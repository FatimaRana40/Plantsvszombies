#pragma once
#include "Zombies.h"
class TrashZombie :public Zombies {

public:
	TrashZombie();
	virtual void move(int& gameover);
};