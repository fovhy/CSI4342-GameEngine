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
std::ostream& operator<<(std::ostream& os, const MovableObject& MO) {
	return os << MO.pos_.x << ' ' << MO.pos_.y << ' ' << MO.size_.x <<
		' ' << MO.size_.y << ' ' << MO.colliSize_.x << ' ' <<
		MO.colliSize_.y << ' ' << MO.depth_ << ' ';
}
