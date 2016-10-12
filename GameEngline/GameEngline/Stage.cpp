#include "Stage.h"
#include "AI.h"
#include <iostream>

/*GLTexture Stage::grassTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkGreen.png");
GLTexture Stage:: iceTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkBlue.png");
GLTexture Stage:: dirtTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_LightBeige.png");
GLTexture Stage::poisonTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkPing.png");*/
void Stage::init(int numPlayers) {
	//load all the textures
	grassTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkGreen.png");
	iceTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkBlue.png");
	dirtTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_LightBeige.png");
	poisonTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkPing.png");
	backGroundTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/Backgrounds/background.png");

	players.resize(numPlayers);
	players[0].init(glm::vec2(0, 200));
	players[0].setCurrentCharacters(players[0].characters[0]);
	players[0].setPlayerType(PLAYER_ONE);
	players[0].setPayerState(STANDING);
	if (numPlayers > 1) {
		players[1].setPlayerType(PLAYER_TWO);
		AIPlayerActive_ = false;
		AIPlayer_ = NULL;
	}
	else {
		//player 2 is an AI character
		AI compPlayer;
		compPlayer.setPlayers(players);
		compPlayer.setStage(this);
		players.push_back(compPlayer);
		players[1].setPlayerType(COMP);
		AIPlayerActive_ = true;
		AIPlayer_ = &compPlayer;
	}
	players[1].init(glm::vec2(1000, 200));
	players[1].setCurrentCharacters(players[1].characters[0]);
	players[1].setPayerState(STANDING);

	myTiles_.resize(quadrantNumber);
	setStage();

}

void Stage::checkAttack() {
	if (!players[0].currentCharacter_->attackDone) {
		if (myPhysic.checkCollisions(players[0].currentCharacter_->attackBox, players[1].getMatrix())) {
			players[1].takingDamage = true;
			std::cout << "taking damage p1" << std::endl;
		}
	}
	if (!players[1].currentCharacter_->attackDone) {
		if (myPhysic.checkCollisions(players[1].currentCharacter_->attackBox, players[0].getMatrix())) {
			players[0].takingDamage = true;
			std::cout << "taking damage p2" << std::endl;
		}
	}
	players[0].currentCharacter_->attackDone = true;
	players[1].currentCharacter_->attackDone = true;

}

bool Stage::isAI()
{
	return AIPlayerActive_;
}

Player * Stage::getAI()
{
	return AIPlayer_;
}

void Stage::update() {
	for (auto& player : players) {
		player.processInput();
		tileCollisionChecking(player);
		if (player.onTile) {
			applyTileEffect(player, findTile(player));
		}
		applyGravity();
		checkAttack();
		player.update();
	}
	/*players[0].processInput();
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
	checkAttack();*/
}

