#pragma once
#include"Plants.h"
class Wallnut :public Plants
{
private:
	int defensivebonus;
	coordinates Vertex[4];
	float rotationSpeed ; // Adjust this value to control the rotation speed
	float rotationAngle ;
	Texture walltextures[4];
	int currentIndex;
	Clock rotationTimer;
	bool diagonal;

public:
	Wallnut();
	bool direction;
	virtual void draw(sf::RenderWindow& window);
	virtual void update() ;
	virtual void ShootPea(); 
	virtual int getCurrency();//will do rotation 
	bool isActive();
	void collect(Event& event, int& currency);
	virtual void displayplant(sf::RenderWindow& window);
	bool detectcollision(coordinates c)
	{
		return false;
	}
	virtual void movediagonal();
	virtual void setdiagonalmovement();
};