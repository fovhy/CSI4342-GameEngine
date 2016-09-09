#pragma once
#include <SDL/SDL.h>
#include "Camera.h"
enum class GameState {PLAY, EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();
	void run();
private:
	SDL_Window* window_;
	int screenWidth_ = 1200;
	int screenHeight_ = 800;
	Camera mainCamera_;
	float time_ = 0;
	GameState gameState_;
	float fps_;
	float frameTime_;
	float maxfps_ = 60.0f;
	SDL_Renderer* renderer_ = nullptr;

	void initSystem();
	void gameLoop();
	void processInput();
	void drawGame();
	void calculateFPS();
};

