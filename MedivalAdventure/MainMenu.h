#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "StaticImage.h"
#include "btn.h"
#include "Music.h"
#include "SelectMenu.h"

using namespace sf;

class MainMenu
{
public:
	MainMenu(sf::RenderWindow* hwnd);

	int ReturnScrene();

private:
	int Scene;
	bool change = true;
	bool ShowOptions = true;
	std::vector<String> VolumeItems = { "Music Volume", "0%", "10%", "20%", "30%", "40%", "50%", "60%", "70%", "80%", "90%", "100%" };
	Font font;

};

