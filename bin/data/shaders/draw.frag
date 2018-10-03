#version 330

#define COLOR_MIN 0.2
#define COLOR_MAX 0.35

uniform vec2 iResolution;
uniform sampler2DRect tex0;

in vec2 vTexCoord;

out vec4 fragColor;

float getGradient(vec2 uv)
{
  return (COLOR_MAX - texture(tex0, uv).y) /
         (COLOR_MAX - COLOR_MIN);
}

void main()
{
	vec2 uv = gl_FragCoord.xy / iResolution.xy;
	float v = getGradient(vTexCoord);
    
    fragColor = vec4(v, v, v, 1.0);
}