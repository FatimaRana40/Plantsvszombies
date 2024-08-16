#include "SimpleZombie.h"

simpleZombie::simpleZombie() :Zombies(4,1.5,"simple/simple (","simple_die/simple_die (","simple_eat/simple_eat (",18,20,10) {
	positionZ.x = 1100 + (rand() % 400);
	//lives = 60;
}
void simpleZombie::alive() {
	Zombies::alive();
	lives = 4;
}
void simpleZombie::move(int& gameover) {
	if (!dead && moving && !bilkulDead && !boom) {
		if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
			zombieSprite.setTexture(zombieTexture[current]);
			
			if (current == 17) {
				current = 0;
			}
			else {
				current++;
			}
			textureClock.restart();
		}
		positionZ.x -= zombiespeed;
		
	}

	if (!dead && positionZ.x < 100 ) {
		gameover--;
		bilkulDead = true;
		dead = true;
	}
	
}

