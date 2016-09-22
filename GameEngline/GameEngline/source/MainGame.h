#pragma once
#include "Stage.h"
#include "inputManager.h"
#include <set>

const int MAX_CONTROLS = 4;
enum class GameState {PLAY, EXIT, PAUSE};
class MainGame{
public:
    MainGame();
    ~MainGame();

    void run();



private:
    SDL_Window* window;
    int screenWidth = 1200;
    int screenHeight = 800;
    float time = 0;
    GameState gameState;
    ResourceManager mainManager;

    Camera camera;
    float fps;
    float frameTime;
    float maxfps = 60.0f;
    //GLTexture playerTexture;



    Stage myStage;

    void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
    void initShaders();
    void calculateFPS();
	void pauseMenu(int);

    inputManager inputManager_;

    SpriteBatch spriteBatch_;
    GLSLProgram colorProgram;


};
