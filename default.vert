#version 330 core
//Coordinates 
layout(location = 0) in vec3 aPos;
//Normal vector
layout(location = 1) in vec3 aNorm;

layout(location = 2) in vec3 aColor;
//Textures
layout(location = 3) in vec2 aTex;

out vec3 crntPos;
out vec3 Normal;

out vec3 color;

out vec2 texCoord;

uniform mat4 camMatrix;
uniform mat4 model;

void main(){
	crntPos = vec3(model* vec4(aPos, 1.0f));
	Normal = aNorm;
	color = aColor;
	texCoord = aTex;
	gl_Position = camMatrix * vec4(crntPos, 1.0);
};