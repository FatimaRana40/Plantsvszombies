#include "FoggyForest.h"
FoggyForest::FoggyForest() :Levels(24) {
	pathbg = "Images/level12.jpg";
	backgroundMusicBuffer.loadFromFile("audio/level4music.mp3");
	backgroundMusic.setBuffer(backgroundMusicBuffer);
	backgroundMusic.play();
}
void FoggyForest::draw(RenderWindow& window) {
	Levels::draw(window, "Images/inslevel1.jpg", "Level 4: HOW TO PLAY\n", "Objectives:\nPlants like PeaShooter, Sunflowers, Wall-nut, Snow Pea, \nCherry Bomb, and Repeater are Introduced  to clear \nfog and enhance offensive capabilities.\nLearn to anticipate zombie movements despite limited \nvisibility.");
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
	
	Sprite snowpeacard;
	Texture snowtext;
	snowtext.loadFromFile("Images/snowcard.png");
	snowpeacard.setTexture(snowtext);
	snowpeacard.setPosition(319, 0);
	Sprite repeatercard;
	Texture repttext;
	repttext.loadFromFile("Images/repeatercard.png");
	repeatercard.setTexture(repttext);
	repeatercard.setPosition(382, 0);
	
	sf::Texture fog;
	fog.loadFromFile("Images/fog3.png");
	sf::Sprite fogSprite;
	fogSprite.setTexture(fog);
	fogSprite.setPosition(500, -100);
	if (start == true) {
		window.draw(fogSprite);
		window.draw(snowpeacard);
		window.draw(repeatercard);
		window.draw(wallnutcard);
		window.draw(cherrybombcard);
	}

}
void FoggyForest::introducezombies() {
	if (track.getElapsedTime().asSeconds() > 5 && z->getIndex() == 0) {
		z->AddZombie(4);
		z->AddZombie(5);
		track.restart();
	}
	else if (z->getIndex() == 24 && z->allDead() && !wavedone) {
		wavedone = true;
		z->alive(3);
	}
	else if (track.getElapsedTime().asSeconds() > 10 + rand() % 10) {
		z->AddZombie(1);
		z->AddZombie(5);
		if (z->getIndex() == 4 || z->getIndex() == 15)
			z->AddZombie(4);
		if (z->getIndex() == 5 || z->getIndex() == 16 || z->getIndex() == 21)
			z->AddZombie(2);
		if (z->getIndex() == 8 || z->getIndex() == 19)
			z->AddZombie(3);
		track.restart();
	}

}
bool FoggyForest::handleEvents(RenderWindow& window, Event event) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	pf->handleMouseClick(event, mousePosition, currency, FIELD_GAME_STATUS, 6);

	return Levels::handleEvents(window, event);
}
bool FoggyForest::checkWinCondition(RenderWindow& window) {
	if (z->allDead() && z->getIndex() == 24 && wavedone) {
		return true;
	}
	else {
		return false;
	}
}
void FoggyForest::manageGameLogic(RenderWindow& window) {
	introducezombies();
	draw(window);
	update();
}