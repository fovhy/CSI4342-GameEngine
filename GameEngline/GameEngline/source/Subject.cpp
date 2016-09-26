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
	observer->addSubject(this);
	observers_.insert(observer);
}
void Subject::removeObserver(Observer* observer) {
	observers_.erase(observer);
}
void Subject::notifyAll(const Subject& subject, std::string eventName) {
	if (EventManager::getEventManager().eventExist(eventName) == false)
		printError("No such event as " + eventName);

	for (const auto& itr : observers_) {
		itr->onNotify(subject, EventManager::getEventManager().getEvent(eventName));
	}
}
void Subject::unregisterAll() {
	if (observers_.size() > 0) {
		for (const auto& itr : observers_) {
			itr->releaseDuty(this);
		}
	}
}