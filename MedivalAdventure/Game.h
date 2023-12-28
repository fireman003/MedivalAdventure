#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
#include "WorldMap.h"

using namespace sf;

class Game
{
private:
	RenderWindow *hwnd;
	int Scene = 0;
	

	int StartingScreen();
	void loadScreen(int x);
	Texture logo;
	Sprite SLogo;
public:
	Game(int Width, int height, String name, bool fullscreen);

	void SceneManager() {
		while(hwnd->isOpen())
		{
			switch (Scene) {
			case 0:
				Scene = StartingScreen();
				break;
			case 1:{
				MainMenu menu(hwnd);
				Scene = menu.ReturnScrene();
			}
				break;
			case 2: {
				WorldMap map(hwnd);
				Scene = map.returnScene(); }
				break;
			}
		}
	}


	~Game() {
		delete hwnd;
	}
protected:
};

