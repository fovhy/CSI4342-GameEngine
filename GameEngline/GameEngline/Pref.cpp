#include "Preferences.h"

/**
	File: Pref.cpp
	Description: Implementation of Pref's functions
	Date Created: 9/9/2016
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

void Pref::getInput(char player) {
	std::fstream file;
	file.open(std::string("inputs") + player + ".txt");
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

void Pref::savePref(char player) {
	//write the prefered inputs to the file
	std::fstream file;
	file.open(std::string("inputs") + player + ".txt");
	if (!file.is_open) {
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