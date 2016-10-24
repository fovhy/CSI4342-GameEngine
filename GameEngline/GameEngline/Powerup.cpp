#include "Powerup.h"

PowerupType Powerup::getType()
{
	return type_;
}

void Powerup::spawn(const glm::vec2& it)
{
	srand(time(0));
	type_ = PowerupType(rand() % 6);
	setPosition(it);
}