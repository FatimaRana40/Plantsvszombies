#pragma once
#include "Zombies.h"
class footballZombie :public Zombies {

public:
	footballZombie();
	virtual void move(int& gameover);
	virtual void alive();
};