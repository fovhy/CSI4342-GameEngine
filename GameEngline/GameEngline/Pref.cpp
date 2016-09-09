#include "Preferences.h"

/**
	File: Pref.cpp
	Description: Implementation of Pref's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

void Pref::getInput() {
	std::fstream file;
	file.open("inputs.txt");
	if (!file.is_open) {
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
void Pref::savePref() {
	//write the prefered inputs to the file
	std::fstream file;
	file.open("inputs.txt");
	if (!file.is_open) {
		//do something
	}
	else {
		file.seekp(0);
		//write the data to the file, overwriting the previous contents
	}
}
Pref::Pref() {
	getInput();
}
//Deconstructor; saves the user's preferred inputs to the preferences file
Pref::~Pref() {
	savePref();
}

//getters; retrieves the user's current input preferences
char Pref::getUp() {
	return up_;
}
char Pref::getDown() {
	return down_;
}
char Pref::getLeft() {
	return left_;
}
char Pref::getRight() {
	return right_;
}
char Pref::getJump() {
	return jump_;
}

//setters; remaps the ipnuts for the user
void Pref::setUp(char newUp) {
	up_ = newUp;
}
void Pref::setDown(char newDown) {
	down_ = newDown;
}
void Pref::setLeft(char newLeft) {
	left_ = newLeft;
}
void Pref::setRight(char newRight) {
	right_ = newRight;
}
void Pref::setJump(char newJump) {
	jump_ = newJump;
}