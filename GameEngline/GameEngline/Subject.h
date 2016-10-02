#pragma once
#include <set>
#include "Observer.h"
class Observer;
enum class type {
	CHARACTER,
	MAINGAME,
	PLAYER
};

class Subject
{
public:
	Subject();
	~Subject();
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
	type getType() const { return thisType_; }
	//TODO: add a isCharacter, but then we have to implement dynamic character type, will do in the future.
protected:
	void notifyAll(const Subject& subject, std::string eventName);  // needs to be changed to be more sophsicated
	void unregisterAll();
	std::set<Observer*> observers_;
	type thisType_;
};

