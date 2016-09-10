#pragma once
#include "inputManager.h"

void InputManager::pressKey(unsigned int keyID) {
	keyMap_[keyID] = true;
}

void InputManager::releaseKey(unsigned int keyID) {
	keyMap_[keyID] = false;
}


void InputManager::pressButton(unsigned int buttonID) {
	buttonMap_[buttonID] = true;
}
void InputManager::releaseButton(unsigned int buttonID) {
	buttonMap_[buttonID] = false;
}


void InputManager::setAxis_X(unsigned int axisID, int axisTilt) {
	axisMap_X_[axisID] = axisTilt;
}
void InputManager::setAxis_Y(unsigned int axisID, int axisTilt) {
	axisMap_Y_[axisID] = axisTilt;
}


bool InputManager::isKeyPressed(unsigned int keyID) {
	auto it = keyMap_.find(keyID);
	if (it != keyMap_.end()) {
		return it->second;
	}
	else
		return false;
}
bool InputManager::isButtonPressed(unsigned int buttonID) {
	auto it = buttonMap_.find(buttonID);
	if (it != buttonMap_.end()) {
		return it->second;
	}
	else
		return false;
}


int InputManager::getAxisTilt_X(unsigned int axisID) {
	auto it = axisMap_X_.find(axisID);
	if (it != axisMap_X_.end()) {
		return it->second;
	}
	else
		return false;
}
int InputManager::getAxisTilt_Y(unsigned int axisID) {
	auto it = axisMap_Y_.find(axisID);
	if (it != axisMap_Y_.end()) {
		return it->second;
	}
	else
		return false;
}
