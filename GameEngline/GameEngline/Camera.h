#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	Camera();
	~Camera();

	void setPosition(const glm::vec2& position) { this->position = position; updateRequried = true; }
	void setScale(float scale) { this->scale = scale; updateRequried = true; }


	glm::vec2 getPosition() { return position; }
	glm::mat4 getCameraMatrix() {
		return cameraMatrix;
	}

	void init(int screenWidth, int screenHeight);
	void update();

	float getScale() {
		return scale;
	}

private:
	int screenWidth;
	int screenHeight;
	float scale;
	bool updateRequried;
	glm::vec2 position;
	glm::mat4 cameraMatrix;
	glm::mat4 orthoMatrix;

};
