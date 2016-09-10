#pragma once
#include "Thing.h"
/**
	File: Rectangle.h
	Description: The setup for all rectangular objects
	Date Created: 8/31/16
	Creator: Logan
	Last Modified: 8/31/16
	Modified By: Logan
*/

class Rectangle : public Thing{
private:
	double length_, width_;

public:
	//constructor
	Rectangle();

	SDL_Rect getSDLRect();


	//getters
	double getWidth();
	double getLength();

	//setters
	void setLength(double newLength);
	void setWidth(double newWidth);

	void draw();
};