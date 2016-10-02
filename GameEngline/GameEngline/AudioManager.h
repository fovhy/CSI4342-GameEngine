/*
sound effect should be WAVE files, and music can be WAVE MOD MIDL OGG MP3 FLAC format 
*/
#pragma once
#include <string>
#include "Observer.h"
#include "Subject.h"
#include <unordered_map>
#include <SDL\SDL_mixer.h>
#include "Event.h"
class AudioManager : public Observer{
public:
	void init(); // init sdl2_mixer
	void pauseAll(); // pause all audio being playing
	void pauseSoundEffect(int channel);//pause a specific channel, it is for sound effect not music
	void resume(int channel); // resume a specific channel
	void pauseMusic();
	void resumeMusic();
	void setMusicVolumn(int level);  // set volumn level for music(max is 128)

	void addEffect(const std::string&); // add effect to the effect map
	void addMuisc(const std::string&); // add music to the muisc map
	void removeEffect(const std::string&);
	void removeAllEffect();
	void removeAllMusic();
	void removeMusic(const std::string&);

	void playEffect(int channel, const std::string& fileName, int loops);
	void playMusicFadeIn(const std::string&, int loops, int ms);
	void playMusicFadeOut(int ms);

	bool musicExisit(const std::string musicName) const;
	bool effectExist(const std::string effectName) const;
	void bindMusic(const std::string& eventName, const std::string& musicName);
	void bindEffect(const std::string& eventName, const std::string& effectName);
	void playMusic(const std::string& musicName, int loops);
	/*
	specify ms to -1 if you do not want to cut it
	*/
	void playSoundFromEvent(const std::string& eventName, int loops, int ms); 

	void playEffectTimed(const std::string& effectName, int channel, int loops, int ms);
	void playMusicTimed(const std::string& musicName, int loops, int ms);

	Mix_Chunk* getEffect(const std::string& soundName);
	Mix_Music* getMusic(const std::string& soundName);

	std::string getSoundName(const std::string& eventName);

	void setEffectVolumn(int channel , int volumn); // 128 is the max
	void onNotify(const Subject& subject, Event event) override;
	AudioManager() = default;
	~AudioManager();
private:
	std::unordered_map<std::string, Mix_Chunk*> effectMap_;
	std::unordered_map<std::string, Mix_Music*> musicMap_;
	std::unordered_map <std::string, std::string> eventMap_;
};

