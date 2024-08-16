
#include "sun.h"
Sun::Sun()
{
	suntexture.loadFromFile("Images/sun.png");
	sunsprite.setTexture(suntexture);
	positionS.x = 400 + rand() % 600;
	positionS.y = 50;
	isActivev = false;
	appearanceTimer.restart();

}

void Sun::setPosition(float x, float y) {
	positionS.x = x;
	positionS.y = y;
}
void Sun::update() {

	if (appearanceTimer.getElapsedTime().asSeconds() >= 10) {
		isActivev = true;
		appearanceTimer.restart();
	}
	if (isActivev)
		positionS.y += 3;


	if (positionS.y > 600) {
		setPosition(400 + rand() % 900, 50);
		isActivev = false;
	}
}

void Sun::drawSun(RenderWindow& window)
{
	if (isActivev) {
		sunsprite.setPosition(positionS.x, positionS.y);
		window.draw(sunsprite);
	}
}

void Sun::collectsuns(Event event,int& currency) {
	if (isActivev) {
		if (event.mouseButton.x >= positionS.x && event.mouseButton.x <= positionS.x + 80 &&
			event.mouseButton.y >= positionS.y && event.mouseButton.y <= positionS.y + 100) {
			isActivev = false;
			setPosition(400 + rand() % 900, 50);
			currency += 25;
		}
	}
}
Clock Sun::getTime() {
	return appearanceTimer;
}
void Sun::setActive(bool set) {
	isActivev = set;
}
