#pragma once
#include "Stage.h"
/*
hopefully stores and manage all the stages
*/
class StageBin{
public:
	friend class boost::serialization::access;
	friend inline std::ostream& operator<< (std::ostream& os, const StageBin &sb);
	StageBin();
	~StageBin();
	int getStageNumber() const;
	void init();
	void addNewStage(int playerNumber);
	template<class Archive>
	inline void serialize(Archive & ar, const unsigned int version) {
		ar & stages;
	}
	std::vector<Stage> stages;
	const std::string saveFileName_ = "stage.txt";
};


