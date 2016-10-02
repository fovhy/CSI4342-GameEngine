#include "MovableObject.h"



MovableObject::MovableObject()
{
}


MovableObject::~MovableObject()
{
}
double MovableObject::getSpeedX() {
	return Vx_;
}
double MovableObject::getSpeedY() {
	return Vy_;
}
void MovableObject::setSpeedX(const double it) {
	Vx_ = it;
}
void MovableObject::setSpeedY(const double it) {
	Vy_ = it;
} 

std::vector<quadrant> MovableObject::getQuadrant() {
	calculateQuadrants();
	return quadrants_;
}
