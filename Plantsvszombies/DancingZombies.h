#pragma once
#include "Zombies.h"
#include "summonZombie.h"
class DancingZombie :public Zombies{
	Clock summontimer;
	bool summon;
	bool summoncomplete;
	Texture danceTexture[22];
	Texture summonTexture[3];
	bool dance;
	summonZombie* summonz[4];

public:
	DancingZombie(summonZombie* s1, summonZombie* s2, summonZombie * s3, summonZombie* s4);
	void summonZombies(RenderWindow& window);
	virtual void move(int& gameover);
	virtual void alive();
	virtual void draw(RenderWindow& window);
};