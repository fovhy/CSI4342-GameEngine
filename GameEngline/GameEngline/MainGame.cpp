#include "MainGame.h"
#include "log.h"
#include <GL/glew.h>





MainGame::MainGame() {
	window_ = nullptr;
	gameState_ = GameState::PLAY;
}


MainGame::~MainGame(){
	SDL_DestroyRenderer(renderer_);
	SDL_DestroyWindow(window_);
}


void MainGame::run() {
	initSystem();
	gameLoop();
}


void MainGame::initSystem() {
	
	int numPlayers = 1;
	


	stages_.push_back(*new Stage());
	stages_[0].getNPCs().push_back(*new Character());
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
	// initiate SDL window 
	window_ = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, screenWidth_, screenHeight_, SDL_WINDOW_SHOWN);    // used sdl to open a window and kick graphic to opengl 
	if (window_ == nullptr) {
		log::getInstance().logMessage("Windows failed to open " + std::string(SDL_GetError()), logType::error);
	}
	// initiate SDL_renderer
	renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED);
	if (renderer_ == nullptr) {
		log::getInstance().logMessage("Failed to create SDL render" + std::string(SDL_GetError()), logType::error);
	}
	Pref* pref;
	for (int i = 0; i < numPlayers; i++) {
		pref = new Pref((char)i);
	}
	stages_[0].getNPCs()[0].makeDefault(renderer_);
	// init game camera
	mainCamera_.init(screenWidth_, screenHeight_);
}


void MainGame::gameLoop() {
	while (gameState_ != GameState::EXIT) {
		// TODO: change the fps to system dependent (possibly), for now is hard coded at 60 fps 
		float startTicks = SDL_GetTicks();
		time_ += 0.1;
		processInput();
		calculateFPS();
		drawGame();
	}
}


void MainGame::processInput() {
//TODO: process input
	SDL_Event event;
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			gameState_ = GameState::EXIT;
			break;
		case SDL_MOUSEMOTION:
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		case SDL_MOUSEBUTTONUP:
			break;
		case SDL_KEYDOWN:
			inputManager_.pressKey(event.key.keysym.sym);
			break;
		case SDL_KEYUP:
			inputManager_.releaseKey(event.key.keysym.sym);
			break;
		case SDL_CONTROLLERBUTTONDOWN:
			inputManager_.pressButton(event.cbutton.button);
			break;
		case SDL_CONTROLLERBUTTONUP:
			inputManager_.releaseButton(event.cbutton.button);
			break;
		case SDL_CONTROLLER_AXIS_LEFTX:
			//left stick tilted left or right
			break;
		case SDL_CONTROLLER_AXIS_LEFTY:
			//left stick tilted up or down
			break;
		}
	}
}


void MainGame::drawGame() {
	SDL_RenderClear(renderer_);
	for (int i = 0; i < stages_[currentStage_].getNPCs().size(); i++) {
		
		stages_[currentStage_].getNPCs()[i].draw(renderer_);
	}
	SDL_RenderPresent(renderer_);
}


void MainGame::calculateFPS() {
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];

	static float prevTicks = SDL_GetTicks();

	static int currentFrame = 0;
	float currentTicks = SDL_GetTicks();
	frameTime_ = currentTicks - prevTicks;

	frameTimes[currentFrame % NUM_SAMPLES] = frameTime_;

	int count;
	currentFrame++;

	if (currentFrame < NUM_SAMPLES) {
		count = currentFrame;
	}
	else {
		count = NUM_SAMPLES;
	}
	prevTicks = currentTicks;

	float frameTimeAverage = 0;;

	for (int i = 0; i < count; ++i) {
		frameTimeAverage += frameTimes[i];
	}
	frameTimeAverage /= count;
	if (frameTimeAverage > 0) {
		fps_ = 1000.0f / frameTimeAverage;
	}
	else {
		fps_ = 60.0f;
	}
}