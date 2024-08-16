#include "summonZombie.h"
summonZombie::summonZombie() : Zombies(6,1.75, "summondance/summondance (", "summon_die/summon_die (", "summon_eat/summon_eat (", 21, 9, 20) {
	positionZ.x = 1100;
	positionZ.y = 65 + (rand() % 6) * 110;
	dead = true;
	bilkulDead = true;
	for (int i = 0; i < 21; i++) {
		mound[i].loadFromFile("Images/mound/mound (" + to_string(i + 1) + ").gif");
	}
	zombieSprite.setTexture(mound[0]);
	summoned = false;
}

void summonZombie::alive() {
	Zombies::alive();
	zombieSprite.setTexture(mound[0]);
	lives = 6;
}
void summonZombie::move(int& gameover) {

	if (!dead && !boom) {
		if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
			zombieSprite.setTexture(zombieTexture[current]);

			if (current == 21) {
				current = 0;
			}
			else {
				current++;
			}
			textureClock.restart();
		}
		positionZ.x -= zombiespeed;

		if (!dead && positionZ.x < 100) {
			gameover--;
			bilkulDead = true;
			dead = true;
		}
	}
	
	

}
void summonZombie::setPosition(int x, int y) {
	positionZ.x = x;
	positionZ.y = y;
}

void summonZombie::summon() {
	if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
		zombieSprite.setTexture(mound[current]);

		if (current == 20) {
			summoned = true;
			current = 0;
			zombieSprite.setTexture(zombieTexture[current]);
		}
		else {
			current++;
		}
		textureClock.restart();
	}
	
}
bool summonZombie::done() {
	return summoned;
}