#include <iostream>
#include "TrashZombie.h"
TrashZombie::TrashZombie() :Zombies(6, 1.5, "TrashZombie/TrashZombie (", "simple_die/simple_die (", "Trash_eat/Trash-eat (", 20, 20, 10) {

}
void TrashZombie::move(int& gameover) {
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

	if (!dead && positionZ.x < 100) {
		gameover--;
		bilkulDead = true;
		dead = true;
	}
}