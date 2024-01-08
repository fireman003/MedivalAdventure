#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

class btn
{
public:
	btn(Vector2f Position, Color fillColor, String Txt, Color HoverColor, unsigned int FontSize, int font)
	{
		text.setString(Txt);
		text.setFillColor(HoverColor);
		HOverColor = HoverColor;
		text.setPosition(Position);
		text.setCharacterSize(FontSize);
		FillColor = fillColor;
		switch (font)
		{
		case 1:
			fon.loadFromFile("assets/ModernAntiqua-Zw5K.ttf");
			break;

		}
		text.setFont(fon);
	}



	void buttonDraw(RenderWindow* window, bool x) {
		if (x)
		{
			window->draw(text);
		}
	}

	bool checkHover()
	{
		Vector2i MousePos = Mouse::getPosition();

		if (MousePos.x > text.getGlobalBounds().left and MousePos.x < text.getGlobalBounds().left + text.getGlobalBounds().width and MousePos.y > text.getGlobalBounds().top && MousePos.y < text.getGlobalBounds().top + text.getGlobalBounds().height)
		{
			text.setFillColor(FillColor);
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				return true;
			}
		}
		else
		{
			text.setFillColor(HOverColor);
		}

		return false;
	}

	float Bounderies(bool down) {
		if (down) {
			return text.getGlobalBounds().width;
		}
		return text.getGlobalBounds().height;
	}

private:
	Text text;
	Color FillColor;
	Font fon;
	Color HOverColor;

};