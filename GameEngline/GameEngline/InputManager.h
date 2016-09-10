#pragma once
#include <unordered_map>
#include <vector>
#include "InputListener.h"
/*
The InputManager controls the input of the player. It uses a unordered map to keep track player key up and key down.
It implements an observer pattern with InputListener. 

Author: Dean He
Create Date: 9/8/2016

Last Modified: 9/10/16
Modified By: Logan
*/

//TODO bind it with preface class
class InputManager {
public:
	InputManager() {}
	~InputManager() {}

	void pressKey(unsigned int keyID);
	void releaseKey(unsigned int keyID);

	void pressButton(unsigned int buttonID);
	void releaseButton(unsigned int buttonID);

	void setAxis_X(unsigned int axisID, int axisTilt);
	void setAxis_Y(unsigned int axisID, int axisTilt);

	bool isKeyPressed(unsigned int keyID);
	bool isButtonPressed(unsigned int keyID);
	int getAxisTilt_X(unsigned int axisID);
	int getAxisTilt_Y(unsigned int axisID);

	void notifyAll(); // notify all the InputListener

private:
	bool keyPressed_ = false;
	std::unordered_map<unsigned int, bool> keyMap_;
	std::unordered_map<unsigned int, bool> buttonMap_;
	std::unordered_map<unsigned int, int> axisMap_X_;
	std::unordered_map<unsigned int, int> axisMap_Y_;
	std::vector<InputListener*> listeners_;
};