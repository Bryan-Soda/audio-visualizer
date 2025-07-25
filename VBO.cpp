#include "VBO.h"

VBO::VBO(std::vector<Vertex>& vertices) {
	glGenBuffers(1, &ID);
	// Binds the VBO
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	//intros the vertices made earlier
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);
}

void VBO::Bind() {
	// Binds the VBO
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind() {
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Delete() {
	glDeleteBuffers(1, &ID);
}