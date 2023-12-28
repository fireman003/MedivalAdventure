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

private:
	Texture texture;
	Sprite sprite;
};

