#include "MainGame.h"
#include "log.h"
#include <GL/glew.h>
MainGame::MainGame() {
	window_ = nullptr;
	gameState_ = GameState::PLAY;
}


MainGame::~MainGame(){
}

void MainGame::run() {
	initSystem();
	gameLoop();
}

void MainGame::initSystem() {
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	window_ = SDL_CreateWindow("Game Engine", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, screenWidth_, screenHeight_, SDL_WINDOW_OPENGL);    // used sdl to open a window and kick graphic to opengl

	if (window_ == nullptr) {
		log::getInstance().logMessage("Windows failed to open", logType::error);
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window_);
	if (glContext == nullptr) {
		log::getInstance().logMessage("SDL_GL context could not be created", logType::error);
	}

	GLenum glewSignal = glewInit();
	if (glewSignal != GLEW_OK) {
		log::getInstance().logMessage("Failed to initialize glew", logType::error);
	}
	//TODO:initiate shader
	mainCamera_.init(screenWidth_, screenHeight_);
}

void MainGame::gameLoop() {
	while (gameState_ != GameState::EXIT) {
		// TODO: change the fps to system dependent (possibly), for now is hard coded at 60 fps 
		float startTicks = SDL_GetTicks();
		time_ += 0.1;
		processInput();
		calculateFPS();
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
			break;
		case SDL_KEYUP:
			break;
		}
	}
}

void MainGame::drawGame() {
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//TODO: draw the game
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