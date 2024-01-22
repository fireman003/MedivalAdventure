#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include<windows.h>           // for windows
#include <iostream>

#include "Music.h"
#include "btn.h"
#include "StaticImage.h"
#include "LoadData.h"

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
	bool shop = false;
	vector<double> MyData;

	int money = 100;
	vector<StaticImage> GuiItems;
	vector<btn> GuiText;

	

	//std::vector<StaticImage> chains = { StaticImage(Vector2f(340, 350), "assets/cchain.png"), StaticImage(Vector2f(390, 775), "assets/cchain.png"), StaticImage(Vector2f(942, 510), "assets/cchain.png"), StaticImage(Vector2f(1575, 900), "assets/cchain.png") };

	//std::vector<Vector2f> chainPos = {Vector2f(340, 350), Vector2f(390, 775) , Vector2f(942, 510) , Vector2f(1575, 900)};
};

