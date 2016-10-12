#include "AudioManager.h"
#include "EventManager.h"
#include "Error.h"



AudioManager::~AudioManager(){
	for (auto& itr : effectMap_) {
		Mix_FreeChunk(itr.second);
	}
	for (auto& itr : musicMap_) {
		Mix_FreeMusic(itr.second);
	}
	Mix_CloseAudio();
}
void AudioManager::init() {
	//add all the needed sound effect here
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1) {
		printError("Failed to initilize the audio");
	}
	addMuisc("../YOLO/sounds/Music/Dragonborn.mp3");
	addEffect("../YOLO/sounds/Effect/death.wav");
	bindEffect("playerDeath", "../YOLO/sounds/Effect/death.wav");
	bindMusic("gameStart", "../YOLO/sounds/Music/Dragonborn.mp3");
}
void AudioManager::pauseAll() {
	Mix_Pause(-1);
	Mix_PauseMusic();
}
void AudioManager::pauseSoundEffect(int channel) {
	Mix_Pause(channel);
}
void AudioManager::resume(int channel) {
	Mix_Resume(channel);
}
void AudioManager::pauseMusic() {
	Mix_PauseMusic();
}
void AudioManager::resumeMusic() {
	Mix_ResumeMusic();
}
void AudioManager::setMusicVolumn(int level) {
	Mix_VolumeMusic(level);
}
void AudioManager::setEffectVolumn(int channel, int level) {
	Mix_Volume(channel, level);
}


void AudioManager::addEffect(const std::string& soundName) {
	Mix_Chunk* temp = Mix_LoadWAV(soundName.c_str());
	if (temp == nullptr) {
		printError("Failed to load sound effect " + soundName);
	}
	effectMap_.emplace(soundName, temp);
}
void AudioManager::addMuisc(const std::string& soundName) {
	Mix_Music* temp = Mix_LoadMUS(soundName.c_str());
	if (temp == nullptr) {
		printError("Failed to load music " + soundName);
	}
	musicMap_.emplace(soundName, temp);
}
void AudioManager::removeEffect(const std::string& soundName) {
	effectMap_.erase(soundName);
}
void AudioManager::removeAllEffect() {
	effectMap_.clear();
}
void AudioManager::removeAllMusic() {
	musicMap_.clear();
}
void AudioManager::removeMusic(const std::string& soundName) {
	musicMap_.erase(soundName);
}

Mix_Chunk* AudioManager::getEffect(const std::string& soundName){
	auto temp = effectMap_.find(soundName);
	if (temp == effectMap_.end()) {
		return nullptr;
	}
	else {
		return temp->second;
	}
	
}

void AudioManager::playEffect(int channel, const std::string& fileName, int loops) {
	Mix_PlayChannel(channel, getEffect(fileName), loops);
}

Mix_Music* AudioManager::getMusic(const std::string& soundName) {
	auto temp = musicMap_.find(soundName);
	if (temp == musicMap_.end()) {
		return nullptr;
	}
	return temp->second;
}
void AudioManager::playMusic(const std::string& musicName, int loops) {
	Mix_PlayMusic(getMusic(musicName), loops);
}
void AudioManager::playMusicFadeIn(const std::string&, int loops, int ms) {

}
void AudioManager::playMusicFadeOut(int ms) {

}
bool AudioManager::musicExisit(std::string musicName) const{
	return musicMap_.find(musicName) != musicMap_.end();
}

bool AudioManager::effectExist(std::string effectName) const{
	return effectMap_.find(effectName) != effectMap_.end();
}

void AudioManager::bindEffect(const std::string& eventName, const std::string& effectName) {
	if (effectExist(effectName) && EventManager::getEventManager().eventExist(eventName)) {
		eventMap_.emplace(eventName, effectName);
	}
	else {
		printError("cannot bind " + eventName + " event with " + effectName + " effect.");
	}
}

void AudioManager::bindMusic(const std::string& eventName, const std::string& musicName) {
	if (musicExisit(musicName) && EventManager::getEventManager().eventExist(eventName)) {
		eventMap_.emplace(eventName, musicName);
	}
	else {
		printError("cannot bind " + eventName + " event with " + musicName + " Music.");
	}
}
std::string AudioManager::getSoundName(const std::string& eventName) {
	auto temp = eventMap_.find(eventName);
	if (temp == eventMap_.end()) {
		return "";
	}
	else {
		return temp->second;
	}
}

void AudioManager::playEffectTimed(const std::string& effectName, int channel, int loops, int ms) {
	Mix_PlayChannelTimed(channel, getEffect(getSoundName(effectName)), loops, ms);
}
void AudioManager::playMusicTimed(const std::string& musicName, int loop, int ms) {

}

void AudioManager::playSoundFromEvent(const std::string& eventName, int loops, int ms) {
	std::string soundName = getSoundName(eventName);
	if (soundName == "") {
		printError("No such event in the audioManager");
	}
	auto effect = getEffect(soundName);
	if (effect != nullptr) {
		if (ms = -1) {
			playEffect(2, soundName, loops);
		}
		else {
			playEffectTimed(soundName, 2, loops, ms);
		}
	}else {
		auto music = getMusic(soundName);
		if (music != nullptr) {
			playMusic(soundName, loops);
			std::cout << " played music" << std::endl;
		}
		else {
			printError("cannot play music");
		}
	}
}

void AudioManager::onNotify(const Subject& subject, Event event) {
	switch (subject.getType()) {
		//TODO: make this actually mean something
	case type::CHARACTER:
		playSoundFromEvent(event.eventName, 0, -1);          // TODO: add sound event and other events to event manager
		break;
	case type::MAINGAME:
		playSoundFromEvent(event.eventName, -1, -1);
		break;
	case type::PLAYER:
		playSoundFromEvent(event.eventName, 0, -1);
		break;
	}
}