#pragma once
#include "DrawableObject.h"
class UnmovableObject :
	public DrawableObject
{
public:
	virtual std::vector<quadrant> getQuadrant() override;
	UnmovableObject();
	~UnmovableObject();
};

