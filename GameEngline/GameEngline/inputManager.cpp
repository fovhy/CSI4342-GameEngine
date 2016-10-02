#include "inputManager.h"

void inputManager::pressKey(unsigned int keyID){
    keyMap_[keyID] = true;
}

void inputManager::releaseKey(unsigned int keyID){
    keyMap_[keyID] = false;
}

bool inputManager::isKeyPressed(unsigned int keyID){
    auto it = keyMap_.find(keyID);
    if(it != keyMap_.end()){
        return it->second;
    }else
        return false;
}
