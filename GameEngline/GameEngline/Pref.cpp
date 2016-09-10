#include "Preferences.h"

/**
	File: Pref.cpp
	Description: Implementation of Pref's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/10/16
	Modified By: Logan
*/

/*
	SDL Game Controller Buttons:
		SDL_CONTROLLER_BUTTON_INVALID
		SDL_CONTROLLER_BUTTON_A
		SDL_CONTROLLER_BUTTON_B
		SDL_CONTROLLER_BUTTON_X
		SDL_CONTROLLER_BUTTON_Y
		SDL_CONTROLLER_BUTTON_BACK
		SDL_CONTROLLER_BUTTON_GUIDE
		SDL_CONTROLLER_BUTTON_START
		SDL_CONTROLLER_BUTTON_LEFTSTICK
		SDL_CONTROLLER_BUTTON_RIGHTSTICK
		SDL_CONTROLLER_BUTTON_LEFTSHOULDER
		SDL_CONTROLLER_BUTTON_RIGHTSHOULDER
		SDL_CONTROLLER_BUTTON_DPAD_UP
		SDL_CONTROLLER_BUTTON_DPAD_DOWN
		SDL_CONTROLLER_BUTTON_DPAD_LEFT
		SDL_CONTROLLER_BUTTON_DPAD_RIGHT
		SDL_CONTROLLER_BUTTON_MAX

	SDL Axis:
		SDL_CONTROLLER_AXIS_INVALID
		SDL_CONTROLLER_AXIS_LEFTX
		SDL_CONTROLLER_AXIS_LEFTY
		SDL_CONTROLLER_AXIS_RIGHTX
		SDL_CONTROLLER_AXIS_RIGHTY
		SDL_CONTROLLER_AXIS_TRIGGERLEFT
		SDL_CONTROLLER_AXIS_TRIGGERRIGHT
		SDL_CONTROLLER_AXIS_MAX
*/

void Pref::getInput(char player) {
	std::fstream file;
	file.open(std::string("inputs") + player + ".txt");
	if (!file.is_open()) {
		//defaults
		up_ = SDL_SCANCODE_UP;
		down_ = SDL_SCANCODE_DOWN;
		left_ = SDL_SCANCODE_LEFT;
		right_ = SDL_SCANCODE_RIGHT;
		jump_ = SDL_SCANCODE_SPACE;
	}
	else {
		//reads the user's preferences
		//can be changed later
	}
}
void Pref::savePref(char player) {
	//write the prefered inputs to the file
	std::fstream file;
	file.open(std::string("inputs") + player + ".txt");
	if (!file.is_open()) {
		//do something
	}
	else {
		file.seekp(0);
		//write the data to the file, overwriting the previous contents
	}
}


Pref::Pref(char player) {
	assocPlayer = player;
	getInput(player);
}
Pref::~Pref() {
	savePref(assocPlayer);
}


SDL_Scancode Pref::getUp() {
	return up_;
}
SDL_Scancode Pref::getDown() {
	return down_;
}
SDL_Scancode Pref::getLeft() {
	return left_;
}
SDL_Scancode Pref::getRight() {
	return right_;
}
SDL_Scancode Pref::getJump() {
	return jump_;
}


void Pref::setUp(SDL_Scancode newUp) {
	up_ = newUp;
}
void Pref::setDown(SDL_Scancode newDown) {
	down_ = newDown;
}
void Pref::setLeft(SDL_Scancode newLeft) {
	left_ = newLeft;
}
void Pref::setRight(SDL_Scancode newRight) {
	right_ = newRight;
}
void Pref::setJump(SDL_Scancode newJump) {
	jump_ = newJump;
}