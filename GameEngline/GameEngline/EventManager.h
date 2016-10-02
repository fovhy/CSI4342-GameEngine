/*
A singleton class that stores all the possible events here
*/
#pragma once
#include "Event.h"
#include <unordered_map>
class EventManager
{
public:
	static EventManager& getEventManager();
	void init();
	void addEvent(std::string);
	void removeEvent(std::string);

	bool setEventTrue(std::string);
	bool setEventFalse(std::string);
	bool eventExist(std::string);
	bool isEventTrue(std::string);

	Event getEvent(std::string);
	~EventManager();
private:
	EventManager() {}; // disable given constructor 
	EventManager(EventManager const&) = delete;
	void operator=(EventManager const&) = delete;
	bool init_;
	std::unordered_map<std::string, Event> events_;

};

