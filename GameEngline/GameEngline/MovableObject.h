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
	friend class boost::serialization::access;
	friend std::ostream& operator<<(std::ostream& os, const MovableObject& MO);
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar & boost::serialization::base_object<DrawableObject>(*this);
	}
private:
	double Vx_ = 0; //speed in x direction
	double Vy_ = 0; //speed in y direction 
};

