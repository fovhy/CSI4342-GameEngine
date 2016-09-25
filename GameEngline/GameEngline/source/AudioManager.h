/*
sound effect should be WAVE files, and music can be WAVE MOD MIDL OGG MP3 FLAC format 
*/
#pragma once
#include <string>
#include <unordered_map>
#include <SDL\SDL_mixer.h>
class AudioManager
{
public:
	void init(); // init sdl2_mixer
	void pauseAll(); // pause all audio being playing
	void pauseSoundEffect(int channel);//pause a specific channel, it is for sound effect not music
	void resume(int channel); // resume a specific channel
	void pauseMusic();
	void resumeMusic();
	void setMusicVolumn(int level);  // set volumn level for music(max is 128)

	void addEffect(std::string); // add effect to the effect map
	void addMuisc(std::string); // add music to the muisc map
	void removeEffect(std::string);
	void removeAllEffect();
	void removeAllMusic();
	void removeMusic(std::string);

	void playEffect(int channel, std::string fileName, int loops);
	void playMusic(std::string, int loops);
	void playMusicFadeIn(std::string, int loops, int ms);
	void playMusicFadeOut(int ms);
	AudioManager();
	~AudioManager();
private:
	std::unordered_map<std::string, Mix_Chunk*> effectMap_;
	std::unordered_map<std::string, Mix_Music*> musicMap_;
};

