#pragma once
#include "Stage.h"
#include "inputManager.h"
enum class GameState {PLAY, EXIT};
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

    inputManager inputManager_;

    SpriteBatch spriteBatch_;
    GLSLProgram colorProgram;


};
