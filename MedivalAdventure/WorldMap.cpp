#include "WorldMap.h"

WorldMap::WorldMap(RenderWindow* hwnd)
{
	StaticImage background(Vector2f(0, 0), "assets/worldmap.jpg");
	MusicPlay music(50, "assets/worldmapsong.wav", true);

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
		
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			change = false;
			Scene = 1;
		}


		hwnd->clear(Color::Black);
		background.Drawing(hwnd, true);



		hwnd->display();
	}
	music.Stop();

}
