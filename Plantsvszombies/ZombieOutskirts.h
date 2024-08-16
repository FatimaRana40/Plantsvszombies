#pragma once
#include "levels.h"
using namespace sf;
class ZombieOutskirts :public Levels {
protected:
	sf::SoundBuffer backgroundMusicBuffer;
	sf::Sound backgroundMusic;

public:
	ZombieOutskirts();
	virtual void update();
	virtual void manageGameLogic(RenderWindow& window);
	bool handleEvents(RenderWindow& window, Event event);
	virtual bool checkWinCondition(RenderWindow& window);
	virtual void draw(RenderWindow& window);
	virtual void introducezombies();
};
