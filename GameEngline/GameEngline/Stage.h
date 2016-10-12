#pragma once
#include "Sprite.h"
#include <SDL/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>
#include <vector>
#include "GLSLProgram.h"
#include "GLTexture.h"
#include "ImageLoader.h"
#include "Camera.h"
#include "spriteBatch.h"
#include "fileManager.h"
#include "ResourceManager.h"
#include "tile.h"
#include "Player.h"
#include "Physic.h"
#include "AI.h"

class Stage{
public:
    Stage(){}
    ~Stage(){}
    void init(int);
    void setStage();
    static const int PLAYER_NUMBERS= 2;
    std::vector<Player> players;
    Physic myPhysic;
    void tileCollisionChecking(Player&);
    void update();
    void draw(SpriteBatch& spriteBattch);
    tile findTile(const Player& aPlayer);
    void applyTileEffect(Player& aPlayer,  tile& aTile);
    void applyGravity();
	void drawPlayers(SpriteBatch&);
	void drawStage(SpriteBatch&);
    void checkAttack();

private:
	static const unsigned int quadrantNumber = 4;
    float firstLevelHeight = -200;
    float secondLevelHeight = -100;
    float thirdLevelHeight = 0;
    float fourthLevelHeight = 100;

    GLTexture grassTexture;
    GLTexture iceTexture;
    GLTexture dirtTexture;
    GLTexture poisonTexture;
    GLTexture backGroundTexture;

    // store each level of tiles
	std::vector<std::vector<tile>> myTiles_;

    // two players

    int tileWidth = 100;
    int tileHeight = 30;

    glm::vec4 getTilesLeftRight(const glm::vec4& pos, int);
    glm::vec4 getTilesUpDown(const glm::vec4& pos, int);
    void drawTiles(const std::vector<tile>& level, SpriteBatch& spriteBatch);
    ResourceManager stageManager;


};
