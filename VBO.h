#ifndef VBO_CLASS_H
#define VBO_CLASS_H

	//[!] Include glm into source code
//#include<glm/glm.hpp>
#include <glad/glad.h>
#include<vector>

struct Vertex {
	//requires glm to work :p
};

class VBO {
public:
	GLuint ID;
	VBO(std::vector<Vertex>& vertices);
	void Bind();
	void Unbind();
	void Delete();
};


#endif