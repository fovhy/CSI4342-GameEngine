#include "Player.h"

/**
	File: Player.cpp
	Description: Implementation of Player's functions
	Date Created: 9/9/16
	Creator: Logan
	Last Modified: 9/9/16
	Modified By: Logan
*/

Player::Player(char number) {
	num_ = number;
	preference_ = new Pref(num_);
}

Player::~Player() {
	delete preference_;
}