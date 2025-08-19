#version 330 core

uniform vec3 baseColor;
uniform vec3 entityColor;

in vec3 outColor;
in vec3 FragPos;
in vec2 TexCoords;

out vec4 FragColor;

void main()
{    
    vec3 result = outColor;

    //result *= baseColor; //Color de la textura
    //result *= entityColor;

    //Result
    FragColor = vec4(result, 1.0);
}
