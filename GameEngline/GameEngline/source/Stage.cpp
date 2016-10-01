#include "Stage.h"

/*GLTexture Stage::grassTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkGreen.png");
GLTexture Stage:: iceTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkBlue.png");
GLTexture Stage:: dirtTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_LightBeige.png");
GLTexture Stage::poisonTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkPing.png");*/
void Stage::init(){
    //load all the textures
    grassTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkGreen.png");
    iceTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkBlue.png");
    dirtTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_LightBeige.png");
    poisonTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkPing.png");
    backGroundTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/Backgrounds/background.png");

    players.resize(PLAYER_NUMBERS);
    players[0].init(glm::vec2(0, 200));
    players[0].setCurrentCharacters(players[0].characters[0]);
    players[0].setPlayerType(PLAYER_ONE);
    players[0].setPayerState(STANDING);
    players[1].init(glm::vec2(1000, 200));
    players[1].setCurrentCharacters(players[0].characters[0]);
    players[1].setPlayerType(PLAYER_TWO);
    players[1].setPayerState(STANDING);

    firstLevel.resize(12);
    secondLevel.resize(12);
    thirdLevel.resize(12);
    fourthLevel.resize(12);
}

void Stage::checkAttack(){
    if(!players[0].currentCharacter_->attackDone){
        if(myPhysic.checkCollisions(players[0].currentCharacter_->attackBox, players[1].getMatrix())){
           players[1].takingDamage = true;
            std::cout << "taking damage p1" << std::endl;
        }
    }
    if(!players[1].currentCharacter_->attackDone){
        if(myPhysic.checkCollisions(players[1].currentCharacter_->attackBox, players[0].getMatrix())){
            players[0].takingDamage = true;
			std::cout << "taking damage p2" << std::endl;
        }
    }
	players[0].currentCharacter_->attackDone = true;
	players[1].currentCharacter_->attackDone = true;

}

void Stage::update() {
	players[0].processInput();
	players[1].processInput();
	if (players[0].onTile) {
		applyTileEffect(players[0], findTile(players[0]));
	}
	players[0].update();
	if (players[1].onTile) {
		applyTileEffect(players[1], findTile(players[1]));
	}
	players[1].update();
	tileCollisionChecking(players[0]);
	tileCollisionChecking(players[1]);
	applyGravity();
	checkAttack();
}

void Stage::draw(SpriteBatch &spriteBattch) {
	for (auto &aPlayer : players) {
		aPlayer.drawPlayer(spriteBattch);
	}
}

