#pragma once
//#include "SFML/Graphics.hpp"
//#include<iostream>
//using namespace sf;
//struct coordinates2
//{
//	int x;
//	int y;
//};
//class Sun
//{
//protected:
//	Sprite sunsprite;
//	Texture suntexture;
//	coordinates2 positionS;
//	sf::Clock appearanceTimer; // Timer to control sun appearance
//	bool isActivev;
//
//public:
//	Sun();
//	void sunmovement(float s);
//	void setPosition(float x, float y);
//	void setSpeed(int speed);
//	void drawSun(sf::RenderWindow& window);
//	void setActive(bool active);
//	bool isActive();
//	void update();
//};
#include "SFML/Graphics.hpp"
#include<iostream>
using namespace sf;
struct coordinates2
{
	int x;
	int y;
};
class Sun
{
protected:
	Sprite sunsprite;
	Texture suntexture;
	coordinates2 positionS;
	sf::Clock appearanceTimer; // Timer to control sun appearance
	bool isActivev;

public:
	Sun();
	void setPosition(float x, float y);
	void drawSun(sf::RenderWindow& window);
	void update();
	void collectsuns(Event event,int& currency);
	Clock getTime();
	void setActive(bool set);
};
