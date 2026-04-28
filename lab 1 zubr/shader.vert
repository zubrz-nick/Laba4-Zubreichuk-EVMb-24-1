#version 410 core
layout (location = 0) in vec3 vp;
uniform float offsetX;

void main()
{
    vec3 pos = vp;
    pos.x += offsetX;          
    gl_Position = vec4(pos, 1.0);
}