// for now it is just gonna be hard coded
void Stage::setStage(SpriteBatch& spriteBatch) {
	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	glm::vec4 wholeScreen(0, -400, 1200, 800);
	glm::vec4 uv(0, 0, 1, 1);
	spriteBatch.draw(wholeScreen, uv, backGroundTexture.id, 0.0f, solidColor);
	glm::vec4 firstLevelPos(0, firstLevelHeight, tileWidth, tileHeight);
	firstLevel[0].setTile(firstLevelPos, POISON);
	firstLevel[1].setTile(getTilesLeftRight(firstLevelPos, 1), POISON);
	firstLevel[2].setTile(getTilesLeftRight(firstLevelPos, 2), POISON);
	firstLevel[3].setTile(getTilesLeftRight(firstLevelPos, 3), GRASS);
	firstLevel[4].setTile(getTilesLeftRight(firstLevelPos, 4), GRASS);
	firstLevel[5].setTile(getTilesLeftRight(firstLevelPos, 5), BLANK);

	firstLevel[6].setTile(getTilesLeftRight(firstLevelPos, 6), BLANK);
	firstLevel[7].setTile(getTilesLeftRight(firstLevelPos, 7), GRASS);
	firstLevel[8].setTile(getTilesLeftRight(firstLevelPos, 8), GRASS);
	firstLevel[9].setTile(getTilesLeftRight(firstLevelPos, 9), POISON);
	firstLevel[10].setTile(getTilesLeftRight(firstLevelPos, 10), POISON);
	firstLevel[11].setTile(getTilesLeftRight(firstLevelPos, 11), POISON);

	glm::vec4 secondLevelPos(0, secondLevelHeight, tileWidth, tileHeight);
	secondLevel[0].setTile(secondLevelPos, BLANK);
	secondLevel[1].setTile(getTilesLeftRight(secondLevelPos, 1), BLANK);
	secondLevel[2].setTile(getTilesLeftRight(secondLevelPos, 2), BLANK);
	secondLevel[3].setTile(getTilesLeftRight(secondLevelPos, 3), BLANK);
	secondLevel[4].setTile(getTilesLeftRight(secondLevelPos, 4), ICE);
	secondLevel[5].setTile(getTilesLeftRight(secondLevelPos, 5), ICE);

	secondLevel[6].setTile(getTilesLeftRight(secondLevelPos, 6), ICE);
	secondLevel[7].setTile(getTilesLeftRight(secondLevelPos, 7), ICE);
	secondLevel[8].setTile(getTilesLeftRight(secondLevelPos, 8), BLANK);
	secondLevel[9].setTile(getTilesLeftRight(secondLevelPos, 9), BLANK);
	secondLevel[10].setTile(getTilesLeftRight(secondLevelPos, 10), BLANK);
	secondLevel[11].setTile(getTilesLeftRight(secondLevelPos, 11), BLANK);

	glm::vec4 thirdLevelPos(0, thirdLevelHeight, tileWidth, tileHeight);
	thirdLevel[0].setTile(thirdLevelPos, BLANK);
	thirdLevel[1].setTile(getTilesLeftRight(thirdLevelPos, 1), DIRT);
	thirdLevel[2].setTile(getTilesLeftRight(thirdLevelPos, 2), DIRT);
	thirdLevel[3].setTile(getTilesLeftRight(thirdLevelPos, 3), DIRT);
	thirdLevel[4].setTile(getTilesLeftRight(thirdLevelPos, 4), DIRT);
	thirdLevel[5].setTile(getTilesLeftRight(thirdLevelPos, 5), BLANK);

	thirdLevel[6].setTile(getTilesLeftRight(thirdLevelPos, 6), BLANK);
	thirdLevel[7].setTile(getTilesLeftRight(thirdLevelPos, 7), DIRT);
	thirdLevel[8].setTile(getTilesLeftRight(thirdLevelPos, 8), DIRT);
	thirdLevel[9].setTile(getTilesLeftRight(thirdLevelPos, 9), DIRT);
	thirdLevel[10].setTile(getTilesLeftRight(thirdLevelPos, 10), DIRT);
	thirdLevel[11].setTile(getTilesLeftRight(thirdLevelPos, 11), BLANK);

	glm::vec4 fourthLevelPos(0, fourthLevelHeight, tileWidth, tileHeight);
	fourthLevel[0].setTile(fourthLevelPos, ICE);
	fourthLevel[1].setTile(getTilesLeftRight(fourthLevelPos, 1), ICE);
	fourthLevel[2].setTile(getTilesLeftRight(fourthLevelPos, 2), BLANK);
	fourthLevel[3].setTile(getTilesLeftRight(fourthLevelPos, 3), BLANK);
	fourthLevel[4].setTile(getTilesLeftRight(fourthLevelPos, 4), ICE);
	fourthLevel[5].setTile(getTilesLeftRight(fourthLevelPos, 5), ICE);

	fourthLevel[6].setTile(getTilesLeftRight(fourthLevelPos, 6), ICE);
	fourthLevel[7].setTile(getTilesLeftRight(fourthLevelPos, 7), ICE);
	fourthLevel[8].setTile(getTilesLeftRight(fourthLevelPos, 8), BLANK);
	fourthLevel[9].setTile(getTilesLeftRight(fourthLevelPos, 9), BLANK);
	fourthLevel[10].setTile(getTilesLeftRight(fourthLevelPos, 10), ICE);
	fourthLevel[11].setTile(getTilesLeftRight(fourthLevelPos, 11), ICE);

	drawTiles(firstLevel, spriteBatch);
	drawTiles(secondLevel, spriteBatch);
	drawTiles(thirdLevel, spriteBatch);
	drawTiles(fourthLevel, spriteBatch);

	spriteBatch.end();
	spriteBatch.renderBatches();
}
// draw a single level of tiles
void Stage::drawTiles(const std::vector<tile>& level, SpriteBatch& spriteBatch) {
	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	glm::vec4 uv(0, 0, 1, 1);
	for (auto aTile : level) {
		switch (aTile.type) {
		case GRASS:
			spriteBatch.draw(aTile.getPos(), uv, grassTexture.id, 0.0f, solidColor);
			break;
		case ICE:
			spriteBatch.draw(aTile.getPos(), uv, iceTexture.id, 0.0f, solidColor);
			break;
		case DIRT:
			spriteBatch.draw(aTile.getPos(), uv, dirtTexture.id, 0.0f, solidColor);
			break;
		case POISON:
			spriteBatch.draw(aTile.getPos(), uv, poisonTexture.id, 0.0f, solidColor);
			break;
		}
	}
}
// direction > 0 means right, < 0 means left
glm::vec4 Stage::getTilesLeftRight(const glm::vec4& pos, int direction) {
	return pos + glm::vec4(tileWidth * direction, 0, 0, 0);
}

