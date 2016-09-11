#pragma once
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <unordered_map>
#include "Camera.h"
#include "InputManager.h"
#include "Player.h"
#include "Preferences.h"
#include "Stage.h"

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
	InputManager inputManager_;
	std::vector<Player> players_;
	std::vector<Stage> stages_;
	unsigned int currentStage_;

	void initSystem();
	void gameLoop();
	void processInput();
	void drawGame();
	void calculateFPS();
};

