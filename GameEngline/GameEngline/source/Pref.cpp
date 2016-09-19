#include "Preferences.h"

/**
File: Pref.cpp
Description: Implementation of Pref's functions
Date Created: 9/9/2016
Creator: Logan
Last Modified: 9/11/16
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
Pref::Pref() {

}


void Pref::init(char playerNum) {
	getInput(playerNum);
}


void Pref::getInput(char player) {
	std::fstream file;
	file.open(std::string("inputs") + player + ".txt");
	if (!file.is_open()) {
		//defaults
		if (player == '2') {
			up_ = SDLK_UP;
			down_ = SDLK_DOWN;
			left_ = SDLK_LEFT;
			right_ = SDLK_RIGHT;
		}
		else if (player == '1') {
			up_ = SDLK_w;
			down_ = SDLK_s;
			left_ = SDLK_a;
			right_ = SDLK_d;
		}
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


int Pref::getUp() {
	return up_;
}
int Pref::getDown() {
	return down_;
}
int Pref::getLeft() {
	return left_;
}
int Pref::getRight() {
	return right_;
}
int Pref::getJump() {
	return jump_;
}
int Pref::getAttack() {
	return attack_;
}


void Pref::setUp(int newUp) {
	up_ = newUp;
}
void Pref::setDown(int newDown) {
	down_ = newDown;
}
void Pref::setLeft(int newLeft) {
	left_ = newLeft;
}
void Pref::setRight(int newRight) {
	right_ = newRight;
}
void Pref::setJump(int newJump) {
	jump_ = newJump;
}
void Pref::setAttack(int newAttack) {
	attack_ = newAttack;
}