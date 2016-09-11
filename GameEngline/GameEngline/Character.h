#pragma once
#include <vector>
#include "Thing.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

/*
Character is the astract base class for both PC and NPC. It contains several meothods that all
characters should have.

Author: Dean He 
Create Date: 9/8/2016

Last Modified: 9/9/16
Modified By: Logan
*/
class Character
{
private:
	std::vector<Thing*> comp_;
public:
	Character();
	~Character();
	void draw(SDL_Renderer* renderer);
	void makeDefault(SDL_Renderer* renderer);
};

