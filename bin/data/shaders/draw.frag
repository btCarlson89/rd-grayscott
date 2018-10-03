#version 330

#define COLOR_MIN 0.2
#define COLOR_MAX 0.35

uniform vec2 iResolution;
uniform sampler2D iChannel0;

out vec4 fragColor;

float getGradient(vec2 uv)
{
  return (COLOR_MAX - texture(iChannel0, uv).y) /
         (COLOR_MAX - COLOR_MIN);
}

vec2 getTexel(vec2 uv)
{
    return texture(iChannel0, uv).xy;
}

void main()
{
	vec2 uv = gl_FragCoord.xy / iResolution.xy;
	//float v = getGradient(uv);
	vec2 v = getTexel(uv);
    
    fragColor = vec4(v, 0.0, 1.0);
}