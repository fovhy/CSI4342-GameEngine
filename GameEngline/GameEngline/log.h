/*
Description: This logger is able to record any kind of logs in the game. It uses a singleton
	design pattern with lazy initialzation. The logger will be able have different behaivor and
	log to differnet files based on the user's need. For now the file it logs to is hard coded.

Author: Dean He
*/
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <chrono>
#include <ctime>
#include <memory>

using UN32 = unsigned int;
template <typename T>
using s_ptr = std::shared_ptr<T>;
enum class logType { // the kind of log you want to make, for now it only has error type
	error
};
enum class behavior { // the kind of behavior you want to perform after a log is done.
	exit,
	go_on
};
class log
{
public:
	static log& getInstance() {
		static log instance;
		return instance;
	}
	static void logMessage(const std::string logString,
		logType aType,
		behavior aBehavior = behavior::exit);
	~log();
private:
	log() {};
	log(log const&) = delete;
	void operator=(log const&) = delete;
    std::vector<s_ptr<std::ofstream>> fileStreams_;
	bool hasErrorLog_ = false;
	UN32 errorLogPos_ = 0;
	std::string errorLog_ = "errorLog.txt"; // hard coded filename
};

