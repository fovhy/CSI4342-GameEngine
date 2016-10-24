#pragma once
#include "DrawableObject.h"
#include <cstdlib>
#include <ctime>
/*
	Author: Logan
	Date Created: 10/24/2016
	Description: Class to add powerups for the players to collect
*/
enum PowerupType {
	SPEED_UP,
	SPEED_DOWN,
	FRICTION_UP,
	FRICTION_DOWN,
	JUMP_UP,
	JUMP_DOWN
};

class Powerup : public DrawableObject{
private:
	PowerupType type_;
public:
	PowerupType getType();
	void spawn(const glm::vec2& it);

};