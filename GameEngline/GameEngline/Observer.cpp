#include "Observer.h"

Observer::~Observer(){
	for (auto& itr : watchList_) {
		itr->removeObserver(this);
	}
}

void Observer::releaseDuty(Subject* subject) {
	watchList_.erase(subject);
}
