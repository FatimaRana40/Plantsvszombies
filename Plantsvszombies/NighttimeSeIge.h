#pragma once
#include "levels.h"
using namespace sf;

class NighttimeSeIge :public Levels
{
protected:
	sf::SoundBuffer backgroundMusicBuffer;
	sf::Sound backgroundMusic;
public:
	NighttimeSeIge();
	virtual void draw(RenderWindow& window);
	virtual void introducezombies();
	bool handleEvents(RenderWindow& window, Event event);
	virtual void manageGameLogic(RenderWindow& window);
	virtual bool checkWinCondition(RenderWindow& window);
};