
#pragma once
#ifndef HEADER_H
#define HEADER_H
#include "SFML/Graphics.hpp"
#include<iostream>
#include"SFML/Audio.hpp"
#include<string>
#include"lawnmower.h"
#include"weapon.h"
#include "sun.h"
#include "coordinates.h"
using namespace sf;
class Plants
{
protected:
	
	int health;
	coordinates positionP;
	int price;
	Sprite plantSprite;
	Texture plantTexture;


public:
	Plants();
	int n;
	bool isplacedongrid;
	bool plantdead;
	Plants(int h, coordinates c, int pr, Sprite ps, Texture pt);
	void  setPositionplant(float x, float y);
	coordinates getPosition();
	virtual void displayplant(sf::RenderWindow& window)=0;
	virtual int getCurrency() = 0;
	virtual void update() = 0;
	virtual void draw(sf::RenderWindow& window) = 0;
	//virtual bool isActive() = 0;
	virtual void ShootPea() = 0;
	virtual bool isActive() = 0; //for cherry 
	virtual void collect(Event& event, int& currency) = 0;
	virtual bool detectcollision(coordinates c)=0;
	int gethealth();
	void decrementhealth();
	virtual void movediagonal();
	virtual void setdiagonalmovement();
	virtual ~Plants() {

	}

};
#endif // HEADER_H