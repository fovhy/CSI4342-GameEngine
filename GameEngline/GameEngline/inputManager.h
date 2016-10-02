#pragma once
#include <unordered_map>

class inputManager{
public:
    inputManager(){}
    ~inputManager(){}

    void pressKey(unsigned int keyID);
    void releaseKey(unsigned int keyID);

    bool isKeyPressed(unsigned int keyID);

private:
    bool keyPressed_ = false;
    std::unordered_map<unsigned int, bool> keyMap_;
};
