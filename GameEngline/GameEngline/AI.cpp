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
	preferences_.setUp(AI_UP);
}


void AI::setStage(Stage* stage)
{
	//stage_ = stage;
}

void AI::pathfind()
{
	SDL_Event action;
	action.type = SDL_KEYDOWN;
	Player* target = NULL;
	if (!stage_->players[1].isDead) {
		if (!stage_->players[0].isDead
			&& stage_->players[0].getPlayerType() != COMP)
		{
			target = &stage_->players[0];
		}

		if (target)
		{
			float targetX = target->getX();
			float selfX = stage_->players[1].getX();
			float targetY = target->getY();
			float selfY = stage_->players[1].getY();
			float PUMod = 1;
			if (currentPU && currentPU->getType() == SPEED_DOWN)
			{
				PUMod = 0.5;
			}
			if (currentPU && currentPU->getType() == SPEED_UP)
			{
				PUMod = 1.5;
			}
			if (target->getX() > selfX && stage_->players[1].getVX() < 1 * PUMod) 
			{
				action.key.keysym.sym = preferences_.getLeft();
				action.type = SDL_KEYUP;
				SDL_PushEvent(&action);
				action.key.keysym.sym = preferences_.getRight();
				action.type = SDL_KEYDOWN;
				SDL_PushEvent(&action);
			}
			else if (target->getX() < selfX && stage_->players[1].getVX() > -1 * PUMod)
			{
				action.key.keysym.sym = preferences_.getRight();
				action.type = SDL_KEYUP;
				SDL_PushEvent(&action);
				action.key.keysym.sym = preferences_.getLeft();
				action.type = SDL_KEYDOWN;
				SDL_PushEvent(&action);
			}
			if (stage_->players[1].onTile) {
				tilesType ttype = stage_->findTile(stage_->players[1]).type;
				if (ttype == POISON || targetY > selfY) {
					action.key.keysym.sym = preferences_.getUp();
					SDL_PushEvent(&action);
				}
				else
				{
					action.key.keysym.sym = preferences_.getUp();
					action.type = SDL_KEYUP;
					SDL_PushEvent(&action);
				}
				if (stage_->players[1].direction > 0)
				{
					//looking right

				}
				else
				{
					//looking left

				}
			}
		}
	}
	return;
}
