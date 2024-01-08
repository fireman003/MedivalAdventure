#pragma once

#include <SFML/Graphics.hpp>
#include "btn.h"

#include <string>

using namespace sf;

class SelectMenu
{
public:
	SelectMenu(Color FillColor, Color BaseColor, std::vector<String> items, Vector2f Pos, int Size, Font Font, int offset) {
		btn L(Vector2f(Pos.x - offset, Pos.y), FillColor, "<", BaseColor, Size, Font);
		btn R(Vector2f(Pos.x + offset, Pos.y), FillColor, ">", BaseColor, Size, Font);

		btn I(Vector2f(Pos.x - offset + 10, Pos.y), BaseColor, items.at(1), BaseColor, Size, Font);
		btn T(Vector2f(Pos.x - offset - 20, Pos.y), BaseColor, items.at(0), BaseColor, Size, Font);

		L.SetText("Hello, world");

		S.push_back(L); S.push_back(R); S.push_back(I); S.push_back(T);
	}

	void UpdateMenu() {

	}

	void DrawMenu(RenderWindow* hwnd, bool x) {
		S.at(0).buttonDraw(hwnd, x);
		//S.at(1).buttonDraw(hwnd, x);
		//S.at(2).buttonDraw(hwnd, x);
		//S.at(3).buttonDraw(hwnd, x);
	}

private:
	std::vector<btn> S;

};

