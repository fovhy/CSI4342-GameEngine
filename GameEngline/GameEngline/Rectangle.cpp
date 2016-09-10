#include "Rectangle.h"
/**
	File: Rectangle.cpp
	Description: Implementation of Rectangle's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/10/16
	Modified By: Dean
*/

Rectangle::Rectangle() {
	type_ = 0;
}


double Rectangle::getWidth() {
	return width_;
}
double Rectangle::getHeight() {
	return height_;
}


void Rectangle::setHeight(double newHeight) {
	height_ = newHeight;
	lowerLeft_.y = loc_.y - (height_ / 2);
	upperRight_.y = loc_.y + (height_ / 2);
}
void Rectangle::setWidth(double newWidth) {
	width_ = newWidth;
	lowerLeft_.x = loc_.x - (width_ / 2);
	upperRight_.x = loc_.x + (width_ / 2);
}


void Rectangle::draw() {
	return;
}

SDL_Rect Rectangle::getSDLRect() {
	SDL_Rect rec;
	rec.h = height_;
	rec.w = width_;
	rec.x = loc_.x;
	rec.y = loc_.y;
	return rec;
}
