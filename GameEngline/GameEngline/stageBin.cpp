#include "stageBin.h"



StageBin::StageBin()
{
}


StageBin::~StageBin()
{
}

int StageBin::getStageNumber() const {
	return stages.size() - 1;
}

void StageBin::addNewStage() {
	stages.push_back(Stage());
	stages.back().initTextures();
	stages.back().init();
}
void StageBin::init() {
}
std::ostream& operator<< (std::ostream& os, const StageBin &sb) {
	for (auto itr = sb.stages.begin(); itr != sb.stages.end(); itr++) {
		os << *itr;
	}
	return os;
}
