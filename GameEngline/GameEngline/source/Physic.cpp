#include "Physic.h"
#include <iostream>

bool Physic::checkCollisions(const glm::vec4 &firstItem, const glm::vec4 &secondItem){
    bool collisionX = firstItem.x + firstItem.z > secondItem.x &&
            secondItem.x + secondItem.z > firstItem.x;

    bool collisionY = firstItem.y + firstItem.w > secondItem.y &&
            secondItem.y + secondItem.w > firstItem.y;

    return collisionX && collisionY;
}

bool Physic::checkTileCollisions(const glm::vec4 &playerPos, const glm::vec4 &tilePos){
    bool onTile = playerPos.x + playerPos.z - playerPos.z/3 > tilePos.x
            && playerPos.x < tilePos.x + tilePos.z - playerPos.z/3;
    bool collisionY = playerPos.y <= tilePos.y + tilePos.w && playerPos.y >= tilePos.y;
    return onTile && collisionY;
}

void Physic::applyFriction(float& speed, float friction){
    if(speed > 0){
        if(speed > friction){
            speed -= friction;
        }else
            speed = 0;
    }else{
        if(speed < -friction){
            speed += friction;
        }else
            speed = 0;
    }
}

