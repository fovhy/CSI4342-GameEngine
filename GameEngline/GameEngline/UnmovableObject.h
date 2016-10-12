#pragma once
#include "DrawableObject.h"
class UnmovableObject :
	public DrawableObject
{
public:
	friend class boost::serialization::access;
	friend inline std::ostream& operator<<(std::ostream& os, const UnmovableObject& DO);
	virtual std::vector<quadrant> getQuadrant() override;
	template <class Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar & boost::serialization::base_object<DrawableObject>(*this);
	}
	UnmovableObject();
	~UnmovableObject();
};

