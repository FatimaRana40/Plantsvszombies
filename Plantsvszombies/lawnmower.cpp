#include"lawnmower.h"
#include<iostream>
using namespace std;
using namespace sf;
#include"SFML/Graphics.hpp"
//#include"Plants.h"

Lawnmower::Lawnmower()
{
	lawnMowertexture.loadFromFile("Images/car.png");
	lawnMowersprite.setTexture(lawnMowertexture);
	positionL = {120,250 };
	lawmowershootingbuffer.loadFromFile("audio/lawnmower.wav");
	 lawnmowersound.setBuffer(lawmowershootingbuffer);
	 move = false;

}
void Lawnmower::lawnmowermovement()
{
	if (move) {
		positionL.x += 5;
		if (positionL.x > 1200) {
			move = false;
		}
	}

	
}
void Lawnmower::drawlawnMower(sf::RenderWindow& window)
{
	lawnMowersprite.setPosition(positionL.x, positionL.y);
	window.draw(lawnMowersprite);
}
void Lawnmower::playsound()
{
//	lawnmowersound.play();
}
void Lawnmower:: setPosition(float x, float y)
{
	positionL.x = x;
	positionL.y = y;
}
void checkzombiemowercollsion(coordinates z)
{

}
void Lawnmower::setMove() {
	move = true;
	playsound();
}