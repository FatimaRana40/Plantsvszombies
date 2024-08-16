#pragma once
#include "Plants.h"


using namespace sf;
class sunflower :public Plants
{
protected:
	Sun sun;
	sf::Texture peaTextures[5];
	sf::Clock timer;
	int currentTextureIndex;
public:

	sunflower();
	void collect(Event& event,int& currency);
	virtual void update(); // Update method to handle sun production
	virtual void draw(sf::RenderWindow& window);
	virtual void ShootPea();
	virtual int getCurrency();
	bool isActive();
	virtual void displayplant(sf::RenderWindow& window);
	bool detectcollision(coordinates c)
	{
		return false;
	}

};
