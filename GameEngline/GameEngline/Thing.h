#pragma once 
#include <SDL/SDL.h>
/**
	File: Thing.h
	Description: The abstract base class for all drawable objects in the game.
	Date Created: 8/30/16
	Creator: Logan
	Last Modified: 9/8/16
	Modified By: Dean He  
*/

class Thing {
protected:
	struct Coordinate {
		double x;
		double y;
	};

	//location
	Coordinate loc_;

	//x and y velocities
	double xVelocity_, yVelocity_;


	//acceleration
	double xAcceleration_, yAcceleration_;

	//can it move?
	bool moveable_;

	//can it break?
	//bool breakable

	//type of object; each object sets their own type in the constructor
	int type_;

	//hitbox; each object sets their own
	Coordinate lowerLeft_, upperRight_;

	SDL_Texture* texture_; // store texture



public:
	virtual ~Thing() {} 

	virtual void draw() = 0;
	//get location
	Coordinate getLoc() {
		return loc_;
	}

	//set location with points
	void setCoord(double x, double y) {
		loc_.x = x;
		loc_.y = y;
	}

	//set location with a Coordinate
	void setCoord(Coordinate newLoc) {
		loc_ = newLoc;
	}

	//can the thing move?
	bool canMove() {
		return moveable_;
	}

	//get velocities
	double getXVeloc() {
		return xVelocity_;
	}
	double getYVeloc() {
		return yVelocity_;
	}

	//get acceleration
	double getXAccel() {
		return xAcceleration_;
	}
	double getYAccel() {
		return yAcceleration_;
	}

	//get type
	int getType() {
		return type_;
	}

	//set velocities
	void setXVeloc(double newXVeloc) {
		xVelocity_ = newXVeloc;
	}
	void setYVeloc(double newYVeloc) {
		yVelocity_ = newYVeloc;
	}

	//set acceleration
	void setXAccel(double newXAccel) {
		xAcceleration_ = newXAccel;
	}
	void setYAccel(double newYAccel) {
		yAcceleration_ = newYAccel;
	}
};
