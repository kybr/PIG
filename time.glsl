const int row = 1;
const int column = 2;
const vec2 bias = vec2(0.3, 0.6);

// uniform vec4 color;  
// uniform vec2 scale;  
// uniform vec2 centre;  
uniform float time;  
varying vec2 tcoord;  

void main(void) {  
  vec2 center = vec2(1920.0 / 2.0, 1080.0 / 2.0);
  float foo = distance(gl_FragCoord.xy, center);
  gl_FragColor = vec4(mod(7.0 * time, 100.0) / foo);
  //gl_FragColor = vec4(sin(time*3.0) / 2.0 + 0.5, foo, foo, 1.0);
}

