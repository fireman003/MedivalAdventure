#include "WorldMap.h"

WorldMap::WorldMap(RenderWindow* hwnd)
{
	StaticImage background(Vector2f(0, 0), "assets/worldmap.jpg");
	MusicPlay music(50, "assets/worldmapsong.wav", true);
	StaticImage coin(Vector2f(1860, 50), "assets/coin");
	btn CoinText(Vector2f(1800, 50), );

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

		for (auto i : chains)
		{
			i.Drawing(hwnd, true);
		}


		hwnd->display();
	}
	music.Stop();

}
