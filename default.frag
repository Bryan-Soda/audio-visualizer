#version 330 core

out vec4 FragColor;

in vec3 color;

in vec2 texCoord;

in vec3 Normal;
in vec3 crntPos;

//These are mainly for fancy type of lighting (may not use)
uniform sampler2D diffuse0;
uniform sampler2D specular0;

uniform vec4 lightColor;
uniform vec3 lightPos;

void main(){
	vec3 normal = normalize(Normal);
	vec3 lightDirection = normalize(lightPos - crntPos);

	float diffuse = max(dot(normal, lightDirection), 0.0f);

	//FragColor = texture(tex0, texCoord) * lightColor * diffuse;

	vec3 texColor = texture(diffuse0, texCoord).rgb;
	FragColor = vec4(texColor * (0.1 + 0.9 * diffuse) * lightColor.rgb, 1.0); 

};