#include "WorldMap.h"

WorldMap::WorldMap(RenderWindow* hwnd)
{
	StaticImage background(Vector2f(0, 0), "assets/worldmap.jpg");
	MusicPlay music(50, "assets/worldmapsong.wav", true);
	StaticImage coin(Vector2f(1860, 50), "assets/coin.png");
	Font font; font.loadFromFile("assets/ModernAntiqua-Zw5K.ttf");
	btn CoinText(Vector2f(1800, 55), Color::White, "test", Color::White, 25, 1);
	ChainInit();

	Event ev;
	music.Play();
	while (hwnd->isOpen() and change)
	{
		while (hwnd->pollEvent(ev))
		{
			switch (ev.type) {
			case Event::Closed:
				hwnd->close();
			}
		}
		
		if (shop)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				shop = false;
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				change = false;
				Scene = 1;
			}
			if (true)
			{

			}
		}


		hwnd->clear(Color::Black);
		background.Drawing(hwnd, true);

		coin.Drawing(hwnd, !shop);
		CoinText.buttonDraw(hwnd, !shop);
		for (auto i : chains)
		{
			i.Drawing(hwnd, !shop);
		}



		hwnd->display();
	}
	music.Stop();

}
