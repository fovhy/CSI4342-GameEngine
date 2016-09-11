#include "Triangle.h"

/**
	File: Triangle.cpp
	Description: Implementation of Triangle's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/10/16
	Modified By: Logan
*/

Thing::Coordinate Triangle::getCoord1() {
	return coord1_;
}

Thing::Coordinate Triangle::getCoord2() {
	return coord2_;
}

Thing::Coordinate Triangle::getCoord3() {
	return coord3_;
}


void Triangle::setCoord1(Coordinate newCoord) {
	coord1_ = newCoord;
}

void Triangle::setCoord2(Coordinate newCoord) {
	coord2_ = newCoord;
}

void Triangle::setCoord3(Coordinate newCoord) {
	coord3_ = newCoord;
}

void Triangle::draw(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture_, NULL, &getSDLRect());
	return;
}

SDL_Rect Triangle::getSDLRect() {
	SDL_Rect rec;
	//find lowest and highest x-values
	double xLow, xHigh;
	//find lowest and highest y-values
	double yLow, yHigh;
	xLow = xHigh = coord1_.x;
	yLow = yHigh = coord1_.y;
	if (xLow > coord2_.x) {
		xLow = coord2_.x;
	}
	else if (xHigh > coord2_.x) {
		xHigh = coord2_.x;
	}

	if (xLow > coord3_.x) {
		xLow = coord3_.x;
	}
	else if (xHigh < coord3_.x) {
		xHigh = coord3_.x;
	}
	
	if (yLow > coord2_.y) {
		yLow = coord2_.y;
	}
	else if (yHigh > coord2_.y) {
		yHigh = coord2_.y;
	}

	if (yLow > coord3_.y) {
		yLow = coord3_.y;
	}
	else if (yHigh < coord3_.y) {
		yHigh = coord3_.y;
	}
	rec.h = yHigh - yLow;
	rec.w = xHigh - xLow;
	rec.x = loc_.x;
	rec.y = loc_.y;
	return rec;
}