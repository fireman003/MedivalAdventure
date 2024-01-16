#include "Game.h"

int main() {
	LoadData data;
	data.InitFiles();
	Game game(1920, 1080, "Medival adventure" , true);
	game.SceneManager();
	return 0;
}

/*
	code structure:
		main		-window loading settings from files

		class Game	- scene switching
					- window handling
					- loading screen method

		MainMenu	-MainMenu for selecting play, setting, exit etc.
					-setting page with saving to file settings and changing settings
					-exit button to turn off

		WorldMap	-This page or scene is level selector
					- int this page you could see money and shop to spend money
					- operating with army
					- locking and unlocking lvl using saving in to file

		Utils		- load data from files
					- calculating delta time/elapsed time for movement etc.

		btn			- handling buttons create a text button with input and changing hover color 

		Music		- Handling music, loading from file, repeat, volume - handle play, stop.

		StaticImage - Handling static images like backgrounds etc.
					- set position and draw


*/