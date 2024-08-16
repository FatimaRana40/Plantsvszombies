#include"BeginnersGarden.h"
BegginersGarden::BegginersGarden() :Levels(8){

	pathbg = "Images/level12.jpg";
	track.restart();
	firstZombieAppeared = false;

	// Load sound buffer from file
	if (!zombieSoundBuffer.loadFromFile("audio/Voicy_TheZombiesarecoming.mp3")) {
		std::cerr << "Failed to load zombie sound file" << std::endl;
	}
	zombieSound.setBuffer(zombieSoundBuffer);
	if (!backgroundMusicBuffer.loadFromFile("audio/20.GrasswalkIN-GAME.mp3")) {
		std::cerr << "Failed to load background music file" << std::endl;
	}
	zombieSound.setVolume(100);
	backgroundMusic.setBuffer(backgroundMusicBuffer);
	backgroundMusic.play();
}
void BegginersGarden::draw(RenderWindow& window) {
	Levels::draw(window, "Images/inslevel1.jpg", "Level 1: HOW TO PLAY\n", "Objectives:\nPlant sunflowers to generate sunlight.\nDefend against incoming zombies using pea shooters.\nStrategically use lawnmowers as a last line of defense.");
}
bool BegginersGarden::checkWinCondition(RenderWindow& window) {
	if (z->allDead() && z->getIndex() == 8 && wavedone) {
		return true;
	}
	else {
		return false;
	}
}

void BegginersGarden::update() {
	Levels::update();
	
	if (!firstZombieAppeared && z->getIndex() > 0 && !z->isDead(0)) {
		
		zombieSound.play();

		
		firstZombieAppeared = true;
	}
	
	

	
}
void BegginersGarden::introducezombies() {

	if (z->getIndex() <=7  && track.getElapsedTime().asSeconds() > 7+rand()%10) {
		z->AddZombie(1);

		track.restart();
	}
	if (z->allDead() && z->getIndex() == 8 && !wavedone) {
		//cout << "wavedonne";
		wavedone=true;
		z->alive(1);
	}
}


void BegginersGarden::manageGameLogic(RenderWindow& window) {
	introducezombies();
	draw(window);
	update();
}
bool BegginersGarden::handleEvents(RenderWindow& window, Event event)
{	 
	
	
	sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
	pf->handleMouseClick(event, mousePosition, currency, FIELD_GAME_STATUS, 2);

	return Levels::handleEvents(window, event);

}