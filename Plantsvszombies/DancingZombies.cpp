#include "DancingZombies.h"

DancingZombie::DancingZombie(summonZombie* s1, summonZombie* s2, summonZombie* s3, summonZombie* s4) :Zombies(6, 2.5, "moving/move (", "dancing_die/die (", "dancing_eat/dancing (", 21, 11, 12) {
	summonz[0] = s1;
	summonz[1] = s2;
	summonz[2] = s3;
	summonz[3] = s4;

	positionZ.y = 35 + 230 +(rand() % 2) * 115;
	for (int i = 0; i < 22; i++) {
		danceTexture[i].loadFromFile("Images/dance/dance (" + to_string(i + 1) + ").gif");
	}
	for (int i = 0; i < 3; i++) {
		summonTexture[i].loadFromFile("Images/summon/summon (" + to_string(i + 1) + ").gif");
	}

	dance = false;
	summon = false;
	summoncomplete = true;
}
void DancingZombie::draw(RenderWindow& window) {
	Zombies::draw(window);
	if (summon == true && !dead){
		if (!summoncomplete) {
			
			summonZombies(window);
		}
	}
}

void DancingZombie::alive() {
	Zombies::alive();
	summoncomplete = true;
	dance = false;
	positionZ.y = 35 + 230 + (rand() % 2) * 115;
	summon = false;
	lives = 6;
}
void DancingZombie::move(int& gameover) {
	if (!dead && !boom) {
		if (summoncomplete==true) {
			if (dance == false && summon==false) {
				if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
					zombieSprite.setTexture(zombieTexture[current]);

					if (current == 20) {
						current = 0;
						dance = true;
					}
					else {
						current++;
					}
					textureClock.restart();
				}
			}
			positionZ.x -= zombiespeed;
			

			if (dance == true || summon == true) {
				if (textureClock.getElapsedTime().asSeconds() >= 0.1) {
					zombieSprite.setTexture(danceTexture[current]);

					if (current == 21) {
						current = 0;
						dance = false;
					}
					else {
						current++;
					}
					textureClock.restart();
				}
			}
		}
		if (summon == false) {
			if (positionZ.x > 720 && positionZ.x < 720 + 90) {
				summoncomplete = false;
				summon = true;
				summontimer.restart();
				current = 0;
			}
		}
		else if(summoncomplete && summon){

			for (int i = 0; i < 4; i++) {
				summonz[i]->move(gameover);
			}
		}
		if (!summoncomplete) {
			if (textureClock.getElapsedTime().asSeconds() >= 0.3) {
				zombieSprite.setTexture(summonTexture[current]);
				if (current != 2) {
					current++;
				}
				textureClock.restart();
			}
		}
		
	}
	
	if (!dead && positionZ.x < 100) {
		gameover--;
		dead = true;
		bilkulDead = true;
		summon = false;
	
	}

}
void DancingZombie::summonZombies(RenderWindow& window) {
	Texture t, t2;
	t.loadFromFile("Images/spotlight.png");
	t2.loadFromFile("Images/spotlight2.png");
	Sprite s, s2;
	s.setTexture(t);
	s.setPosition(200, -80);
	s2.setTexture(t2);
	s2.setPosition(190, 380);
	window.draw(s);
	window.draw(s2);
	if (summontimer.getElapsedTime().asSeconds() >= 5) {
		summoncomplete = true;
		current = 0;
	}
	if (summontimer.getElapsedTime().asSeconds() >= 3) {
		for (int i = 0; i < 4; i++) {
			if(summonz[i]->isDead())
			summonz[i]->alive();
			if (!(summonz[i])->done())
				summonz[i]->summon();
		}
	}
	
	summonz[0]->setPosition(positionZ.x + 95,positionZ.y);
	summonz[1]->setPosition(positionZ.x - 95, positionZ.y);
	summonz[2]->setPosition(positionZ.x, positionZ.y + 115);
	summonz[3]->setPosition(positionZ.x, positionZ.y - 115);


}

 