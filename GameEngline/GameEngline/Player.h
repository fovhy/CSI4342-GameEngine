#pragma once
#include "Preferences.h"
#include "Character.h"

/**
	File: Player.h
	Description: Player object
	Date Created: 8/31/16
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

class Player : public Character{
private:
	Pref* preference_;
	char num_;
public:
	Player(char playerNum);
	~Player();
	
};

