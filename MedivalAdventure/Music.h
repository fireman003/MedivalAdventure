#pragma once
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;

class MusicPlay
{
public:
	MusicPlay(int volume, String path, bool repeat) {
		music.openFromFile(path);
		music.setVolume(volume);
		music.setLoop(repeat);
	}
	void Play() {
		music.play();
	}
	void Stop() {
		music.stop();
	}

private:
	Music music;
};
