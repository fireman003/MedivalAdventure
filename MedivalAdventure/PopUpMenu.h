#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#include "btn.h"
#include "StaticImage.h"
#include <vector>
#include <string>

using namespace sf;
using namespace std;





class PopUpMenu
{
public:
	PopUpMenu(Vector2f Pos, int size, Color Bg, Color Text, Color Arrow, string Items, Color Hover, int font, string bgPath); // every * mean new item

	void PopDraw(RenderWindow * window, bool show, bool opened);
private:
	vector<String> Item;
	vector<btn> buttons;
	RectangleShape rect;
	int selected = 0;
};

