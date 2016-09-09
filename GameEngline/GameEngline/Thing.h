#pragma once 
#include <SDL/SDL.h>
/**
	File: Thing.h
	Description: The abstract base class for all drawable objects in the game.
	Date Created: 8/30/16
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan 
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
	Coordinate getLoc();

	//set location with points
	void setCoord(double x, double y);

	//set location with a Coordinate
	void setCoord(Coordinate newLoc);

	//can the thing move?
	bool canMove();

	//get velocities
	double getXVeloc();
	double getYVeloc();

	//get acceleration
	double getXAccel();
	double getYAccel();

	//get type
	int getType();

	//set velocities
	void setXVeloc(double newXVeloc);
	void setYVeloc(double newYVeloc);

	//set acceleration
	void setXAccel(double newXAccel);
	void setYAccel(double newYAccel);

	//get hitbox
	Coordinate getLowerLeft();
	Coordinate getUpperRight();
};
