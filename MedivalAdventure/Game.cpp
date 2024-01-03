#include "Game.h"

int Game::StartingScreen()
{
	int x;
	logo.loadFromFile("assets/Logo.png");
	
	auto surface = VideoMode::getDesktopMode();

	SLogo.setTexture(logo);
	SLogo.setPosition(surface.width/2 - (256/2), surface.height / 2 - (256/2));

	for (x = 0; x < 254; x++)
	{
		loadScreen(x);
	}

	for (x = 254; x > 0; x--)
	{
		loadScreen(x);
	}

	return 1;
}

void Game::loadScreen(int x)
{
	Event ev;
	while (hwnd->pollEvent(ev))
	{
		switch (ev.type) {
		case Event::Closed:
			hwnd->close();
		}
	}

	SLogo.setColor(Color(255, 255, 255, x));

	hwnd->clear(Color::Black);

	hwnd->draw(SLogo);

	hwnd->display();

}

Game::Game(int Width, int height, String name, bool fullscreen)
{
	//create window
	if (fullscreen)
	{
		hwnd = new RenderWindow(VideoMode(height, Width), name, Style::Fullscreen);
	}
	else
	{
		hwnd = new RenderWindow(VideoMode(height, Width), name);
	}
	hwnd->setFramerateLimit(120);

}
