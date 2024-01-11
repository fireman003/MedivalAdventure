#include "MainMenu.h"


MainMenu::MainMenu(sf::RenderWindow *hwnd)
{

	//basic menu
	StaticImage background(Vector2f(0, 0), "assets/background.jpg");
	btn Play(Vector2f(640, 380), Color::Red, "Play", Color::White, 25, 1);
	btn Options(Vector2f(640, 460), Color::Red, "Options", Color::White, 25, 1);
	btn Exit(Vector2f(640, 540), Color::Red, "Exit", Color::White, 25, 1);
	MusicPlay music(50, "assets/ClaimYourWeapon.wav", true);
	

	//options
	StaticImage BgOptions(Vector2f(1920/2 - 1125/2, 1080/2 - 750/2), "assets/backroundOptions.jpg");
	btn CloseOptions(Vector2f(1920 / 2 + 1125 / 2 - 100, 1080 / 2 + 750 / 2 - 40), Color::Red, "Close", Color::White, 25, 1);
	//SelectMenu SoundVolume(Color::Red, Color::White, VolumeItems, Vector2f(1920 / 2 - 1125 / 2 + 120, 1080 / 2 - 750 / 2 + 120), 25, font, 20);

	music.Play();
	Event ev;	
	while (hwnd->isOpen() and change)
	{
		while (hwnd->pollEvent(ev))
		{
			switch (ev.type)
			{
			case Event::Closed:
				hwnd->close();
				break;
			}
		}
			//update
		if (ShowOptions)
		{
			if (Play.checkHover())
			{
				Scene = 2;
				change = false;
			}
			else if (Options.checkHover())
			{
				ShowOptions = false;
			}
			else if (Exit.checkHover())
			{
				hwnd->close();
			}
		}
		else
		{
			if (Keyboard::isKeyPressed(Keyboard::Escape))
			{
				ShowOptions = true;
			}
			if (CloseOptions.checkHover()) {
				ShowOptions = true;
			}
		}

			//draw
			hwnd->clear(Color::Black);
			background.Drawing(hwnd, true);
			BgOptions.Drawing(hwnd, !ShowOptions);
			Play.buttonDraw(hwnd, ShowOptions);
			Options.buttonDraw(hwnd, ShowOptions);
			Exit.buttonDraw(hwnd, ShowOptions);
			CloseOptions.buttonDraw(hwnd, !ShowOptions);
			//SoundVolume.DrawMenu(hwnd, !ShowOptions);
			hwnd->display();
		
	}
	music.Stop();
}

int MainMenu::ReturnScrene()
{
    return Scene;
}
