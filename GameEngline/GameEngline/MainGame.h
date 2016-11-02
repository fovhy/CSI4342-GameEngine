#pragma once
//AI.h has Stage.h
#include "AI.h"
#include "inputManager.h"
#include <set>
#include "stageBin.h"
#include "inputManager.h"
#include "EventManager.h"
#include "AudioManager.h"
#include "Subject.h"
#include "SpriteFont.h"


const int MAX_CONTROLS = 4;
enum class GameState {PLAY, EXIT, PAUSE, EDIT};
class MainGame : public Subject{
public:
    MainGame();
    ~MainGame();
    void run();
	Stage myStage;

private:
    SDL_Window* window;
    int screenWidth = DrawableObject::screenWidth;
    int screenHeight = DrawableObject::screenHeight;
    float time = 0;
    GameState gameState;
    ResourceManager mainManager;

    Camera camera;
    float fps;
    float frameTime;
    float maxfps = 60.0f;
	int numberOfPlayers;
    //GLTexture playerTexture;

	unsigned int currentStage = 0;
	StageBin myStages_;
	Player* comp = nullptr;

	bool nextLevel = false;
	

	void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
    void initShaders();
    void calculateFPS();
	void pauseMenu(int);
	void addObserverToAllStage(Observer* observer);
	void drawHUD();
	void drawInstruction();

	void updateLevel();
	void goToNextLevel();
	bool checkLevelChange();
	void enableLevelChange();
	bool checkPlayerLifesReachZero();
	void drawText(const char* s, glm::vec2 pos, glm::vec2 scaling,
		float depth, ColorRGBA8 tint, Justification just);

	tilesType editType = GRASS;
	void saveStages();
	void loadStages(int);         //if it failed to load, it will init with the basic stage
    inputManager inputManager_;
	AudioManager audioManager_;

    SpriteBatch spriteBatch_;
	SpriteBatch hudBatch_;

	SpriteFont* spriteFont_;
    GLSLProgram colorProgram;

};
