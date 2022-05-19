#include <lo/lo.h>
#include <lo/lo_cpp.h>
#include <stdio.h>  // getchar()

#include "App.hpp"
#include "GLES2/gl2.h"  // OpenGL!

struct LiveShader : App {
  float r = 0;
  void setup() {
    add_method("/r", "f", [this](lo_arg **argv, int) {
      r = argv[0]->f;
      //
    });

    add_method("/g", "ib", [this](lo_arg **argv, int) {
      int version = argv[0]->i;
      int size = argv[1]->blob.size;
      // const char *blob = &argv[1]->blob.data;
      printf("glsl blob %d bytes (version %d)\n", size, version);
      // memcpy(FRAGMENT, blob, size);
      // FRAGMENT[size] = '\0';
      // printf("====== fragment ========================\n%s\n", FRAGMENT);
      fflush(stdout);
      // recompile = 1;
    });

    add_method("/q", "", [this](lo_arg **argv, int) {
      end();
      //
    });
  }

  float b = 0;
  void draw() {
    glClearColor(r, 1.0, b, 1.0);
    b += 0.01;
    if (b >= 1) b -= 1;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glFlush();
    glFinish();
    flip();
  }
};

int main() {
  LiveShader().run();
  return 0;
}
