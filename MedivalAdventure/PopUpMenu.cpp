#include "PopUpMenu.h"

PopUpMenu::PopUpMenu(Vector2f Pos, int size, Color Bg, Color Text, Color Arrow, string Items, Color Hover, int font, string bgPath)
{
	//separate items in to vector
	string delimiter = "*";
	size_t pos = 0;
	while ((pos = Items.find(delimiter)) != std::string::npos) {
		Item.push_back(Items.substr(0, pos));
		Items.erase(0, pos + delimiter.length());
	}

	for (auto x : Item)
	{
		btn button(Pos, Text, x, Hover, size, font);
		Pos.y += size * 1.6;
		buttons.push_back(button);
	}
	
	rect = RectangleShape(Vector2f(buttons.at(0).Bounderies(false), buttons.at(0).Bounderies(true)));
	rect.setFillColor(Bg);


	if (bgPath != "") {
		Texture *texure{};
		texure->loadFromFile(bgPath);
		rect.setTexture(texure);
		delete texure;
	}

	
}

void PopUpMenu::PopDraw(RenderWindow* window, bool show, bool opened)
{
	
	if (opened and show) {

	}
	else if (show)
	{
		window->draw(rect);
		buttons.at(selected).buttonDraw(window, true);
	}
}
