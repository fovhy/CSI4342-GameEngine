#include "Character.h"

/*
	File: Character.cpp
	Description: Implementation of Character's functions
	File Created:
	Creator:
	Last Modified: 9/10/16
	Modified By: Logan
*/

Character::Character()
{
}
Character::~Character()
{
}


void Character::draw(SDL_Renderer* renderer) {
	//Thing* toDraw;
	for (int i = 0; i < comp_.size(); i++) {
		comp_[i]->draw(renderer);
	}
}

void Character::makeDefault(SDL_Renderer* renderer) {
	Thing* item = new Rectangle();
	((Rectangle*)(item))->setHeight(30);
	((Rectangle*)(item))->setWidth(30);
	comp_.push_back(item);
	comp_[0]->loadTexture("textures/texture_rocks.jpg", renderer);
	comp_[0]->setCoord(100, 100);
}