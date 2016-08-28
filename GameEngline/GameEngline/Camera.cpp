#include "Camera.h"
#include <iostream>

Camera::Camera() : position(0.0f, 0.0f), cameraMatrix(1.0f), orthoMatrix(1.0f), scale(1.0f), updateRequried(false) {

}

Camera::~Camera() {
}

void Camera::init(int screenWidth, int screenHeight) {
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;
	orthoMatrix = glm::ortho(0.0f, float(screenWidth), 0.0f, float(screenHeight));
	glm::vec3 translate(-position.x, -position.y + screenHeight / 2, 0.0f);
	cameraMatrix = glm::translate(orthoMatrix, translate);
}

void Camera::update() {
	if (updateRequried) {
		// translation
		glm::vec3 translate(-position.x, -position.y + screenHeight / 2, 0.0f);
		cameraMatrix = glm::translate(orthoMatrix, translate);
		// scale
		glm::vec3 scaleVec(scale, scale, 0.0f);
		cameraMatrix = glm::scale(glm::mat4(1.0f), scaleVec) * cameraMatrix;
		updateRequried = false;
	}
}