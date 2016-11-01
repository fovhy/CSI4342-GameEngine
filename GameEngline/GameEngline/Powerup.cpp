#include "Powerup.h"

Powerup::Powerup()
{
	position.z = WIDTH;
	position.w = HEIGHT;
}

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

glm::vec4 Powerup::getPos()
{
	return position;
}
