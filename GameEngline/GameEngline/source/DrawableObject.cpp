#include "DrawableObject.h"


DrawableObject::DrawableObject(glm::vec2 pos, glm::vec2 size, glm::vec2 collisionSize, std::string fileName){
	pos_ = pos;
	size_ = size;
	colliSize_ = collisionSize;
	textureFileName_ = fileName;
}


DrawableObject::~DrawableObject(){

}
