#include "VAO.h"

VAO::VAO() {
	glGenVertexArrays(1, &ID);
}

void VAO::LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset) {
	VBO.Bind();
	//Config Vertex Attribs to OpenGL knows how to read VBO
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	// Enable the Vertex Attribs so that OpenGL knows to use it
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind() {
	//Actively binds the VAO ID 
	glBindVertexArray(ID);
}

void VAO::Unbind() {
	//Actively unbinds the VAO ID 
	glBindVertexArray(0);
}

void VAO::Delete() {
	glDeleteVertexArrays(1, &ID);
}