#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <iostream>
#include "MainMenu.h"
#include "WorldMap.h"

using namespace sf;

class Game
{
private:
	RenderWindow *hwnd;
	int Scene = 0;
	tgui::Gui *gui;

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

			case 3:
				cout << "Level 1" << endl;
				Scene = 1;
				break;
			case 4:
				cout << "Level 2" << endl;
			case 5:
				cout << "Level 3" << endl;
			case 6:
				cout << "Level 4" << endl;
			case 7:
				cout << "Level 5" << endl;
			}
		}
	}


	~Game() {
		delete hwnd;
		delete gui;
	}
protected:
};

