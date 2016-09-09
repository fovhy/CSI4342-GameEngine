#include "Character.h"



Character::Character()
{
}


Character::~Character()
{
}

void Character::draw() {
	for (auto i : comp_) {
		i.draw();
	}
}