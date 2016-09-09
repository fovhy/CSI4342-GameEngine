#pragma once
#include <unordered_map>
/*
The InputManager controls the input of the player. It uses a unordered map to keep track player key up and key down.

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

private:
	bool keyPressed_ = false;
	std::unordered_map<unsigned int, bool> keyMap_;
};