// direction > 0 means up, < 0 means down
glm::vec4 Stage::getTilesUpDown(const glm::vec4& pos, int direction) {
	return pos + glm::vec4(0, tileHeight * direction, 0, 0);
}

void Stage::applyGravity() {
	for (auto &aPlayer : players) {
		if (!aPlayer.onTile) {
			aPlayer.setVY(aPlayer.getVY() - myPhysic.gravity);
		}
	}
}

tile Stage::findTile(Player& aPlayer) {
	if (!aPlayer.onTile) {
		printError("Not on tile while finding tile");
		exit(3);
	}
	float playerLeft = aPlayer.getX();
	float playerRight = aPlayer.getX() + aPlayer.getCurr()->getWidth();
	float midPoint = (playerLeft + playerRight) / 2.0;
	if (std::abs(aPlayer.getY() - firstLevelHeight - tileHeight) < 10) {
		for (auto &aTile : firstLevel) {
			if (aTile.type != BLANK)
				if (midPoint > aTile.x && midPoint < aTile.x + aTile.width) {
					return aTile;
				}
		}
	}
	if (std::abs(aPlayer.getY() - secondLevelHeight - tileHeight) < 10) {
		for (auto &aTile : secondLevel) {
			if (aTile.type != BLANK)
				if (midPoint > aTile.x && midPoint < aTile.x + aTile.width) {
					return aTile;
				}
		}
	}
	if (std::abs(aPlayer.getY() - thirdLevelHeight - tileHeight) < 10) {
		for (auto &aTile : thirdLevel) {
			if (aTile.type != BLANK)
				if (midPoint > aTile.x && midPoint < aTile.x + aTile.width) {
					return aTile;
				}
		}
	}
	if (std::abs(aPlayer.getY() - fourthLevelHeight - tileHeight) < 10) {
		for (auto &aTile : fourthLevel) {
			if (aTile.type != BLANK)
				if (midPoint > aTile.x && midPoint < aTile.x + aTile.width) {
					return aTile;
				}
		}
	}
	tile aTile;
	aTile.type = BLANK;
	return aTile;
}

void Stage::applyTileEffect(Player& aPlayer, tile& aTile) {
	float speedX = aPlayer.getVX();
	if (&aTile) {
		switch (aTile.type) {
		case GRASS:
			myPhysic.applyFriction(speedX, aTile.getFriction());
			aPlayer.setVX(speedX);
			break;
		case ICE:
			myPhysic.applyFriction(speedX, aTile.getFriction());
			aPlayer.setVX(speedX);
			break;
		case DIRT:
			myPhysic.applyFriction(speedX, aTile.getFriction());
			aPlayer.setVX(speedX);
			break;
		case POISON:
			myPhysic.applyFriction(speedX, aTile.getFriction());
			aPlayer.setVX(speedX);
			break;
		}
	}
}


void Stage::tileCollisionChecking(Player& aPlayer) {
	glm::vec4 playerPos;
	glm::vec4 tilePos;
	if (aPlayer.getVY() <= 0) {
		playerPos.x = aPlayer.getX();
		playerPos.y = aPlayer.getY();

		playerPos.z = aPlayer.getCurr()->getWidth();
		playerPos.w = aPlayer.getCurr()->getHeight();

		for (auto& aTile : firstLevel) {
			if (aTile.type != BLANK) {
				tilePos = aTile.getPos();
				if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
					aPlayer.onTile = true;
					aPlayer.setY(tilePos.y + tilePos.w / 1.3);
					aPlayer.setVY(0.0f);
					return;
				}
			}
		}
		for (auto& aTile : secondLevel) {
			if (aTile.type != BLANK) {
				tilePos = aTile.getPos();
				if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
					aPlayer.onTile = true;
					aPlayer.setY(tilePos.y + tilePos.w / 1.3);
					aPlayer.setVY(0.0f);
					return;
				}
			}
		}
		for (auto& aTile : thirdLevel) {
			if (aTile.type != BLANK) {
				tilePos = aTile.getPos();
				if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
					aPlayer.onTile = true;
					aPlayer.setY(tilePos.y + tilePos.w / 1.3);
					aPlayer.setVY(0.0f);
					return;
				}
			}
		}
		for (auto& aTile : fourthLevel) {
			if (aTile.type != BLANK) {
				tilePos = aTile.getPos();
				if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
					aPlayer.onTile = true;
					aPlayer.setY(tilePos.y + tilePos.w / 1.3);
					aPlayer.setVY(0.0f);
					return;
				}
			}
		}
	}
	aPlayer.onTile = false;
	//std::cout<<"not on tile" << std::endl;
}
