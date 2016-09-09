#include "Rectangle.h"
/**
	File: Rectangle.cpp
	Description: Implementation of Rectangle's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

Rectangle::Rectangle() {
	type_ = 0;
}


double Rectangle::getWidth() {
	return width_;
}
double Rectangle::getLength() {
	return length_;
}

void Rectangle::setLength(double newLength) {
	length_ = newLength;
	lowerLeft_.x = loc_.x - (length_ / 2);
	upperRight_.x = loc_.x + (length_ / 2);
}
void Rectangle::setWidth(double newWidth) {
	width_ = newWidth;
	lowerLeft_.y = loc_.y - (width_ / 2);
	upperRight_.y = loc_.y + (width_ / 2);
}

void Rectangle::draw() {
	return;
}