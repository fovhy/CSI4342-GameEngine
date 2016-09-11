#pragma once
#include "glm/glm.hpp"

enum tilesType{
    GRASS,
    ICE,
    DIRT,
    POISON,
    BLANK
};

struct tile{
    int x = 0;  // x position
    int y = 0;  // y position
    int width = 0;
    int height = 0;

    void setTile(const glm::vec4& pos, tilesType aType){
        x = pos.x;
        y = pos.y;
        width = pos.z;
        height = pos.w;
        type = aType;
    }

    void setType(tilesType aType){
        type = aType;
    }

    glm::vec4 getPos(){
        return glm::vec4(x, y, width, height);
    }

    float getFriction(){
        switch (type) {
        case GRASS:
            return 0.05;
            break;
        case ICE:
            return 0.01;
            break;
        case DIRT:
            return 0.1;
            break;
        case POISON:
            return 0.4;
            break;
        }
    }

    tilesType type;

};
