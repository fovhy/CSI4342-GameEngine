#pragma once
#include "Event.h"
#include "Subject.h"
#include <set>
class Subject;
class Observer
{
public:
	Observer();
	virtual void onNotify(const Subject* subject, Event event) = 0;
	virtual ~Observer();
	void releaseDuty(Subject* subject); // remove this subject in the watchList
protected:
	std::set<Subject*> watchList_;
};

