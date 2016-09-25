/*
a singleton class that stores all the events can be usede by a observer pattern
*/
#pragma once
#include <unordered_map>
#include <string>
class Event
{
public:
	Event(std::string eventName) { this->eventName = eventName; }
	~Event() {};
	std::string eventName;
	bool happened = false;
};

