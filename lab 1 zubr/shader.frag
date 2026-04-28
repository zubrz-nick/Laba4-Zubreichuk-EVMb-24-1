#version 410 core
out vec4 frag_color;
uniform vec4 ourColor;
void main()
{
    frag_color = ourColor;
}