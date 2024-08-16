#pragma once
#include "levels.h"
using namespace sf;
class FoggyForest:public Levels
{
protected:
	sf::SoundBuffer backgroundMusicBuffer;
	sf::Sound backgroundMusic;
public:
	FoggyForest();
	virtual void draw(RenderWindow& window);
	virtual void introducezombies();
	bool handleEvents(RenderWindow& window, Event event);
	virtual void manageGameLogic(RenderWindow& window);
	virtual bool checkWinCondition(RenderWindow& window);
};