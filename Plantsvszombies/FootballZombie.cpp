#include "FootballZombie.h"

footballZombie::footballZombie() : Zombies(9, 2, "football/football (", "football_die/football_die (", "football_eat/football_eat (", 11, 10, 7) {

}
void footballZombie::alive() {
	Zombies::alive();
	lives = 9;
}
void footballZombie::move(int& gameover) {
	if (!dead && !boom) {
		if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
			zombieSprite.setTexture(zombieTexture[current]);

			if (current == 10) {
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
		dead = true;
		bilkulDead = true;
		
	}
}