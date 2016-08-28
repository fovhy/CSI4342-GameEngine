#include "log.h"

// for now there is only one log type
void log::logMessage(const std::string logString, logType aType,
	behavior aBehavior) {
	switch (aType) {
	case logType::error:
		if (!getInstance().hasErrorLog_) {
			getInstance().fileStreams_.push_back(
				std::make_shared<std::ofstream>(getInstance().errorLog_,
				std::ofstream::app));
			getInstance().hasErrorLog_ = true;
			getInstance().errorLogPos_ = getInstance().fileStreams_.size() - 1;
		}
		auto now = std::chrono::system_clock::now();
		std::time_t now_t = std::chrono::system_clock::to_time_t(now);
		(*getInstance().fileStreams_.at(getInstance().errorLogPos_)) <<
			std::ctime(&now_t) <<
			logString << std::endl;
		switch (aBehavior) {
		case behavior::exit:
			std::cout << "An error happened. Press any key to continue" << std::endl;
			char temp;
			std::cin >> temp;
			SDL_Quit();
			exit(1);
			break;
		}
		break;
	}

}
log::~log() {
	for (auto& stream : getInstance().fileStreams_) {
		stream->close();
	}
}