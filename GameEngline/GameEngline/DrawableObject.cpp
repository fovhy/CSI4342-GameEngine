#include "DrawableObject.h"
#include "vertex.h"

int DrawableObject::screenHeight = 800;
int DrawableObject::screenWidth = 1200;
DrawableObject::DrawableObject(const glm::vec2& pos, const glm::vec2& size,
	const glm::vec2 &collisionSize, double depth) {
	setPosition(pos);
	setSize(size);
	setColliSize(collisionSize);
	depth_ = depth;
}

DrawableObject::~DrawableObject() {

}

void DrawableObject::draw(SpriteBatch& spriteBatch, glm::vec4 uv, GLTexture texture) {
	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	spriteBatch.draw(glm::vec4(pos_.x, pos_.y, size_.x, size_.y), uv, texture.id, depth_, solidColor);
}

GLTexture DrawableObject::getTexture() {
	return texture_;
}
glm::vec2 DrawableObject::getPosition() {
	return pos_;
}
glm::vec2 DrawableObject::getSize() {
	return size_;
}
glm::vec2 DrawableObject::getColliSize() {
	return colliSize_;
}
void DrawableObject::setColliSize(const glm::vec2& it) {
	colliSize_ = it;
}
void DrawableObject::setSize(const glm::vec2& it) {
	size_ = it;
}
void DrawableObject::setPosition(const glm::vec2& it) {
	pos_ = it;
	calculateQuadrants();
}

void DrawableObject::calculateQuadrants() {
	if (Physic::checkCollisions(glm::vec4(pos_, colliSize_),  // check collision with first quadrant
		glm::vec4(0, 0, screenWidth / 2, screenHeight / 2))) {
		quadrants_.push_back(quadrant::first);
	}
	if (Physic::checkCollisions(glm::vec4(pos_, colliSize_),  // check collision with second quadrant
		glm::vec4(screenWidth/2, 0, screenWidth , screenHeight / 2))) {
		quadrants_.push_back(quadrant::second);
	}
	if (Physic::checkCollisions(glm::vec4(pos_, colliSize_),  // check collision with thir quadrant
		glm::vec4(0, screenHeight/2, screenWidth / 2, screenHeight))) {
		quadrants_.push_back(quadrant::third);
	}
	if (Physic::checkCollisions(glm::vec4(pos_, colliSize_),  // check collision with fourth quadrant
		glm::vec4(screenWidth/2, screenHeight/2, screenWidth, screenHeight))) {
		quadrants_.push_back(quadrant::fourth);
	}
}

