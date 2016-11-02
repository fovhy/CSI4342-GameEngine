#pragma once
#include "DrawableObject.h"
#include "ResourceManager.h"
#include <cstdlib>
#include <ctime>
/*
	Author: Logan
	Date Created: 10/24/2016
	Description: Class to add powerups for the players to collect
*/

const int HEIGHT = 50;
const int WIDTH = 50;

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
	glm::vec4 position;
	ResourceManager powerUpManager_;
public:
	Powerup();
	PowerupType getType();
	void spawn(const glm::vec4& it);
	glm::vec4 getPos();
	void drawSU(SpriteBatch&);
	void drawSD(SpriteBatch&);
	void drawFU(SpriteBatch&);
	void drawFD(SpriteBatch&);
	void drawJU(SpriteBatch&);
	void drawJD(SpriteBatch&);

	GLTexture FU;
	GLTexture FD;
	GLTexture JU;
	GLTexture JD;
	GLTexture SU;
	GLTexture SD;
	
};