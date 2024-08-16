#pragma once
#include"SFML/Audio.hpp"
#include <SFML/Graphics.hpp>
#include "levels.h"
using namespace sf;
using namespace std;

class BegginersGarden :public Levels {
	
protected:
	bool firstZombieAppeared;
	sf::SoundBuffer zombieSoundBuffer;
	sf::Sound zombieSound;
	sf::SoundBuffer backgroundMusicBuffer; 
	sf::Sound backgroundMusic;
public:
	BegginersGarden();
	virtual bool checkWinCondition(RenderWindow& window);
	virtual void draw(RenderWindow& window);
	virtual void update();
	void introducezombies();
	virtual void manageGameLogic(RenderWindow& window);
	virtual bool  handleEvents(RenderWindow& window, Event event);
	//void chotamenudiplay();

};