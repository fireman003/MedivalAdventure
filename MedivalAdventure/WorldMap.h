#pragma once

#include <SFML/Graphics.hpp>

#include <vector>
#include<windows.h>           // for windows
#include <iostream>

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
	bool shop = false;

	void ChainInit() {
		for (int i = 0; i < chains.size(); i++)
		{
			chains.push_back(StaticImage(chainPos.at(i), "assets/chain.png"));
		}
	};

	int money = 100;

	std::vector<StaticImage> chains;

	std::vector<Vector2f> chainPos = {Vector2f(340, 350), Vector2f(390, 775) , Vector2f(942, 510) , Vector2f(1575, 900)};
};

