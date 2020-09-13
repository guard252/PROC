#version 440 core

layout(location = 0) in vec4 coord;

void main()
{
	gl_Position = coord;
}