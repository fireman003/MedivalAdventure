#include "WorldMap.h"

WorldMap::WorldMap(RenderWindow* hwnd)
{
	StaticImage background(Vector2f(0, 0), "assets/worldmap.jpg");
	MusicPlay music(50, "assets/worldmapsong.wav", true);
	StaticImage coin(Vector2f(1860, 50), "assets/coin.png");
	Font font; font.loadFromFile("assets/ModernAntiqua-Zw5K.ttf");
	btn CoinText(Vector2f(1800, 55), Color::White, std::to_string(money), Color::White, 25, 1);
	StaticImage ShopIcon(Vector2f(1760, 920), "assets/shop.png");
	StaticImage ShopBackround(Vector2f(1920 / 2 - 450, 1080 / 2 - 250), "assets/ShopBackground.png");
	btn CloseShop(Vector2f(1920 / 2 + 410, 1080 / 2 + 220), Color::White, "Close", Color::Red, 25, 1);
	StaticImage UiBar(Vector2f(), "assets/UIdata.png");

	StaticImage ch1(Vector2f(340, 350), "assets/cchain.png");
	StaticImage ch2(Vector2f(390, 775), "assets/cchain.png");
	StaticImage ch3(Vector2f(942, 510), "assets/cchain.png");
	StaticImage ch4(Vector2f(1575, 900), "assets/cchain.png");

	LoadData data;

	MyData = data.readNumbersFromFile("assets/data.txt");


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
				Sleep(200);
			}
		}
		else {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				change = false;
				Scene = 1;
			}
			else if (ShopIcon.Click(hwnd))
			{
				shop = true;
			}
		}


		hwnd->clear(Color::Black);
		background.Drawing(hwnd, true);

		coin.Drawing(hwnd, !shop);
		CoinText.buttonDraw(hwnd, !shop);
		if (MyData.at(1) == 1)
		{
			ch1.Drawing(hwnd, !shop);
		}
		else if (MyData.at(1) == 2) {
			ch1.Drawing(hwnd, !shop);
			ch2.Drawing(hwnd, !shop);
		}
		else if (MyData.at(1) == 3) {
			ch3.Drawing(hwnd, !shop);
			ch2.Drawing(hwnd, !shop);
			ch1.Drawing(hwnd, !shop);
		}
		else if (MyData.at(1) == 4) {
			ch3.Drawing(hwnd, !shop);
			ch4.Drawing(hwnd, !shop);
			ch1.Drawing(hwnd, !shop);
			ch2.Drawing(hwnd, !shop);
		}

		ShopIcon.Drawing(hwnd, !shop);

		ShopBackround.Drawing(hwnd, shop);

		hwnd->display();
	}
	music.Stop();

}
