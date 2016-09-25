#pragma once
#include <set>
#include "Observer.h"
class Observer;
class Subject
{
public:
	Subject();
	~Subject();
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	virtual bool isMainGame() = 0;
	virtual bool isPlayer() = 0;
	//TODO: add a isCharacter, but then we have to implement dynamic character type, will do in the future.
protected:
	void notifyAll(Subject* subject, std::string eventName);  // needs to be changed to be more sophsicated
	void unregisterAll();
	std::set<Observer*> observers_;
};

