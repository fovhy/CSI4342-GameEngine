#pragma once 
#include "Thing.h"
/**
	File: Circle.h
	Description: Basic setup for all circular objects
	Date Created: 8/31/16
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

class Circle : public Thing{
private:
	double radius_;

	SDL_Rect getSDLRect();

public:
	//constructor
	Circle();

	//getter
	double getRadius();

	//setter
	void setRadius(double newRadius);

	void draw();

};