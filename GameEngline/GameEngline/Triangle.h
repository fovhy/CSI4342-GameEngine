#pragma once
#include "Thing.h"

/**
	File: Triangle.h
	Description: The setup for all triangular objects
	Date Created: 9/9/16
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

class Triangle : public Thing {
private:
	Coordinate coord1_, coord2_, coord3_;
public:
	Coordinate getCoord1();
	Coordinate getCoord2();
	Coordinate getCoord3();

	void setCoord1(Coordinate);
	void setCoord2(Coordinate);
	void setCoord3(Coordinate);
	
	void draw(SDL_Renderer* renderer);
};