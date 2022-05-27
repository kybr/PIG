uniform sampler2D texture;
uniform float time;  
uniform ivec2 position;  
uniform ivec2 size;  
uniform ivec2 bias;  
varying vec2 texture_coordinate;

void main(void) {  
  vec2 center = vec2(size.x / 2 + 100, size.y / 2 + 300);
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
  vec4 previous = texture2D(texture, texture_coordinate);
  vec4 pinwheel = vec4(a * b + (1.0 - b) * (1.0 - a)); // xor!
  gl_FragColor = mix(pinwheel, previous, 0.);
}
