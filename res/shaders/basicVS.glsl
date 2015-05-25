#version 330 core

layout (location = 0) in vec3 position;

uniform mat4 projection;
uniform mat4 transformation;

void main()
{

	gl_Position = projection * transformation * vec4(position, 1.0);

}
