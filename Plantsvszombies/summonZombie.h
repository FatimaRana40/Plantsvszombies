#pragma once
#include "Zombies.h"
class summonZombie:public Zombies {
	Texture mound[21];
	bool summoned;

public:
	summonZombie();
	virtual void move(int& gameover);
	void setPosition(int x, int y);
	virtual void alive();
	void summon();
	bool done();
};