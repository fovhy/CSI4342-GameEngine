/*
A singleton set that stores all the possible events here
*/
#pragma once
#include "Event.h"
#include <unordered_map>
class EventManager
{
public:
	static EventManager& getEventManager();
	static void init();
	static void addEvent(std::string);
	static void removeEvent(std::string);

	static bool setEventTrue(std::string);
	static bool setEventFalse(std::string);
	static bool eventExist(std::string);
	static bool isEventTrue(std::string);

	static Event getEvent(std::string);
	~EventManager();
private:
	EventManager() {}; // disable given constructor 
	EventManager(EventManager const&) = delete;
	void operator=(EventManager const&) = delete;
	static bool init_;
	static std::unordered_map<std::string, Event> events_;

};

