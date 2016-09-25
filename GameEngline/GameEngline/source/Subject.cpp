#include "Subject.h"
#include <algorithm>
#include "EventManager.h"
#include "Error.h"
Subject::Subject(){
}

Subject::~Subject(){
	unregisterAll();
}
void Subject::addObserver(Observer* observer) {
	observers_.insert(observer);
}
void Subject::removeObserver(Observer* observer) {
	observers_.erase(observer);
}
void Subject::notifyAll(Subject* subject, std::string eventName) {
	if (EventManager::getEventManager().eventExist(eventName) == false)
		printError("No such event as " + eventName);

	for (const auto& itr : observers_) {
		itr->onNotify(subject, EventManager::getEvent(eventName));
	}
}
void Subject::unregisterAll() {
	for (const auto& itr : observers_) {
		itr->releaseDuty(this);
	}
}