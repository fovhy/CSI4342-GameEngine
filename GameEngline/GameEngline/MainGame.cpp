#include "MainGame.h"
#include "Error.h"
MainGame::MainGame::MainGame(){
    window = nullptr;
    gameState = GameState::PLAY;
	thisType_ = type::MAINGAME;
}



MainGame::~MainGame(){
}

void MainGame::run(){
    initSystems();
    gameLoop();
}
void MainGame::initSystems() {
	do {
		std::cout << "One player, or two?\n";
		std::cin >>numberOfPlayers;
		if (numberOfPlayers != 1 && numberOfPlayers != 2) {
			std::cout << "I'm sorry; that's not a valid number of players.\n";
		}
	} while (numberOfPlayers != 1 && numberOfPlayers != 2);
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    window = SDL_CreateWindow("Yolo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight,SDL_WINDOW_OPENGL);
    if(window == nullptr){
        printError("Windows failed to open");
    }
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if(glContext == nullptr){
        printError("SDL_GL context could not be created!");
    }
    GLenum glewSignal = glewInit();
    if (glewSignal != GLEW_OK){
        printError("Failed to initialize glew");
    }
	EventManager::getEventManager().init(); // this has to be init before audioManager
	audioManager_.init();



    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    initShaders();
    camera.init(screenWidth, screenHeight);

    spriteBatch_.init();
	hudBatch_.init();

	// set up the font 
	spriteFont_ = new SpriteFont("../YOLO/font/chintzy.ttf", 32);

	loadStages(numberOfPlayers);
	addObserverToAllStage(&audioManager_);
	addObserver(&audioManager_);
}

void MainGame::gameLoop(){
	bool AIPlayer = myStages_.stages[currentStage].isAI();
	if (AIPlayer) {
		comp = myStages_.stages[currentStage].getAI();
	}
    while(gameState != GameState::EXIT){
        float startTicks = SDL_GetTicks();
        time += 0.1;
		if (comp)
		{
			((AI*)comp)->pathfind();
		}
		processInput();
        calculateFPS();
        static int frameCounter = 0;
        frameCounter ++;
        if(frameCounter == 10){
            //std::cout << fps << std::endl;
            frameCounter = 0;
        }
        drawGame();
		if (EventManager::getEventManager().getEvent("gameStart").happened == false) {
			notifyAll(*this, "gameStart");
			EventManager::getEventManager().setEventTrue("gameStart");
		}
// limit fps to be 60
        float frameTicks = SDL_GetTicks() - startTicks;
        if(1000.0/ maxfps > frameTicks){
            SDL_Delay(1000.0F/ maxfps - frameTicks);
        }
    }
}

void MainGame::processInput(){
    SDL_Event evnt;

	while (SDL_PollEvent(&evnt)) {
		if (gameState == GameState::EDIT) {
			switch (evnt.type) {
			case SDL_MOUSEBUTTONDOWN:
				myStages_.stages[currentStage].addTile(evnt.motion.x, - evnt.motion.y + 400, editType);
				break;
			case SDL_KEYDOWN:
				inputManager_.pressKey(evnt.key.keysym.sym);
				break;
			case SDL_KEYUP:
				inputManager_.releaseKey(evnt.key.keysym.sym);
				break;
			}
			if (inputManager_.isKeyPressed(SDLK_1)) {
				editType = GRASS;
			}
			if (inputManager_.isKeyPressed(SDLK_2)) {
				editType = DIRT;
			}
			if (inputManager_.isKeyPressed(SDLK_3)) {
				editType = ICE;
			}
			if (inputManager_.isKeyPressed(SDLK_4)) {
				editType = POISON;
			}
			if (inputManager_.isKeyPressed(SDLK_r)) {
				gameState = GameState::PLAY;
				inputManager_.releaseKey(SDLK_r);
			}
			if (inputManager_.isKeyPressed(SDLK_z)) {
				myStages_.stages[currentStage].removeTileJustAdded();
				inputManager_.releaseKey(SDLK_z);
			}
		}
		else {
			switch (evnt.type) {
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_KEYDOWN:
				myStages_.stages[currentStage].players[1].playerInputManager.pressKey(evnt.key.keysym.sym);
				if (myStages_.stages[currentStage].players[1].playerInputManager.isKeyPressed(SDLK_F6)) {
					gameState = GameState::PAUSE;
					pauseMenu(2);
					myStages_.stages[currentStage].players[1].playerInputManager.releaseKey(SDLK_F6);
				}
				myStages_.stages[currentStage].players[0].playerInputManager.pressKey(evnt.key.keysym.sym);
				if (myStages_.stages[currentStage].players[0].playerInputManager.isKeyPressed(SDLK_F5)) {
					gameState = GameState::PAUSE;
					pauseMenu(1);
					myStages_.stages[currentStage].players[0].playerInputManager.releaseKey(SDLK_F5);
				}
				break;
			case SDL_KEYUP:
				myStages_.stages[currentStage].players[1].playerInputManager.releaseKey(evnt.key.keysym.sym);
				myStages_.stages[currentStage].players[0].playerInputManager.releaseKey(evnt.key.keysym.sym);
				break;
			}
		}
	}
	myStages_.stages[currentStage].update();
}

void MainGame::drawGame() {

	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	colorProgram.use();

	glActiveTexture(GL_TEXTURE0);


	GLint textureLocation = colorProgram.getUniformLocation("mySampler");

	glUniform1i(textureLocation, 0);

	// GLuint timeLocation = colorProgram.getUniformLocation("time");
	//glUniform1f(timeLocation, time);

	GLuint pLocation = colorProgram.getUniformLocation("ortho");
	glm::mat4 cameraMatrix = camera.getCameraMatrix();

	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));



	myStages_.stages[currentStage].drawStage(spriteBatch_);
	if (gameState != GameState::EDIT) {
		spriteBatch_.begin();
		Color color;
		color.r = 255;
		color.b = 255;
		color.g = 255;
		color.a = 255;
		myStages_.stages[currentStage].drawPlayers(spriteBatch_);
		spriteBatch_.end();
		spriteBatch_.renderBatches();
	}

	drawHUD();

	glBindTexture(GL_TEXTURE_2D, 0);
	colorProgram.unuse();
	SDL_GL_SwapWindow(window);
}

