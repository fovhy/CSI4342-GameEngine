#pragma once 
#include <fstream>
#include <SDL/SDL.h> 

/**
File: Preferences.h
Description: This file will be used to track the user's prefered input
Date Created: 8/30/16
Created By: Logan
Last Modified: 9/11/16
Modified By: Logan
*/

class Pref {
private:
	int up_, down_, left_, right_, jump_;
	//int attack_;
	char assocPlayer;
	void getInput(char);
	bool controller;
	SDL_Joystick* joy;
public:
	//Constructor; gets user's preferred inputs from the preferences file
	Pref(char);
	Pref();
	//Deconstructor; saves the user's preferred inputs to the preferences file
	~Pref();

	//initializes the preferences
	void init(char);

	//getters; retrieves the user's current input preferences
	int getUp();
	int getDown();
	int getLeft();
	int getRight();
	int getJump();
	//int getAttack();

	//setters; remaps the ipnuts for the user
	void setUp(int newUp);
	void setDown(int newDown);
	void setLeft(int newLeft);
	void setRight(int newRight);
	void setJump(int newJump);
	//void setAttack(int newAttack);

	void savePref(char);
};