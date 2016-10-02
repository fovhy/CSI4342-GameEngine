#pragma once
#include "DrawableObject.h"
class MovableObject :public DrawableObject{
public:
	MovableObject();
	~MovableObject();
	double getSpeedX();
	double getSpeedY();
	void setSpeedX(const double);
	void setSpeedY(const double);
	virtual std::vector<quadrant> getQuadrant() override;
private:
	double Vx_ = 0; //speed in x direction
	double Vy_ = 0; //speed in y direction 
};

