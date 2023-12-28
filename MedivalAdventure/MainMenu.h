#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "StaticImage.h"
#include "btn.h"
#include "Music.h"
#include "PopUpMenu.h"

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

	

};

