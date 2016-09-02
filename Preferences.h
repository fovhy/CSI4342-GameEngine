#ifndef PREF_H
#define PREF_H
#include <fstream>
/**
	File: Preferences.h
	Description: This file will be used to track the user's prefered input
	Date Created: 8/30/16
	Created By: Logan
	Last Modified: 8/31/16
	Modified By: Logan
*/

class Pref {
private:
	char up_, down_, left_, right_, jump_;
	void getInput() {
		std::fstream file;
		file.open("inputs.txt");
		if (!file.is_open) {
			//defaults
			up_ = 'w';
			down_ = 's';
			left_ = 'a';
			right_ = 'd';
			jump_ = 0x20;
		}
		else {
			//reads the user's preferences
			//can be changed later
		}
	}
	void savePref() {
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
public:
	//Constructor; gets user's preferred inputs from the preferences file
	Pref() {
		getInput();
	}
	//Deconstructor; saves the user's preferred inputs to the preferences file
	~Pref() {
		savePref();
	}

	//getters; retrieves the user's current input preferences
	char getUp() {
		return up_;
	}
	char getDown() {
		return down_;
	}
	char getLeft() {
		return left_;
	}
	char getRight() {
		return right_;
	}
	char getJump() {
		return jump_;
	}

	//setters; remaps the ipnuts for the user
	void setUp(char newUp) {
		up_ = newUp;
	}
	void setDown(char newDown) {
		down_ = newDown;
	}
	void setLeft(char newLeft) {
		left_ = newLeft;
	}
	void setRight(char newRight) {
		right_ = newRight;
	}
	void setJump(char newJump) {
		jump_ = newJump;
	}
};

#endif