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
		Vector2i MousePos = Mouse::getPosition();
		if (MousePos.x > sprite.getGlobalBounds().left and MousePos.x < sprite.getGlobalBounds().left + sprite.getGlobalBounds().width and MousePos.y > sprite.getGlobalBounds().top && MousePos.y < sprite.getGlobalBounds().top + sprite.getGlobalBounds().height)
		{
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				return true;
			}			
		}
		

		return false;
	}

private:

	Texture texture;
	Sprite sprite;

};

