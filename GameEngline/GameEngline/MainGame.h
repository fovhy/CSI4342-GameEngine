#pragma once
//AI.h has Stage.h
#include "AI.h"
#include "inputManager.h"
#include <set>
#include "EventManager.h"
#include "AudioManager.h"
#include "Subject.h"

const int MAX_CONTROLS = 4;
enum class GameState {PLAY, EXIT, PAUSE};
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
    //GLTexture playerTexture;
	

    void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
    void initShaders();
    void calculateFPS();
	void pauseMenu(int);

    inputManager inputManager_;
	AudioManager audioManager_;

    SpriteBatch spriteBatch_;
    GLSLProgram colorProgram;


};
