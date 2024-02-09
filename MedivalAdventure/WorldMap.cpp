#include "WorldMap.h"

WorldMap::WorldMap(RenderWindow* hwnd)
{
	StaticImage background(Vector2f(0, 0), "assets/worldmap.jpg");
	MusicPlay music(50, "assets/worldmapsong.wav", true);
	StaticImage coin(Vector2f(1860, 50), "assets/coin.png");
	Font font; font.loadFromFile("assets/ModernAntiqua-Zw5K.ttf");

	StaticImage ShopIcon(Vector2f(1760, 920), "assets/shop.png");
	StaticImage ShopBackround(Vector2f(1920 / 2 - 450, 1080 / 2 - 250), "assets/ShopBackground.png");
	btn CloseShop(Vector2f(1920 / 2 + 410, 1080 / 2 + 220), Color::White, "Close", Color::Red, 25, 1);
	//StaticImage UiBar(Vector2f(), "assets/UIdata.png");

	StaticImage ch1(Vector2f(340, 350), "assets/cchain.png");
	StaticImage ch2(Vector2f(390, 775), "assets/cchain.png");
	StaticImage ch3(Vector2f(942, 510), "assets/cchain.png");
	StaticImage ch4(Vector2f(1575, 900), "assets/cchain.png");
	StaticImage ch5(Vector2f(1593, 321), "assets/cchain.png");

	StaticImage GuiBar(Vector2f(1920 / 2 - 640, 75), "assets/UIdata.png"); GuiItems.push_back(GuiBar);

	StaticImage Archer(Vector2f(1920 / 2 - 490, 75), "assets/archery.png"); StaticImage Knight(Vector2f(1920 / 2 - 290, 75), "assets/sword.png"); StaticImage Horse(Vector2f(1920 / 2 - 90, 75), "assets/horse.png"); StaticImage Ship(Vector2f(1920 / 2 + 110, 75), "assets/ship.png"); StaticImage Wizard(Vector2f(1920 / 2 + 310, 75), "assets/witch-hat.png");
	GuiItems.push_back(Archer); GuiItems.push_back(Knight); GuiItems.push_back(Horse); GuiItems.push_back(Ship); GuiItems.push_back(Wizard);
	
	LoadData data; // money - level count - archer - knight - horse - ship - wizard
	MyData = data.readNumbersFromFile("assets/data.txt");
	
	money = MyData.at(0);

	btn CoinText(Vector2f(1800, 55), Color::White, std::to_string(static_cast<int>(MyData.at(0))), Color::White, 25, 1);

	for (int i = 2; i <= 6; i++) {
		GuiText.push_back(btn(Vector2f(400 + ((i-2) * 200), 82), Color::White, std::to_string(static_cast<int>(MyData.at(i))), Color::White, 25, 1));
	}

	Archer.changePosition(Vector2f(1920 / 2 - 300, 1080 / 2 - 225)); 
	Knight.changePosition(Vector2f(1920 / 2 - 300, 1080 / 2 - 125));
	Horse.changePosition(Vector2f(1920 / 2 - 300, 1080 / 2 - 25));
	Ship.changePosition(Vector2f(1920 / 2 - 300, 1080 / 2 + 75));
	Wizard.changePosition(Vector2f(1920 / 2 - 300, 1080 / 2 + 175));
	ShopItems.push_back(Archer); ShopItems.push_back(Knight); ShopItems.push_back(Horse); ShopItems.push_back(Ship); ShopItems.push_back(Wizard);

	btn archer(Vector2f(1920 / 2 - 100, 1080 / 2 - 228), Color::Red, "Click for buy - 35", Color::White, 25, 1);
	btn knight(Vector2f(1920 / 2 - 100, 1080 / 2 - 128), Color::Red, "Click for buy - 25", Color::White, 25, 1);
	btn horse(Vector2f(1920 / 2 - 100, 1080 / 2 - 28), Color::Red, "Click for buy - 40", Color::White, 25, 1);
	btn ship(Vector2f(1920 / 2 - 100, 1080 / 2 + 78), Color::Red, "Click for buy - 50", Color::White, 25, 1);
	btn wizard(Vector2f(1920 / 2 - 100, 1080 / 2 + 178), Color::Red, "Click for buy - 100", Color::White, 25, 1);

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
			if (archer.checkHover())
			{
				if (money >= 35) {
					money -= 35;
					GuiText.at(0).SetString(to_string(static_cast<int>(MyData.at(2) + 1)));
					MyData.at(2) += 1;
					CoinText.SetString(to_string(static_cast<int>(money)));
					Sleep(300);
				}
			}
			else if (knight.checkHover())
			{
				if (money >= 25) {
					money -= 25;
					GuiText.at(1).SetString(to_string(static_cast<int>(MyData.at(3) + 1)));
					MyData.at(3) += 1;
					CoinText.SetString(to_string(static_cast<int>(money)));
					Sleep(300);
				}
			}
			else if (horse.checkHover())
			{
				if (money >= 40) {
					money -= 40;
					GuiText.at(2).SetString(to_string(static_cast<int>(MyData.at(4) + 1)));
					MyData.at(4) += 1;
					CoinText.SetString(to_string(static_cast<int>(money)));
					Sleep(300);
				}
			}
			else if (ship.checkHover())
			{
				if (money >= 50)
				{
					money -= 50;
					GuiText.at(3).SetString(to_string(static_cast<int>(MyData.at(5) + 1)));
					MyData.at(5) += 1;
					CoinText.SetString(to_string(static_cast<int>(money)));
					Sleep(300);
				}
			}
			else if(wizard.checkHover())
			{
				if (money >= 100) {
					money -= 100;
					GuiText.at(4).SetString(to_string(static_cast<int>(MyData.at(6) + 1)));
					MyData.at(6) += 1;
					CoinText.SetString(to_string(static_cast<int>(money)));
					Sleep(300);
				}
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

			//working here
			if (MyData.at(1) == 1)
			{
				if (ch5.Click(hwnd))
				{
					change = false;
					Scene = 3;
				}
				else if (ch2.Click(hwnd))
				{
					change = false;
					Scene = 6;
				}
				else if(ch3.Click(hwnd))
				{
					change = false;
					Scene = 5;
				}
				else if (ch4.Click(hwnd)) {
					change = false;
					Scene = 4;
				}
			}
			else if (MyData.at(1) == 2) {
				if (ch5.Click(hwnd))
				{
					change = false;
					Scene = 3;
				}
				else if (ch3.Click(hwnd))
				{
					change = false;
					Scene = 5;
				}
				else if (ch4.Click(hwnd)) {
					change = false;
					Scene = 4;
				}
			}
			else if (MyData.at(1) == 3) {
				if (ch5.Click(hwnd))
				{
					change = false;
					Scene = 3;
				}
				else if (ch4.Click(hwnd)) {
					change = false;
					Scene = 4;
				}
			}
			else if (MyData.at(1) == 4) {
				if (ch5.Click(hwnd))
				{
					change = false;
					Scene = 3;
				}
			}
			else
			{
				if (ch5.Click(hwnd))
				{
					change = false;
					Scene = 3;
				}
				else if (ch1.Click(hwnd)) {
					change = false;
					Scene = 7;
				}
				else if (ch2.Click(hwnd))
				{
					change = false;
					Scene = 6;
				}
				else if (ch3.Click(hwnd))
				{
					change = false;
					Scene = 5;
				}
				else if (ch4.Click(hwnd)) {
					change = false;
					Scene = 4;
				}
			}
			//---------------------------------------
		}


		hwnd->clear(Color::Black);
		background.Drawing(hwnd, true);

		coin.Drawing(hwnd, true);
		CoinText.buttonDraw(hwnd, true);
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
		
		for (auto i : GuiItems)
		{
			i.Drawing(hwnd, true);
		}

		for (auto i : GuiText) {
			i.buttonDraw(hwnd, true);
		}

		for (auto i : ShopItems) {
			i.Drawing(hwnd, shop);
		}

		for (auto i : Prices) {
			i.buttonDraw(hwnd, shop);
		}

		knight.buttonDraw(hwnd, shop);
		horse.buttonDraw(hwnd, shop);
		archer.buttonDraw(hwnd, shop);
		wizard.buttonDraw(hwnd, shop);
		ship.buttonDraw(hwnd, shop);

		hwnd->display();
	}
	music.Stop();
	MyData.at(0) = money;
	data.write_vector_to_file(MyData, "assets/data.txt");
}
