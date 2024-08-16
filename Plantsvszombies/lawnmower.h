#pragma once
#ifndef LAWNMOWER_H
#define LAWNMOWER_H
#include<iostream>

#include"SFML/Audio.hpp"
#include"SFML/Graphics.hpp"
#include"Plants.h"
#include "coordinates.h"
using namespace sf;
struct coordinates1 {
	int x;
	int y;
};
class Lawnmower
{	private:
	bool move;
	Sprite lawnMowersprite;
	Texture lawnMowertexture;
	coordinates1 positionL;
	Sound lawnmowersound;
	SoundBuffer lawmowershootingbuffer;
public:
	Lawnmower();
	void lawnmowermovement();
	void setPosition(float x, float y);
	void setSpeed(int speed);
	void drawlawnMower(sf::RenderWindow& window);
	void playsound();
	coordinates1 getlawncoordinates()
	{
		return positionL;
	}
	void setMove();

};
#endif // LAWNMOWER_H