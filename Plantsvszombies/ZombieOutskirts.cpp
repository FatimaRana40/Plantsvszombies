#include "ZombieOutskirts.h"
ZombieOutskirts::ZombieOutskirts() :Levels(24) {
	pathbg = "Images/level12.jpg";
	backgroundMusicBuffer.loadFromFile("audio/level2music.mp3");
	backgroundMusic.setBuffer(backgroundMusicBuffer);
	backgroundMusic.play();
}
void ZombieOutskirts::draw(RenderWindow& window) {
	
	Levels::draw(window, "Images/inslevel2.jpg", "Level 2: HOW TO PLAY\n", "Objectives:\nNew zombie types are introduced : Simple zombies, Football\nZombies, Flying Zombies, Dancing Zombies, and Dolphin \nRider zombies.\nUse wall-nuts for additional defense against stronger zombies.\nLearn to use cherry bombs to clear out groups of zombies.");
	if (start == true) {
		Sprite wallnutcard;
		Texture walltext;
		walltext.loadFromFile("Images/cards/wallnutcard.jpeg");
		wallnutcard.setTexture(walltext);
		wallnutcard.setPosition(194, 0);
		Sprite cherrybombcard;
		Texture cherrytext;
		cherrytext.loadFromFile("Images/cherrycard.png");
		cherrybombcard.setTexture(cherrytext);
		cherrybombcard.setPosition(256, 0);
		window.draw(wallnutcard);
		window.draw(cherrybombcard);

	}
}
bool ZombieOutskirts::checkWinCondition(RenderWindow& window) {
	if (z->allDead() && z->getIndex() == 24 && wavedone) {
		return true;
	}
	else {
		return false;
	}
}
void ZombieOutskirts::introducezombies() {
	if (track.getElapsedTime().asSeconds() > 5 && z->getIndex() == 0) {
		z->AddZombie(1);
		track.restart();
	}
	else if (z->getIndex() == 24 && z->allDead() && !wavedone) {
		
		wavedone = true;
		z->alive(2);
		//cout << "wavedone";
	}
	else if (track.getElapsedTime().asSeconds() > 10 + rand() % 10) {
		z->AddZombie(1);
		z->AddZombie(4);
		if(z->getIndex() == 3 || z->getIndex() == 13 || z->getIndex() == 23)
		z->AddZombie(2);
		if(z->getIndex()==6 || z->getIndex()==16)
		z->AddZombie(3);
		track.restart();
	}

}
void ZombieOutskirts::manageGameLogic(RenderWindow& window) {
	introducezombies();
	draw(window);
	update();
}
void ZombieOutskirts::update() {
	Levels::update();

	

}
bool ZombieOutskirts::handleEvents(RenderWindow& window, Event event)
{


	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	pf->handleMouseClick(event, mousePosition, currency, FIELD_GAME_STATUS, 4);

	return Levels::handleEvents(window, event);

}