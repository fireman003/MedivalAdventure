#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

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
		for (auto i : chainPos)
		{
			chains.push_back(StaticImage(i,"assets/chain.png"));
		}
	};

	int money = 100;

	std::vector<StaticImage> chains;

	std::vector<Vector2f> chainPos = {Vector2f(1550, 360), Vector2f(1510, 980) , Vector2f(940, 530) , Vector2f(907, 917)};
};

