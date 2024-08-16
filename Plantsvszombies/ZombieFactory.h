#pragma once
#include "Zombies.h"
#include "SimpleZombie.h"
#include "FootballZombie.h"
#include "DancingZombies.h"
#include "flyingZombie.h"
#include "TrashZombie.h"

class ZombieFactory {
private:

	int maxNumber,index;
public:
	Zombies** zPtr;
	ZombieFactory(int i = 5);
	void AddZombie(int i);
	void decLives(int i);

	bool allDead();

	void draw(RenderWindow& window);
	void update(int& gameover);
	int getIndex() ;

	void alive(int i = 1);
	~ZombieFactory();
	coordinates operator[](int i);
	
	bool isDead(int i);
};