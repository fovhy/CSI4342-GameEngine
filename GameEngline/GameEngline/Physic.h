#pragma once
#include <glm/glm.hpp>

class Physic{
public:
    static bool checkCollisions(const glm::vec4& firstItem, const glm::vec4& secondItem);

    //this will only be used on player and tile collision detection
    static bool checkTileCollisions(const glm::vec4& playerPos, const glm::vec4 & tilePos);

// speed can be positive and negative, friction alwasy gonna be positive
    static void applyFriction(float &speed, float friction);

    const float gravity = 0.2;

};
