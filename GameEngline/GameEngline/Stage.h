#pragma once
#include <glm/glm.hpp>
#include <glm/vec3.hpp>
#include "Character.h"
/*
Stage is a class that host muliple objects. It holds enemy types, players and stuff. It holds all the data
is needed for the main game to render. 

Author: Dean He 
Date: 9/8/2016
*/
class Stage
{
public:
	glm::vec3 it;
	Stage();
	~Stage();
	std::vector<Character> getNPCs();
private:
	std::vector<Character> npcs_;
	
};

