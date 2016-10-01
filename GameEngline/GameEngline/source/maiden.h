#pragma once
#include "Character.h"

class Maiden : public Character{
public:
    void init();
    void spawnSpecialAttackBox(const glm::vec2& pos, int direction);
private:
    void drawSpecialAttack(int direction,SpriteBatch& spriteBatch) override;
};
