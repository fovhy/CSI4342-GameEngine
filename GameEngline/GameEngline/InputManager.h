#pragma once
#include <unordered_map>
#include <vector>
#include "InputListener.h"
/*
The InputManager controls the input of the player. It uses a unordered map to keep track player key up and key down.
It implements an observer pattern with InputListener. 

Author: Dean He
Create Date: 9/8/2016
*/

//TODO bind it with preface class
class InputManager {
public:
	InputManager() {}
	~InputManager() {}

	void pressKey(unsigned int keyID);
	void releaseKey(unsigned int keyID);

	bool isKeyPressed(unsigned int keyID);

	void notifyAll(); // notify all the InputListener

private:
	bool keyPressed_ = false;
	std::unordered_map<unsigned int, bool> keyMap_;
	std::vector<InputListener*> listeners_;
};