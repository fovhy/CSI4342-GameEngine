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
}