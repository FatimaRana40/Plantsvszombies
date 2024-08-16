#include "Plants.h"
#include"SFML/Audio.hpp"
Plants::Plants()
{

}
Plants::Plants(int h, coordinates c, int pr, Sprite ps, Texture pt)
{
	health = h;
	positionP.x = c.x;
	positionP.y = c.y;
	price = pr;
	plantSprite = ps;
	plantTexture = pt;
	plantdead = false;

}
void Plants::setPositionplant(float x, float y) {
	positionP.x = x;
	positionP.y = y;
	plantSprite.setPosition(x, y);
}

coordinates Plants::getPosition() {
	return positionP;
}
int Plants::gethealth()
{
	return health;
}
void Plants::decrementhealth()
{
	health--;
	if (health <= 0)
		plantdead = true;

}
void Plants::movediagonal()
{
	
}

void Plants::setdiagonalmovement() {

}


