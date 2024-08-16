#include"Plants.h"
#include"cstdlib"
#include"sunflower.h"
#include "sun.h"



sunflower::sunflower()
{

	health = 200;
	positionP.x = 280;
	positionP.y = 90;
	price = 50;
	plantdead = false;
	n = 1;
	plantTexture.loadFromFile("Images/img2.png");
	plantSprite.setTexture(plantTexture);
	currentTextureIndex = 0;
	for (int i = 0; i < 5; ++i) {
		std::string path = "Images/sunflower/mysun" + std::to_string(i + 1) + ".png";
		peaTextures[i].loadFromFile(path);
	}


}
void sunflower::update() {
	sun.update();
	sun.setPosition(positionP.x, positionP.y);
	if (timer.getElapsedTime().asSeconds() >= 0.3f) {
		timer.restart();
		currentTextureIndex = (currentTextureIndex + 1) % 5; // Assuming you have 5 textures for peashooter animation
		plantSprite.setTexture(peaTextures[currentTextureIndex]);
	}

}

void sunflower::draw(sf::RenderWindow& window) {
	plantSprite.setPosition(positionP.x, positionP.y);
	window.draw(plantSprite);
	if (sun.getTime().getElapsedTime().asSeconds() >= 5) {
		sun.setActive(false);
	}
	sun.drawSun(window);
}
void sunflower::collect(Event& event, int& currency) {
	sun.collectsuns(event,currency);
}

void sunflower::ShootPea()
{

}
int sunflower::getCurrency()
{
	return price;
}
bool sunflower::isActive()
{
	return true;
}
void sunflower::displayplant(sf::RenderWindow& window) {
	plantSprite.setPosition(positionP.x, positionP.y);
	window.draw(plantSprite);
}