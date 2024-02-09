#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Music.h"


using namespace sf;

class ARMY
{
public:
	virtual int CheckRange() = 0;
	virtual void DragAround() = 0;
	virtual int GoTo() = 0;
	virtual Vector2f GetPos() = 0;
	virtual int Dying() = 0;
	
	bool selected;
	bool attacking;
	bool Follow;

private:
	Vector2f Pos;
	int HP;
	int Armor;
	int DMG;
	int Speed;
	CircleShape Range;
	Vector2f TargetPos;
	MusicPlay attackSound;
	virtual void UpdateRangeCircle() = 0;
};

