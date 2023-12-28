#pragma once

#include <SFML/Graphics.hpp>

#include "Music.h"
#include "btn.h"
#include "StaticImage.h"

using namespace sf;

class WorldMap
{
public:
	WorldMap(RenderWindow* hwnd);

	int returnScene() {
		return Scene;
	}
private:
	int Scene = 1;
	bool change = true;
};

