#include "Plants.h"
#include "wallnut.h"
#include<cmath>

#define M_PI 3.14159265358979323846

	Wallnut::Wallnut()
	{	
		diagonal = false;
		direction = false;
		defensivebonus = 10;
		health = 30;
		positionP.x = 194;
		positionP.y = 0;
		price = 50;
		n = 2;
		//plantTexture.loadFromFile("Images/wall1.png");
		//plantSprite.setTexture(plantTexture);
		walltextures[0].loadFromFile("Images/wallnut/wall1.png");
		walltextures[1].loadFromFile("Images/wallnut/wallnut90.png");
		walltextures[2].loadFromFile("Images/wallnut/wallnut180.png");
		walltextures[3].loadFromFile("Images/wallnut/wallnut270.png");

		plantSprite.setPosition(210, 210);
        rotationSpeed = 0.1f;
            rotationAngle = 0.0f;
            currentIndex = 0;
			isplacedongrid = false;
			plantSprite.setTexture(walltextures[0]);
			plantdead = false;
	}
	void Wallnut::draw(sf::RenderWindow& window) {
		plantSprite.setPosition(positionP.x, positionP.y);
		window.draw(plantSprite);
	}

	void Wallnut::update() {

		if (isplacedongrid)
		{
			if (rotationTimer.getElapsedTime().asSeconds() >= 0.1f) {
				rotationTimer.restart();
				currentIndex = (currentIndex + 1) % 4;
				plantSprite.setTexture(walltextures[currentIndex]);
			}
			positionP.x += 5;
			//positionP.y += 5;

		}
	}
	void Wallnut::movediagonal()
	{
		if (diagonal) {


			if (direction == true) {
				positionP.y += 5;
				//std::cout << "going down ";
			}
			else {
				positionP.y -= 5;
				//std::cout << "going up";
			}
			if (positionP.x > 1200) {
				diagonal = false;
			}
		}
	}
	void Wallnut::setdiagonalmovement()
	{
		diagonal = true;
		direction = !direction;
	}


    void Wallnut::ShootPea() {
        
    }
	
	int Wallnut::getCurrency()
	{
		return price;
	}

	bool Wallnut::isActive()
	{
		return true;
	}
	void Wallnut::collect(Event& event, int& currency)
	{

	}
	void Wallnut::displayplant(sf::RenderWindow& window) {
		plantSprite.setPosition(positionP.x, positionP.y);
		window.draw(plantSprite);
	}
