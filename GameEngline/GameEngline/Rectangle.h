#pragma once
#include "Thing.h"
/**
	File: Rectangle.h
	Description: The setup for all rectangular objects
	Date Created: 8/31/16
	Creator: Logan
	Last Modified: 9/10/16
	Modified By: Dean
*/

class Rectangle : public Thing{
private:
	double height_, width_;

public:
	//constructor
	Rectangle();

	SDL_Rect getSDLRect();


	//getters
	double getWidth();
	double getHeight();

	//setters
	void setHeight(double newHeight);
	void setWidth(double newWidth);

	void draw(SDL_Renderer* renderer);
};