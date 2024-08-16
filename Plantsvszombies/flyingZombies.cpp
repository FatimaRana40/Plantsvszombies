#include "flyingZombie.h"

flyingZombie::flyingZombie() : Zombies(5, 2, "BaloonZombie/BaloonZombie (", "Baloon_die/Baloon_die (", "Baloon_eat/Baloon_eat (", 13, 20, 20) {
	dir = false;
	//positionZ.x = 1100;
	positionZ.y = 55 + (rand() % 5) * 115;
}
void flyingZombie::alive() {
	Zombies::alive();
	lives = 5;
}
void flyingZombie::move(int& gameover) {
	if (!dead && !boom) {
		if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
			zombieSprite.setTexture(zombieTexture[current]);

			if (current == 12) {
				current = 0;
			}
			else {
				current++;
			}
			textureClock.restart();
		}
		if (dir == false) {
			positionZ.y += zombiespeed;
		}
		else if (dir) {
			positionZ.y -= zombiespeed;
		}
		if (positionZ.y < 40 || positionZ.y>=530) {
			dir = !dir;
		}
		
		positionZ.x -= zombiespeed;

	}
	if (!dead && positionZ.x < 100) {
		gameover--;
		dead = true;
		bilkulDead = true;

	}
}