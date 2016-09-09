#include "Circle.h"
/**
	File: Circle.cpp
	Description: Implementation of Circle's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

//constructor
Circle::Circle() {
	type_ = 1;
}

//getter
double Circle::getRadius() {
	return radius_;
}

//setter
void Circle::setRadius(double newRadius) {
	radius_ = newRadius;
	lowerLeft_.x = loc_.x - radius_;
	lowerLeft_.y = loc_.y - radius_;
	upperRight_.x = loc_.x + radius_;
	upperRight_.y = loc_.y + radius_;
}