void MainGame::initShaders() {
	colorProgram.compileShaders("../YOLO/shader/colorShadingVert.glsl",
		"../YOLO/shader/colorShadingFrag.glsl");
	colorProgram.addAttribute("vertexPosition");
	colorProgram.addAttribute("vertexColor");
	colorProgram.addAttribute("vertexUV");
	colorProgram.linkShaders();
}

void MainGame::calculateFPS() {
	static const int NUM_SAMPLES = 10;
	static float frameTimes[NUM_SAMPLES];

	static float prevTicks = SDL_GetTicks();

	static int currentFrame = 0;
	float currentTicks = SDL_GetTicks();
	frameTime = currentTicks - prevTicks;

	frameTimes[currentFrame % NUM_SAMPLES] = frameTime;

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
		fps = 1000.0f / frameTimeAverage;
	}
	else {
		fps = 60.0f;
	}
}

void MainGame::pauseMenu(int playerNum) {
	char choice;
	printf("PLAYER %d PAUSED\n", playerNum);
	while (gameState == GameState::PAUSE) {
		printf("What do you want to do?\nResume\tOptions\tQuit\n");
		std::cin >> choice;
		if (choice == 'r' || choice == 'R') {
			gameState = GameState::PLAY;
		}
		else if (choice == 'o' || choice == 'O') {
			std::cout << "(c) change your control" << std::endl;
			std::cout << "(e) eddit the level" << std::endl;
			std::cout << "(b) back to upper level" << std::endl;
			//options menu
			std::cin >> choice;
			if (choice == 'C' || choice == 'c') {
				printf("Set up your new controls: \n");
				printf("Enter in this order: Left, Right, Up (Jump), Down\n");
				int controlCount = 0;
				std::set<int> controlSet;
				int* newControls = new int[MAX_CONTROLS];
				SDL_Event evnt;
				while (controlCount < MAX_CONTROLS) {
					while (SDL_PollEvent(&evnt)) {
						if (evnt.key.type == SDL_KEYDOWN) {
							bool wasAdded = (controlSet.insert(evnt.key.keysym.sym)).second;
							if (wasAdded) {
								//key was not in the set already
								newControls[controlCount] = evnt.key.keysym.sym;
								controlCount++;
								printf("%s\t", SDL_GetKeyName(evnt.key.keysym.sym));
							}
						}
					}
				}
				printf("\nSaving Controls...\n");
				myStages_.stages[currentStage].players[playerNum - 1].setNewControls(newControls);
				printf("controls Saved\n");
			}
			else if (choice == 'E' || choice == 'e') {
				std::cout << "(a) Add level\n";
				std::cout << "(e) Eddit level\n";
				std::cout << "(c) Change level\n";
				std::cout << "(s) Save all your levels\n";
				std::cout << "(q) Quit level" << std::endl;
				std::cin >> choice;
				switch (choice) {
				case 'a':
					gameState = GameState::EDIT;
					myStages_.addNewStage(numberOfPlayers);
					currentStage = myStages_.getStageNumber();
					break;
				case 'e':
					std::cout << "Which level do you want to edit ? Max Level " <<
						myStages_.getStageNumber() << std::endl;
					unsigned int levelNumber;
					std::cin >> levelNumber;
					if (levelNumber > myStages_.getStageNumber()) {
						std::cout << "Not so many stages" << std::endl;
						gameState = GameState::EXIT;
					}
					else {
						gameState = GameState::EDIT;
						currentStage = levelNumber;
					}
					break;
				case 'c':
					std::cout << "Which level you can go to ? Max Level " <<
						myStages_.getStageNumber() << std::endl;
					std::cin >> currentStage;
					((AI*)comp)->setStage(&myStages_.stages[currentStage]);
					break;
				case 's':
					saveStages();
				break;
				case 'q':
					gameState = GameState::EXIT;
					break;
				}
			}
		}
		else if (choice == 'q' || choice == 'Q') {
			printf("Are you sure you want to quit?\tYes\tNo\n");
			std::cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				gameState = GameState::EXIT;
			}
		}
		else {
			printf("Invalid option, pick again.\n");
		}
	}
}
void MainGame::saveStages() {
	std::cout << "Saving all your levels" << std::endl;;
	std::ofstream ofs(myStages_.saveFileName_);
	if (!ofs.is_open()) {
		std::cout << "Failed to save your file" << std::endl;
	}
	boost::archive::text_oarchive oa (ofs);
	oa << myStages_;
	ofs.close();
}
void MainGame::loadStages(int playerNumber) {
	std::ifstream ifs(myStages_.saveFileName_);
	if (!ifs.is_open()) {
		myStages_.stages.reserve(20); // should be no more than 20 stages for now
		myStages_.addNewStage(playerNumber);
		myStages_.stages.back().setStage();
	}
	else {
		boost::archive::text_iarchive ia(ifs);
		ia >> myStages_;
		myStages_.stages.reserve(20); // should be no more than 20 stages for now
		for (auto &i : myStages_.stages) {
			i.initTextures();
			// one crashes, this is a hack
			i.init(playerNumber);
		}
	}
}
void MainGame::addObserverToAllStage(Observer* observer) {
	for (auto & s : myStages_.stages)
		for (auto & player : s.players)
			player.addObserver(observer);
}
void MainGame::drawHUD() {
	
	char buffer[1024];
	hudBatch_.begin();
	sprintf(buffer, "Halo");
	spriteFont_->draw(hudBatch_, buffer, glm::vec2(300, 300),
		glm::vec2(1.0), 0.0f, ColorRGBA8(255, 0, 0, 255), Justification::RIGHT);

	hudBatch_.end();
	hudBatch_.renderBatches();
}