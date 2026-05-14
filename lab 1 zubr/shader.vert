#version 410 core
layout (location = 0) in vec3 aPos;

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;
uniform float offsetX;

out vec4 ourColor;

void main() {
    vec4 pos = projection * view * model * vec4(aPos, 1.0);
    pos.x += offsetX;
    gl_Position = pos;
}