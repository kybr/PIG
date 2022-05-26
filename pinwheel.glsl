const int row = 1;
const int column = 2;
const vec2 bias = vec2(0.3, 0.6);

// uniform vec4 color;  
// uniform vec2 scale;  
// uniform vec2 centre;  
uniform float time;  
varying vec2 tcoord;  

void main(void) {  
  vec2 center = vec2(1920.0 / 2.0 + 100.0, 1080.0 / 2.0 + 300.0);
  vec2 vec = center - gl_FragCoord.xy;
  float radius = length(vec);
  float angle = degrees(atan(vec.x, vec.y));

  if (false) {
    gl_FragColor = vec4(sin(radius * 0.03) * cos(angle * 0.14 + time));
    return;
  }

  vec2 period = vec2(90.0, 300.0);
  vec2 phase = vec2(time * 10.0, 0.0);
  vec2 width = vec2(0.5, 0.5); // normalized
  float a = step(width.x, mod(phase.x + angle, period.x) / period.x);
  float b = step(width.y, mod(phase.y + radius, period.y) / period.y);
  gl_FragColor = vec4(a * b + (1.0 - b) * (1.0 - a)); // xor!
}
