#pragma once
#include "levels.h"
using namespace sf;

class Level6 :public Levels
{
public:
	Level6():Levels(15) {
		pathbg = "Images/background5.jpg";
	}
	virtual void draw(RenderWindow& window) {
		Levels::draw(window, "Images/inslevel3.jpg", "Level 6: HOW TO PLAY\n", "Objectives:\nDefend against zombies attacking from multiple lanes on the\n rooftop.\nplants like Cherry Bomb are Introduced, which can attack \nzombies in multiple lanes.");
	}
	virtual void introducezombies() {

	}
};