#pragma once
#include "Character.h"

class Bald : public Character{
public:
    void init();
    void spawnAttackBox(const glm::vec2& pos, int direction);
    void spawnSpecialAttackBox(const glm::vec2& pos, int direction);
private:
    void drawSpecialAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
};
