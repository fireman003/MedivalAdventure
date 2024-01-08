#pragma once

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

class StaticImage
{
public:
	StaticImage(Vector2f Pos, String path);
	void Drawing(RenderWindow *hwnd, bool Show);

	void Alpha(int x);
	void changePosition(Vector2f Pos);
	bool Click(RenderWindow* hwnd) {
		if (sprite.getGlobalBounds().left <= Mouse::getPosition().x and sprite.getGlobalBounds().top >= Mouse::getPosition().y and sprite.getGlobalBounds().top + sprite.getGlobalBounds().height >= Mouse::getPosition().y and sprite.getGlobalBounds().left + sprite.getGlobalBounds().width >= Mouse::getPosition().x)
		{
			return true;
		}

		return false;
	}

private:
	Texture texture;
	Sprite sprite;
};

