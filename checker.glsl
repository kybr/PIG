const int row = 1;
const int column = 2;
const vec2 bias = vec2(0.3, 0.6);

uniform vec4 color;  
uniform vec2 scale;  
uniform vec2 centre;  
varying vec2 tcoord;  

void main(void) {  
  // values in pixels
  vec2 period = vec2(192.0, 108.0);
  vec2 phase = vec2(0.0, 0.0);
  vec2 width = vec2(0.5, 0.5); // normalized
  float a = step(width.x, mod(phase.x + gl_FragCoord.x, period.x) / period.x);
  float b = step(width.y, mod(phase.y + gl_FragCoord.y, period.y) / period.y);
  gl_FragColor = vec4(a * b + (1.0 - b) * (1.0 - a)); // xor!

  /*
  float period = 192.0;
  float phase = 256.0;
  float width = 0.5;
  gl_FragColor = vec4(step(width, mod(phase + gl_FragCoord.x, period) / period));
  */

  /*
  if (gl_FragCoord.x > 1920.0 / 2.0)
    gl_FragColor = vec4(0.0, 0.0, 1.0, gl_FragCoord.y / 1080.0);
  else
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0 - gl_FragCoord.y / 1080.0);
    */

  //int c = int(mod(gl_FragCoord.x, 2.0));
  //int r = int(mod(gl_FragCoord.y, 2.0));
  //gl_FragColor = vec4(c/10.0, r/10.0, 1.0, 1.0);
  //gl_FragColor = vec4(mod(gl_FragCoord.x, 10.0));

  /*
  float v = 170.0;
  gl_FragColor = vec4(mod(gl_FragCoord.x, v) / v);
  */
  /*
  float v = 0.13;
  gl_FragColor = vec4(mod(gl_FragCoord.x / 1920.0, v) / v);
  */

  /*
  if (tcoord.y > 0.5)
    gl_FragColor = vec4(0.0, 1.0, 0.0, 1.0);
  else
    gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);
    */

  //gl_FragColor = vec4(gl_FragColor.x > 0 ? 1.0 : 0.5);
  //gl_FragColor = vec4(1.0);
  //gl_FragColor = vec4(0.0);
}

