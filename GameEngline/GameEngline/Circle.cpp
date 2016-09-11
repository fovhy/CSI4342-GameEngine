#include "Circle.h"
/**
	File: Circle.cpp
	Description: Implementation of Circle's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

Circle::Circle() {
	type_ = 1;
}

double Circle::getRadius() {
	return radius_;
}

void Circle::setRadius(double newRadius) {
	radius_ = newRadius;
	lowerLeft_.x = loc_.x - radius_;
	lowerLeft_.y = loc_.y - radius_;
	upperRight_.x = loc_.x + radius_;
	upperRight_.y = loc_.y + radius_;
}

void Circle::draw() {
	return;
}

SDL_Rect Circle::getSDLRect() {
	SDL_Rect rec;
	rec.h = rec.w = radius_ * 2;
	rec.x = loc_.x;
	rec.y = loc_.y;
	return rec;
}