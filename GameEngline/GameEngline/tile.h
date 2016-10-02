#pragma once
#include "glm/glm.hpp"
#include "UnmovableObject.h"

enum tilesType{
    GRASS,
    ICE,
    DIRT,
    POISON,
};

struct tile{
	UnmovableObject myTile;
	tile(glm::vec4& pos, tilesType aType) {
		myTile.setPosition(glm::vec2(pos.x, pos.y));
		myTile.setSize(glm::vec2(pos.z, pos.w));
		myTile.setColliSize(glm::vec2(pos.z, pos.w));
		type = aType;
	}
	tile() = default;

	void setTile(const glm::vec4& pos, tilesType aType) {
		myTile.setPosition(glm::vec2(pos.x, pos.y));
		myTile.setSize(glm::vec2(pos.z, pos.w));
		type = aType;
	}

	void setColliSize(const glm::vec2& size) {
		myTile.setColliSize(size);
	}

	void setType(tilesType aType) {
		type = aType;
	}

	glm::vec4 getPos() {
		return glm::vec4(myTile.getPosition(), myTile.getSize());
	}

	glm::vec2 getColliPosition() {
		return myTile.getColliSize();
	}

	float getFriction() {
		switch (type) {
		case GRASS:
			return 0.12;
			break;
		case ICE:
			return 0.04;
			break;
		case DIRT:
			return 0.14;
			break;
		case POISON:
			return 0.4;
			break;
		}
	}
	tilesType type;
};
