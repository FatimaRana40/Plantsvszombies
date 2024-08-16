#include "NighttimeSeIge.h"
NighttimeSeIge::NighttimeSeIge() :Levels(24) {
	pathbg = "Images/night.jpg";
	backgroundMusicBuffer.loadFromFile("audio/level5music.mp3");
	backgroundMusic.setBuffer(backgroundMusicBuffer);
	backgroundMusic.play();
}
void NighttimeSeIge::draw(RenderWindow& window) {
	
	Levels::draw(window, "Images/inslevel2.jpg", "Level 5: HOW TO PLAY\n", "Objectives:\nSnow Pea is Introduced, which can be planted during the \nnight.\nDefend against waves of zombies while managing limited \nresources.");
	if (start) {
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
		window.draw(snowpeacard);
		window.draw(repeatercard);
		sf::Sprite fumeshroomCard;
		sf::Texture fumeshroomTexture;
		fumeshroomTexture.loadFromFile("Images/fmecard.png");
		fumeshroomCard.setTexture(fumeshroomTexture);
		fumeshroomCard.setPosition(447, 0);
		window.draw(fumeshroomCard);
	}
}
void NighttimeSeIge::introducezombies() {
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
bool NighttimeSeIge::handleEvents(RenderWindow& window, Event event) {
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	pf->handleMouseClick(event, mousePosition, currency, FIELD_GAME_STATUS, 7);

	return Levels::handleEvents(window, event);
}
bool NighttimeSeIge::checkWinCondition(RenderWindow& window) {
	if (z->allDead() && z->getIndex() == 24 && wavedone) {
		return true;
	}
	else {
		return false;
	}
}
void NighttimeSeIge::manageGameLogic(RenderWindow& window) {
	introducezombies();
	draw(window);
	update();
}