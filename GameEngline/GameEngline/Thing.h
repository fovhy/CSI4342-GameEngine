#ifndef THING_H
#define THING_H
/**
	File: Thing.h
	Description: The base class for all objects in the game.
	Date Created: 8/30/16
	Creator: Logan
	Last Modified: 8/31/16
	Modified By: Logan
*/

struct Coordinate {
	double x;
	double y;
	//int z;
};

class Thing {
protected:

	//location
	Coordinate loc_;

	//x and y velocities
	double xVelocity_, yVelocity_;

	//z velocity
	//int zVelocity;

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

public:
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



#endif