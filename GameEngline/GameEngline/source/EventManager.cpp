#include "EventManager.h"
EventManager& EventManager::getEventManager() {
	static EventManager manager;
	return manager;
}

void EventManager::init() {
	if (init_ == false) {
		//TODO: add events here
		init_ = true;
	}
}
void EventManager::addEvent(std::string eventName) {
	events_.emplace(eventName, Event(eventName));
}
void EventManager::removeEvent(std::string eventName) {
	events_.erase(eventName);
}
bool EventManager::setEventTrue(std::string eventName) {
	auto itr = events_.find(eventName);
	if (itr == events_.end()) {
		return false;
	}
	else {
		itr->second.happened = true;
		return true;
	}
}
bool EventManager::setEventFalse(std::string eventName) {
	auto itr = events_.find(eventName);
	if (itr == events_.end()) {
		return false;
	}
	else {
		itr->second.happened = false;
		return true;
	}
}
bool EventManager::eventExist(std::string eventName) {
	auto itr = events_.find(eventName);
	if (itr == events_.end()) 
		return false;
	else
		return true;
}

bool EventManager::isEventTrue(std::string eventName) {
	auto itr = events_.find(eventName);
	if (itr == events_.end()) {
		return false;
	}
	else {
		return itr->second.happened;
	}
}

Event EventManager::getEvent(std::string eventName) {
	auto itr = events_.find(eventName);
	if (itr == events_.end()) {
		return nullptr;
	}
	else {
		return itr->second;
	}
}
EventManager::~EventManager() {
}
