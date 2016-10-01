#include "DrawableObject.h"
#include "vertex.h"

DrawableObject::DrawableObject(glm::vec2 pos, glm::vec2 size, glm::vec2 collisionSize, double depth){
	pos_ = pos;
	size_ = size;
	colliSize_ = collisionSize;
	depth_ = depth;
}

DrawableObject::~DrawableObject(){

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
void DrawableObject::setColliSize(glm::vec2 it) {
	colliSize_ = it;
}
void DrawableObject::setSize(glm::vec2 it) {
	size_ = it;
}
void DrawableObject::setPosition(glm::vec2 it) {
	pos_ = it;
}
