#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace sf;

class btn
{
public:
	btn(Vector2f Position, Color fillColor, String Txt, Color HoverColor, unsigned int FontSize, Font font)
	{
		text.setString(Txt);
		text.setFillColor(HoverColor);
		HOverColor = HoverColor;
		text.setPosition(Position);
		text.setCharacterSize(FontSize);
		FillColor = fillColor;
		text.setFont(font);
	}

	

	void buttonDraw(RenderWindow *window, bool x) {
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

	void SetText(String txt) {
		text.setString(txt);
	}

private:
	Text text;
	Color FillColor;
	Color HOverColor;
	
};

