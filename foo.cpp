#include <lo/lo.h>
#include <lo/lo_cpp.h>

#include <atomic>
#include <chrono>
#include <cstdio>
//#include <cassert>
#include <cstring>

#include "App.hpp"
#include "GL.hpp"

///////////////////////////////////////////////////////////////////////////////
//// OpenGL ///////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

struct OpenGLState {
  GLuint verbose;
  GLuint shader_vertex;
  GLuint shader_fragment;
  GLuint program;
  GLuint tex_fb;
  GLuint tex;
  GLuint buffer_vertex_array;
  GLuint attribute_vertex;
  GLuint uniform_scale;
  GLuint uniform_offset;
  GLuint uniform_center;
  GLuint uniform_time;
};

const GLchar *shader_source_default_vertex = R"(
attribute vec4 vertex;
varying vec2 tcoord;
void main(void) {
  vec4 pos = vertex;
  gl_Position = pos;
  tcoord = vertex.xy*0.5+0.5;
}
)";

  // Mandelbrot
const GLchar *shader_source_default_fragment = R"(
uniform vec2 scale;
uniform vec2 center;
uniform float time;
varying vec2 tcoord;
void main(void) {
  float cr = (gl_FragCoord.x - center.x) * scale.x;
  float ci = (gl_FragCoord.y - center.y) * scale.y;
  float ar = cr;
  float ai = ci;
  float tr, ti;
  float col = 0.0;
  float p = 0.0;
  int i = 0;
  for (int i2 = 1; i2 < 16; i2++) {
    tr = ar * ar - ai * ai + cr;
    ti = 2.0 * ar * ai + ci;
    p = tr * tr + ti * ti;
    ar = tr;
    ai = ti;
    if (p > 16.0) {
      i = i2;
      break;
    }
  }
  gl_FragColor = vec4(float(i) * 0.0625, 0, 0, 1);
}
)";


static void showlog(GLint shader) {
  // Prints the compile log for a shader
  char log[1024];
  glGetShaderInfoLog(shader, sizeof(log), nullptr, log);
  printf("%d:shader:\n%s\n", shader, log);
  fflush(stdout);
}

static void showprogramlog(GLint shader) {
  // Prints the information log for a program object
  char log[1024];
  glGetProgramInfoLog(shader, sizeof(log), nullptr, log);
  printf("%d:program:\n%s\n", shader, log);
  fflush(stdout);
}

static void compile_shader(OpenGLState *state) {

  state->shader_vertex = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(state->shader_vertex, 1, &shader_source_default_vertex, 0);
  glCompileShader(state->shader_vertex);
  check_gl_error();

  if (state->verbose) showlog(state->shader_vertex);

  state->shader_fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(state->shader_fragment, 1, &shader_source_default_fragment, 0);
  glCompileShader(state->shader_fragment);
  check_gl_error();

  if (state->verbose) showlog(state->shader_fragment);

  state->program = glCreateProgram();
  glAttachShader(state->program, state->shader_vertex);
  glAttachShader(state->program, state->shader_fragment);
  glLinkProgram(state->program);
  check_gl_error();

  if (state->verbose) showprogramlog(state->program);

  // to save on GPU memory!!! XXX
  {
    GLint result = 0;
    glGetProgramiv(state->program, GL_LINK_STATUS, &result);
    if (result == GL_TRUE) {
      glDetachShader(state->program, state->shader_vertex);
      glDetachShader(state->program, state->shader_fragment);
    }
  }

  // save GPU memory
  // glDeleteShader(state->shader_vertex);
  glDeleteShader(state->shader_fragment);

  state->attribute_vertex = glGetAttribLocation(state->program, "vertex");
  state->uniform_scale = glGetUniformLocation(state->program, "scale");
  state->uniform_offset = glGetUniformLocation(state->program, "offset");
  state->uniform_center = glGetUniformLocation(state->program, "center");
  check_gl_error();
}

void more_setup(OpenGLState *state, int width, int height) {
  glClearColor(0.0, 1.0, 1.0, 1.0);

  glGenBuffers(1, &state->buffer_vertex_array);

  check_gl_error();

  // Prepare a texture image
  glGenTextures(1, &state->tex);
  check_gl_error();
  glBindTexture(GL_TEXTURE_2D, state->tex);
  check_gl_error();
  // glActiveTexture(0)
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_SHORT_5_6_5, 0);
  check_gl_error();
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  check_gl_error();
  // Prepare a framebuffer for rendering
  glGenFramebuffers(1, &state->tex_fb);
  check_gl_error();
  glBindFramebuffer(GL_FRAMEBUFFER, state->tex_fb);
  check_gl_error();
  glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D,
                         state->tex, 0);
  check_gl_error();
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  check_gl_error();

  // Prepare viewport
  glViewport(0, 0, width, height);
  check_gl_error();

  static const GLfloat vertex_data[] = {-1.0, -1.0, 1.0, 1.0, 1.0, -1.0,
                                        1.0,  1.0,  1.0, 1.0, 1.0, 1.0,
                                        -1.0, 1.0,  1.0, 1.0};

  // Upload vertex data to a buffer
  glBindBuffer(GL_ARRAY_BUFFER, state->buffer_vertex_array);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_data), vertex_data,
               GL_STATIC_DRAW);

  glVertexAttribPointer(state->attribute_vertex, 4, GL_FLOAT, 0, 16, 0);
  glEnableVertexAttribArray(state->attribute_vertex);

  check_gl_error();
}

