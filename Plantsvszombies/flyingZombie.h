#pragma once
#include "Zombies.h"
class flyingZombie :public Zombies {
	bool dir;
public:
	flyingZombie();
	virtual void move(int& gameover);
	virtual void alive();
};