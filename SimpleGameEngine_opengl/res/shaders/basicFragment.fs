#version 330

in vec2 texCoord0;
out vec4 fragColor;

uniform vec3 color;
uniform sampler2D sampler;

void main()
{
    vec4 texColor = texture(sampler, texCoord0.xy);
    if (texColor == vec4(0,0,0,1)) 
        fragColor = vec4(color, 1);
    else
        fragColor = texture(sampler, texCoord0.xy) * vec4(color, 1.0);
}