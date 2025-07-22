#include"Camera.h"

Camera::Camera(int w, int h, glm::vec3 pos) {
	Camera::width = w;
	Camera::height = h;
	Position = pos;
}

void Camera::updateMatrix(float FOVdeg, float nearPlane, float farPlane) {
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	view = glm::lookAt(Position, Position + Orientation, Up);
	projection = glm::perspective(glm::radians(FOVdeg), float(width / height), nearPlane, farPlane);

	camMatrix = projection * view;
}

void Camera::Matrix(Shader& shader, const char* uniform) {
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(camMatrix));
}
//Allows user to control the camera via keyboard or mouse
void Camera::Inputs(GLFWwindow* wind) {
	if (glfwGetKey(wind, GLFW_KEY_W) == GLFW_PRESS) {
		Position += speed * Orientation;
	}
	if (glfwGetKey(wind, GLFW_KEY_A) == GLFW_PRESS) {
		Position += speed * -glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(wind, GLFW_KEY_S) == GLFW_PRESS) {
		Position += speed * -Orientation;
	}
	if (glfwGetKey(wind, GLFW_KEY_D) == GLFW_PRESS) {
		Position += speed * glm::normalize(glm::cross(Orientation, Up));
	}
	if (glfwGetKey(wind, GLFW_KEY_SPACE) == GLFW_PRESS) {
		Position += speed * Up;
	}
	if (glfwGetKey(wind, GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS) {
		Position += speed * -Up;
	}
	if (glfwGetKey(wind, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS) {
		speed = 0.4;
	}
	else if (glfwGetKey(wind, GLFW_KEY_LEFT_SHIFT) == GLFW_RELEASE) {
		speed = 0.1;
	}

	if (glfwGetMouseButton(wind, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS) {
		glfwSetInputMode(wind, GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		if (firstClick) {
			glfwSetCursorPos(wind, (width / 2), (height / 2));
			firstClick = false;
		}
		double mouseX, mouseY;
		glfwGetCursorPos(wind, &mouseX, &mouseY);

		float rotx = sensivitiy * (float)(mouseY - (height / 2)) / height;
		float roty = sensivitiy * (float)(mouseX - (height / 2)) / width;

		glm::vec3 newOrientation = glm::rotate(Orientation, glm::radians(-rotx), glm::normalize(glm::cross(Orientation, Up)));

		if (abs(glm::angle(newOrientation, Up) - glm::radians(90.0f)) <= glm::radians(85.0f)) {
			Orientation = newOrientation;
		}
		Orientation = glm::rotate(Orientation, glm::radians(-roty), Up);

		glfwSetCursorPos(wind, (width / 2), (height / 2));
	}
	else if (glfwGetMouseButton(wind, GLFW_MOUSE_BUTTON_LEFT == GLFW_RELEASE)) {
		glfwSetInputMode(wind, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		firstClick = true;
	}
}//end of Inputs