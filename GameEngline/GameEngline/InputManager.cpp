#pragma once
#include "inputManager.h"

void InputManager::pressKey(unsigned int keyID) {
	keyMap_[keyID] = true;
}

void InputManager::releaseKey(unsigned int keyID) {
	keyMap_[keyID] = false;
}

bool InputManager::isKeyPressed(unsigned int keyID) {
	auto it = keyMap_.find(keyID);
	if (it != keyMap_.end()) {
		return it->second;
	}
	else
		return false;
}