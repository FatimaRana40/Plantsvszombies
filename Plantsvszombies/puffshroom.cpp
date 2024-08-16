#include "header.h"
Puffshroom::Puffshroom()
{
	shootinginterval = 2;
	shootingspeed = 20;
	shootingtexture.loadFromFile("C:/humaImages/pear.png"); //have to load correctly
	shootingsprite.setTexture(shootingtexture);
	shootingbuffer.loadFromFile("C:/audio/splat2.wav");
	sound.setBuffer(shootingbuffer);
	shootingcoordinates.x = 0; //will be set later
	shootingcoordinates.y = 0;
	health = 6;
	positionP.x = 0;
	positionP.y = 0;
	price = 175;
	plantTexture.loadFromFile("C:/humaImages/fume.png");
	plantSprite.setTexture(plantTexture);
}