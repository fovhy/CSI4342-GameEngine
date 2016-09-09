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
	char assocPlayer;
	void getInput(char);
	void savePref(char);
public:
	//Constructor; gets user's preferred inputs from the preferences file
	Pref(char);
	//Deconstructor; saves the user's preferred inputs to the preferences file
	~Pref();

	//getters; retrieves the user's current input preferences
	SDL_Scancode getUp();
	SDL_Scancode getDown();
	SDL_Scancode getLeft();
	SDL_Scancode getRight();
	SDL_Scancode getJump();

	//setters; remaps the ipnuts for the user
	void setUp(SDL_Scancode newUp);
	void setDown(SDL_Scancode newDown);
	void setLeft(SDL_Scancode newLeft);
	void setRight(SDL_Scancode newRight);
	void setJump(SDL_Scancode newJump);
};