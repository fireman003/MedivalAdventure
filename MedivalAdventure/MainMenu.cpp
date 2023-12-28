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
	btn ExitOption(Vector2f(1920 / 2 + 1125 / 2 - 80, 1080 / 2 + 750 / 2 - 40), Color::Red, "Close", Color::White, 25, 1);
	//PopUpMenu WindowMod(Vector2f(380, 380), 25, Color::Black, Color::White, Color::White, "True*False", Color::Red, 1, "");
	//PopUpMenu volume();
	//PopUpMenu MaxFPS();


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
			if (ExitOption.checkHover())
			{
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
			ExitOption.buttonDraw(hwnd, !ShowOptions);
			//WindowMod.PopDraw(hwnd, !ShowOptions, false);

			hwnd->display();
		
	}
	music.Stop();
}

int MainMenu::ReturnScrene()
{
    return Scene;
}
