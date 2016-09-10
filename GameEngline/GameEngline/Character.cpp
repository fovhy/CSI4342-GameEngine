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
		comp_[i].draw(renderer);
	}
}