void Stage::draw(SpriteBatch &spriteBatch) {
	drawPlayers(spriteBatch);
}
void Stage::drawPlayers(SpriteBatch& spriteBatch) {
	for (auto &aPlayer : players) {
		aPlayer.drawPlayer(spriteBatch);
	}
}
void Stage::drawStage(SpriteBatch& spriteBatch) {
	spriteBatch.begin();
	Color solidColor;
	solidColor.r = 255;
	solidColor.g = 255;
	solidColor.b = 255;
	solidColor.a = 255;
	glm::vec4 wholeScreen(0, -400, 1200, 800);
	glm::vec4 uv(0, 0, 1, 1);
	spriteBatch.draw(wholeScreen, uv, backGroundTexture.id, 0.0f, solidColor);
	for (auto& i : myTiles_) {
		drawTiles(i, spriteBatch);
	}
	spriteBatch.end();
	spriteBatch.renderBatches();
}
// for now it is just gonna be hard coded
void Stage::setStage() {

	glm::vec4 firstLevelPos(0, firstLevelHeight, tileWidth, tileHeight);
	myTiles_[0].emplace_back(firstLevelPos, POISON);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 1), POISON);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 2), POISON);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 3), GRASS);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 4), GRASS);

	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 7), GRASS);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 8), GRASS);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 9), POISON);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 10), POISON);
	myTiles_[0].emplace_back(getTilesLeftRight(firstLevelPos, 11), POISON);

	glm::vec4 secondLevelPos(0, secondLevelHeight, tileWidth, tileHeight);
	myTiles_[1].emplace_back(getTilesLeftRight(secondLevelPos, 4), ICE);
	myTiles_[1].emplace_back(getTilesLeftRight(secondLevelPos, 5), ICE);

	myTiles_[1].emplace_back(getTilesLeftRight(secondLevelPos, 6), ICE);
	myTiles_[1].emplace_back(getTilesLeftRight(secondLevelPos, 7), ICE);

	glm::vec4 thirdLevelPos(0, thirdLevelHeight, tileWidth, tileHeight);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 1), DIRT);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 2), DIRT);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 3), DIRT);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 4), DIRT);

	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 7), DIRT);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 8), DIRT);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 9), DIRT);
	myTiles_[2].emplace_back(getTilesLeftRight(thirdLevelPos, 10), DIRT);

	glm::vec4 fourthLevelPos(0, fourthLevelHeight, tileWidth, tileHeight);
	myTiles_[3].emplace_back(fourthLevelPos, ICE);
	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 1), ICE);
	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 4), ICE);
	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 5), ICE);

	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 6), ICE);
	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 7), ICE);
	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 10), ICE);
	myTiles_[3].emplace_back(getTilesLeftRight(fourthLevelPos, 11), ICE);
}
// draw all tiles
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
			spriteBatch.draw(aTile.getPos(), uv, grassTexture.id, 1.5f, solidColor);
			break;
		case ICE:
			spriteBatch.draw(aTile.getPos(), uv, iceTexture.id, 1.5f, solidColor);
			break;
		case DIRT:
			spriteBatch.draw(aTile.getPos(), uv, dirtTexture.id, 1.5f, solidColor);
			break;
		case POISON:
			spriteBatch.draw(aTile.getPos(), uv, poisonTexture.id, 1.5f, solidColor);
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

tile Stage::findTile(Player& const aPlayer) {
	if (!aPlayer.onTile) {
		printError("Not on tile while finding tile");
		exit(3);
	}
	float playerLeft = aPlayer.getX();
	float playerRight = aPlayer.getX() + aPlayer.getCurr()->getWidth();
	float midPoint = (playerLeft + playerRight) / 2.0;
	for (auto &tiles : myTiles_) {
		for (auto &aTile : tiles) {
			if (std::abs(aPlayer.getY() - aTile.getPos().y - aTile.getColliPosition().y) < 10) {
				if (midPoint > aTile.getPos().x && midPoint < aTile.getPos().x +
					aTile.getColliPosition().x) {
					return aTile;
				}
			}
		}
	}
	tile aTile;
	aTile.type = GRASS;
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

		for (auto& aTile : myTiles_[0]) {
			tilePos = aTile.getPos();
			if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
				aPlayer.onTile = true;
				aPlayer.setY(tilePos.y + tilePos.w / 1.3);
				aPlayer.setVY(0.0f);
				return;
			}
		}
		for (auto& aTile : myTiles_[1]) {
			tilePos = aTile.getPos();
			if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
				aPlayer.onTile = true;
				aPlayer.setY(tilePos.y + tilePos.w / 1.3);
				aPlayer.setVY(0.0f);
				return;
			}
		}
		for (auto& aTile : myTiles_[2]) {
			tilePos = aTile.getPos();
			if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
				aPlayer.onTile = true;
				aPlayer.setY(tilePos.y + tilePos.w / 1.3);
				aPlayer.setVY(0.0f);
				return;
			}
		}
		for (auto& aTile : myTiles_[3]) {
			tilePos = aTile.getPos();
			if (myPhysic.checkTileCollisions(playerPos, tilePos)) {
				aPlayer.onTile = true;
				aPlayer.setY(tilePos.y + tilePos.w / 1.3);
				aPlayer.setVY(0.0f);
				return;
			}
		}
	}
	aPlayer.onTile = false;
	//std::cout<<"not on tile" << std::endl;
}
