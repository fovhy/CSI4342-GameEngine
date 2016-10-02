#include "Error.h"

void printError(std::string error){
    std::cout << error << std::endl;
    std::cout << "Enter any key to quit..." << std::endl;
    int temp;
    std::cin >> temp;
    SDL_Quit();
    exit(1);
}
