#pragma once
/*
	Author: Logan
	Date Created: 10/10/16
	Description: class to simulate an AI character
*/
#include "Player.h"
#include "Stage.h"
const int AI_JUMP = 1;
const int AI_LEFT = 2;
const int AI_RIGHT = 3;
const int AI_DOWN = 4;
const int AI_UP = 5;
class AI : public Player {
public:
	AI();
	void setStage(Stage*);
	void pathfind();
	std::vector<Player> otherPlayers;
private:
	Stage* stage_;
};