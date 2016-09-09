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
	Rectangle() {
		type_ = 0;
	}


	//getters
	double getWidth() {
		return width_;
	}
	double getLength() {
		return length_;
	}

	//setters
	void setLength(double newLength) {
		length_ = newLength;
		lowerLeft_.x = loc_.x - (length_ / 2);
		upperRight_.x = loc_.x + (length_ / 2);
	}
	void setWidth(double newWidth) {
		width_ = newWidth;
		lowerLeft_.y = loc_.y - (width_ / 2);
		upperRight_.y = loc_.y + (width_ / 2);
	}

};