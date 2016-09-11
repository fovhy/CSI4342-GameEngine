#include "Stage.h"



Stage::Stage()
{
	npcs_.push_back(Character());
	//npcs_[0].makeDefault();
}


Stage::~Stage()
{
}

std::vector<Character> Stage::getNPCs() {
	return npcs_;
}