static void render(OpenGLState *state, double ellapsed) {
  // Now render to the main frame buffer
  glBindFramebuffer(GL_FRAMEBUFFER, 0);

  // Clear the background (not really necessary I suppose)
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  check_gl_error();

  glBindBuffer(GL_ARRAY_BUFFER, state->buffer_vertex_array);  //?
  check_gl_error();

  glUseProgram(state->program);
  check_gl_error();

  // glBindTexture(GL_TEXTURE_2D,state->tex);
  // check_gl_error();
  glUniform2f(state->uniform_scale, 0.003, 0.003);
  glUniform2f(state->uniform_center, 1920 / 2.0, 1080 / 2.0);
  glUniform1f(state->uniform_time, ellapsed);
  // glUniform2f(state->uniform_scale, scale, scale);
  // glUniform2f(state->uniform_center, cx, cy);
  // glUniform4f(state->unif_color, 0.5, 0.5, 0.8, 1.0);
  // glUniform2f(state->unif_scale, scale, scale);
  // glUniform2f(state->unif_offset, x, y);
  // glUniform2f(state->unif_centre, cx, cy);
  // glUniform1i(state->unif_tex, 0); // I don't really understand this
  // part, perhaps it relates to active texture?
  check_gl_error();

  glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
  check_gl_error();

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glUseProgram(0);

  glFlush();
  glFinish();
  check_gl_error();
}

void recompile_shader(OpenGLState *state, const char *FRAGMENT) {
  GLuint fragment = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(fragment, 1, (const GLchar **)&FRAGMENT, 0);
  glCompileShader(fragment);
  check_gl_error();

  if (state->verbose) showlog(fragment);

  GLuint program = glCreateProgram();
  glAttachShader(program, state->shader_vertex);  // vertex already compiled
  glAttachShader(program, fragment);
  glLinkProgram(program);
  check_gl_error();

  if (state->verbose) showprogramlog(program);

  {
    GLint result = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &result);
    if (result != GL_TRUE) {
      glDetachShader(program, state->shader_vertex);
      glDetachShader(program, fragment);
      glDeleteShader(fragment);
      glDeleteProgram(program);
      return;
    }
  }

  // XXX need to automatically figure out these...
  state->attribute_vertex = glGetAttribLocation(program, "vertex");
  state->uniform_scale = glGetUniformLocation(program, "scale");
  state->uniform_offset = glGetUniformLocation(program, "offset");
  state->uniform_center = glGetUniformLocation(program, "center");
  state->uniform_time = glGetUniformLocation(program, "time");
  check_gl_error();

  glDetachShader(program, state->shader_vertex);
  glDetachShader(program, fragment);
  glDeleteShader(fragment);
  glDeleteProgram(state->program);
  state->program = program;
}

//==============================================================================

struct ClassTimer {
  std::chrono::high_resolution_clock::time_point begin;
  ClassTimer() : begin(std::chrono::high_resolution_clock::now()) {}
  double ellapsed() {
    return std::chrono::duration<double>(
               std::chrono::high_resolution_clock::now() - begin)
        .count();
  }
};

struct LiveShader : App, ClassTimer {
  OpenGLState state;
  int cx, cy;
  float b{0};
  float r{0};
  std::atomic<bool> recompile{false};

  char FRAGMENT[65536];

  void setup() {
    add_method("/r", "f", [this](lo_arg **argv, int) {
      r = argv[0]->f;
      //
    });

    add_method("/s", "ib", [this](lo_arg **argv, int) {
      int version = argv[0]->i;
      int size = argv[1]->blob.size;
      printf("glsl blob %d bytes (version %d)\n", size, version);
      const char *blob = &argv[1]->blob.data;
      memcpy(FRAGMENT, blob, size);
      FRAGMENT[size] = '\0';
      printf("====== fragment ========================\n%s\n", FRAGMENT);
      fflush(stdout);
      recompile = true;
    });

    add_method(nullptr, nullptr, [](lo_arg **argv, int) {
      printf("got an OSC message\n");
      fflush(stdout);
    });

    memset(&state, 0, sizeof(OpenGLState));
    state.verbose = 1;

    compile_shader(&state);
    more_setup(&state, width(), height());

    cx = width() / 2;
    cy = height() / 2;
  }

  void draw() {
    // glClearColor(r, 1.0, b, 1.0);
    // b += 0.01;
    // if (b >= 1) b -= 1;
    // glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    // glFlush();
    // glFinish();

    if (recompile) {
      recompile = false;
      recompile_shader(&state, FRAGMENT);
      check_gl_error();
    }

    render(&state, ClassTimer::ellapsed());
    flip();
    check_gl_error();
  }
};

int main() {
  LiveShader().run();
  return 0;
}
