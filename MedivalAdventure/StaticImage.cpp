#include "StaticImage.h"

StaticImage::StaticImage(Vector2f Pos, String path)
{
	texture.loadFromFile(path);

	sprite.setTexture(texture);
	sprite.setPosition(Pos);
	Arrow.loadFromSystem(Cursor::Arrow);
	Hand.loadFromSystem(Cursor::Hand);
}

void StaticImage::Drawing(RenderWindow* hwnd, bool Show)
{
	if (Show) {
		hwnd->draw(sprite);
	}
}

void StaticImage::Alpha(int x)
{
	sprite.setColor(Color(255, 255, 255, x));
}

void StaticImage::changePosition(Vector2f Pos)
{
	sprite.setPosition(Pos);
}