#include "Thing.h"
/**
	File: Thing.cpp
	Description: The implementation of Thing's functions
	Date Created: 9/9/16
	Creator: Logan
	Last Modified: 9/10/16
	Modified By: Logan
*/

Thing::~Thing()
{
	if (texture_ != NULL) {
		SDL_DestroyTexture(texture_);
	}
}


void Thing::setCoord(double x, double y) {
	loc_.x = x;
	loc_.y = y;
}
void Thing::setCoord(Coordinate newLoc) {
	loc_ = newLoc;
}
Thing::Coordinate Thing::getLoc() {
	return loc_;
}


bool Thing::canMove() {
	return moveable_;
}


double Thing::getXVeloc() {
	return xVelocity_;
}
double Thing::getYVeloc() {
	return yVelocity_;
}


double Thing::getXAccel() {
	return xAcceleration_;
}
double Thing::getYAccel() {
	return yAcceleration_;
}


int Thing::getType() {
	return type_;
}


void Thing::setXVeloc(double newXVeloc) {
	xVelocity_ = newXVeloc;
}
void Thing::setYVeloc(double newYVeloc) {
	yVelocity_ = newYVeloc;
}


void Thing::setXAccel(double newXAccel) {
	xAcceleration_ = newXAccel;
}
void Thing::setYAccel(double newYAccel) {
	yAcceleration_ = newYAccel;
}


Thing::Coordinate Thing::getLowerLeft() {
	return lowerLeft_;
}
Thing::Coordinate Thing::getUpperRight() {
	return upperRight_;
}

void Thing::loadTexture(std::string texturePath, SDL_Renderer* renderer) {
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(texturePath.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", texturePath.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		texture_ = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (texture_ == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", texturePath.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}
}