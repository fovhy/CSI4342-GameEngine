#pragma once 
#include <fstream>
#include <SDL/SDL.h> 

/**
	File: Preferences.h
	Description: This file will be used to track the user's prefered input
	Date Created: 8/30/16
	Created By: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

class Pref {
private:
	SDL_Scancode up_, down_, left_, right_, jump_;
	void getInput();
	void savePref();
public:
	//Constructor; gets user's preferred inputs from the preferences file
	Pref();
	//Deconstructor; saves the user's preferred inputs to the preferences file
	~Pref();

	//getters; retrieves the user's current input preferences
	char getUp();
	char getDown();
	char getLeft();
	char getRight();
	char getJump();

	//setters; remaps the ipnuts for the user
	void setUp(char newUp);
	void setDown(char newDown);
	void setLeft(char newLeft);
	void setRight(char newRight);
	void setJump(char newJump);
};