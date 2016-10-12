#include "AI.h"
/*
	Author: Logan
	Date Created: 10/10/16
	Description: Implementation of AI methods
*/

AI::AI()
{
	preferences_.setJump(AI_JUMP);
	preferences_.setDown(AI_DOWN);
	preferences_.setLeft(AI_LEFT);
	preferences_.setRight(AI_RIGHT);
}

void AI::setPlayers(std::vector<Player> players)
{
	otherPlayers.resize(players.size());
	std::cout << players.size();
	for (int i = 0; i < players.size(); i++) 
	{
		otherPlayers.push_back(players[i]);
	}
}

void AI::setStage(Stage* stage)
{
	stage_ = stage;
}

void AI::pathfind()
{
	SDL_Event action;
	action.type = SDL_KEYDOWN;
	Player* target = NULL;
	for (int i = 0; i < otherPlayers.size() && !target; i++)
	{
		if (!otherPlayers[i].isDead 
			&& otherPlayers[i].getPlayerType() != COMP)
		{
			target = &otherPlayers[i];
		}
	}
	if (target) 
	{
		if (target->getX() > getX()) {
			action.key.keysym.sym = preferences_.getRight();
		}
		else if (target->getX() < getX())
		{
			action.key.keysym.sym = preferences_.getLeft();
		}
		SDL_PushEvent(&action);

		if (stage_->findTile(*this).type == POISON) {
			action.key.keysym.sym = preferences_.getJump();
			SDL_PushEvent(&action);
		}
		if (direction > 0) 
		{
			//looking right

		}
		else
		{
			//looking left

		}
	}
	return;
}
