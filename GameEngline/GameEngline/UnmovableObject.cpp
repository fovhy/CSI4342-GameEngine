#include "UnmovableObject.h"



UnmovableObject::UnmovableObject()
{
}


UnmovableObject::~UnmovableObject()
{
}

std::vector<quadrant> UnmovableObject::getQuadrant(){
	return quadrants_;
}

std::ostream& operator<<(std::ostream& os, const UnmovableObject& UO) {
	return os << UO.pos_.x << ' ' << UO.pos_.y << ' ' << UO.size_.x <<
		' ' << UO.size_.y << ' ' << UO.colliSize_.x << ' ' <<
		UO.colliSize_.y << ' ' << UO.depth_ << ' ';
}
