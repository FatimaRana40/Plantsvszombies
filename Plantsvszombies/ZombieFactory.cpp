#pragma once
#include "ZombieFactory.h"

ZombieFactory::ZombieFactory(int i) {
		maxNumber = i;
		index = 0;
		zPtr = new Zombies * [i] {0};
	}
	void ZombieFactory::AddZombie(int i) {
		if (index + 1 <= maxNumber) {
			if (i == 1) {
				zPtr[index] = new simpleZombie;
			}
			else if (i == 2) {
				zPtr[index] = new footballZombie;
			}
			else if (i == 3) {
				for (int i = 0; i < 4; i++)
					zPtr[index++] = new summonZombie;
				zPtr[index] = new DancingZombie((summonZombie*)zPtr[index - 4], (summonZombie*)zPtr[index - 3], (summonZombie*)zPtr[index - 2], (summonZombie*)zPtr[index - 1]);
			}
			else if (i == 4) {
				zPtr[index] = new flyingZombie;
			}
			else if (i == 5) {
				zPtr[index] = new TrashZombie;
			}
			index++;
		}
	}
	void ZombieFactory::decLives(int i) {
		zPtr[i]->decrementLife();
	}

	bool ZombieFactory::allDead() {
		for (int i = 0; i < index; i++) {
			if (zPtr[i]->isDead()) {
				continue;
			}
			else {
				return false;
			}
		}
		return true;
	}

	void ZombieFactory::draw(RenderWindow& window) {
		for (int i = 0; i < index; i++) {
			zPtr[i]->draw(window);
		}
	}
	void ZombieFactory::update(int& gameover) {
		for (int i = 0; i < index; i++) {
			zPtr[i]->move(gameover);
		}
	}
	int ZombieFactory::getIndex() {
		return index;
	}

	void ZombieFactory::alive(int i) {
		int x;
		if (i == 1) {
			for (int i = 0; i < 5; i++)
				zPtr[i]->alive();
		}
		else if (i == 2) {
			zPtr[10]->alive();
			x = 7;
			while (x > 0) {
				int y = rand() % 24;
				if (y != 8 && y != 7 && y != 9 && y != 6 && y != 17 && y != 18 && y != 19 && y != 16) {
					if (zPtr[y]->isDead()) {
						cout << "s " << y;
						zPtr[y]->alive();
						x--;
					}
				}
			}

		}
		else if (i == 3) {
			zPtr[0]->alive();
			zPtr[1]->alive();
			zPtr[2]->alive();
			zPtr[5]->alive();
			zPtr[6]->alive();
			zPtr[7]->alive();
			zPtr[12]->alive();
			cout << "done";
		}
	}
	ZombieFactory::~ZombieFactory() {
		for (int i = 0; i < index; i++) {
			delete zPtr[i];
		}
	}
	coordinates ZombieFactory::operator[](int i) {
		return zPtr[i]->getCoordinates();
	}

	bool ZombieFactory::isDead(int i) {
		return zPtr[i]->isDead();
	}