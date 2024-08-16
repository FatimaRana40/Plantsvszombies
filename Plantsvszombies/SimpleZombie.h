#pragma once
#include "Zombies.h"
class simpleZombie :public Zombies {

public:
	simpleZombie();
	virtual void move(int& gameover) ;
	virtual void alive();
};