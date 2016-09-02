#ifndef CIRCLE_H
#define CIRCLE_H
#include "Thing.h"
/**
	File: Circle.h
	Description: Basic setup for all circular objects
	Date Created: 8/31/16
	Creator: Logan
	Last Modified: 8/31/16
	Modified By: Logan
*/

class Circle : public Thing{
private:
	double radius_;
public:
	//constructor
	Circle() {
		type_ = 1;
	}

	//getter
	double getRadius() {
		return radius_;
	}

	//setter
	void setRadius(double newRadius) {
		radius_ = newRadius;
		lowerLeft_.x = loc_.x - radius_;
		lowerLeft_.y = loc_.y - radius_;
		upperRight_.x = loc_.x + radius_;
		upperRight_.y = loc_.y + radius_;
	}



};

#endif