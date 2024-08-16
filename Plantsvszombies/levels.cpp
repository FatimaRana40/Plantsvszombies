#include"SFML/Audio.hpp"
#include <SFML/Graphics.hpp>
#include "levels.h"
#include "gamefeild.h"
#include "Plants.h"
#include "Zombies.h"
#include "ZombieFactory.h"
using namespace sf;
using namespace std;
Levels::Levels(int zombies) {
		gameover = 3;
		start = false;
		currency = 100;
		pf = new PlantFactory();
		z = new ZombieFactory(zombies);
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j < COLS; j++) {
				FIELD_GAME_STATUS[i][j].patchCoordinates.x = 200 + 95 * j;
				FIELD_GAME_STATUS[i][j].patchCoordinates.y = 100 + 115 * i;
				FIELD_GAME_STATUS[i][j].check = true;
			}
		}
		int temp = 115;
		for (int i = 0; i < 5; i++)
		{
			mowers[i].setPosition(130, (temp * i + 110));
		}

}
bool Levels::handleMouse(RenderWindow& window, Event event) {
	if (event.type == Event::MouseButtonPressed) {
		int mouseX = event.mouseButton.x;
		int mouseY = event.mouseButton.y;
	
		int iconLeft = exitSprite.getPosition().x;
		int iconTop = exitSprite.getPosition().y;
		int iconWidth = 140;
		int iconHeight = 35;
		if (mouseX >= iconLeft && mouseX <= iconLeft + iconWidth &&
			mouseY >= iconTop && mouseY <= iconTop + iconHeight) {
			return true;
		}
		else {
			iconLeft = 480;
			iconTop = 510;
			iconWidth = 250;
			iconHeight = 100;
			if (mouseX >= iconLeft && mouseX <= iconLeft + iconWidth &&
				mouseY >= iconTop && mouseY <= iconTop + iconHeight) {
				start = true;
			}

		}
	}
	return false;
}
bool Levels::handleEvents(RenderWindow& window, Event event) {
	if (event.type == Event::MouseButtonPressed) {
		sun.collectsuns(event,currency);
	
		for (int i = 0; i < pf->getindex(); i++)
		{
			pf->plantdoubleptr[i]->collect(event, currency);
		}
		


	}
	if (event.type == sf::Event::KeyPressed) {
		if (event.key.code == sf::Keyboard::Space) {
			paused = true;
			if (isPaused()) {
				pauseGame(window);
			}
		}
	}
	else if (event.type == Event::MouseMoved) {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
		pf->dragPlant(mousePosition);
	}

	if (handleMouse(window, event)) {
		return true;
	}
	

	else {
		return false;
	}
	

}




void Levels::draw(RenderWindow& window,string str1,string str2,string str3) {

	Image bg_image;
	bg_image.loadFromFile(pathbg);
	Texture bg;
	bg.loadFromImage(bg_image);
	Sprite s_bg;
	s_bg.setTexture(bg);
	s_bg.setPosition(15, 0);
	window.draw(s_bg);
	if (start == false) {
		drawIns(window,str1,str2,str3);
	}

	exit.loadFromFile("Images/button.png");
	exitSprite.setTexture(exit);
	exitSprite.setTextureRect(sf::IntRect(45, 50, 200, 70));
	exitSprite.setPosition(1050, 0);
	window.draw(exitSprite);
	if (start == true) {
		drawOptions(window);
		sun.drawSun(window);
		z->draw(window);
		
		for (int i = 0; i < 5; i++)
		{
			mowers[i].drawlawnMower(window);

			pf->display(window);
		}
	}

}
void Levels::drawIns(RenderWindow& window, string str1, string str2, string str3) {
	Texture ins;
	ins.loadFromFile(str1);
	Sprite insSprite;
	insSprite.setTexture(ins);
	insSprite.setPosition(200, 50);
	window.draw(insSprite);
	sf::Font font;
	font.loadFromFile("Images/font2.ttf");
	sf::Text text;
	Text text2;
	text.setFont(font);
	text2.setFont(font);
	text.setString(str2);
	text2.setString(str3);
	text2.setCharacterSize(44);
	text.setCharacterSize(44);
	text2.setFillColor(sf::Color::Black);
	text.setFillColor(sf::Color::White);
	text.setPosition(450, 65);
	text2.setPosition(260, 130);
	window.draw(text);
	window.draw(text2);
	Texture start;
	start.loadFromFile("Images/str.png");
	Sprite startSprite;
	startSprite.setTexture(start);
	startSprite.setPosition(480, 510);
	window.draw(startSprite);
}
void Levels::drawOptions(RenderWindow& window) {
	Texture options;
	options.loadFromFile("Images/options.png");
	Sprite insSprite;
	insSprite.setTexture(options);
	insSprite.setPosition(0, 0);
	Sprite peashotercard;
	Texture peacard;
	peacard.loadFromFile("Images/peacard.png");
	peashotercard.setTexture(peacard);
	peashotercard.setPosition(70, 0);
	Texture sunflowercard;
	Sprite sunflowerp;
	sunflowercard.loadFromFile("Images/sunflowercard.png");
	sunflowerp.setTexture(sunflowercard);
	sunflowerp.setPosition(132, 0);
	
	
	window.draw(insSprite);
	window.draw(peashotercard);
	window.draw(sunflowerp);
	
	sf::Font font;
	font.loadFromFile("Images/font2.ttf");
	//sf::Text scored;
	scored.setFont(font);
	scored.setCharacterSize(30);
	scored.setFillColor(sf::Color::Black);
	scored.setPosition(30,55);
	string scoredisplay = to_string(currency);
	scored.setString(scoredisplay);
	window.draw(scored);
	
}

bool Levels::checkWinCondition(RenderWindow& window) {
	return false;
}
bool Levels::checkLooseCondition() {
	if (gameover <= 0)
		return true;
	return false;
}
void Levels::manageGameLogic(RenderWindow& window) {
	update();
	draw(window);
	
}
void Levels::update() {
	sun.update();

	checkZombiePlantCollision();
	checkMowerCollision();
	checkwallnutcollison();
	checkcherryCollision();
	checkingwallnut();
	pf->run();
	for (int i = 0; i < 5; i++)
		mowers[i].lawnmowermovement();
	z->update(gameover);
	for (int i = 0; i < z->getIndex(); i++) {

		for (int j = 0; j < (pf->getindex()); j++)
		{
			if (z->operator[](i).x - pf->plantdoubleptr[j]->getPosition().x <= 1100 && z->operator[](i).x < 1100 &&
				z->operator[](i).x - pf->plantdoubleptr[j]->getPosition().x >= 0 &&
				z->operator[](i).y <= pf->plantdoubleptr[j]->getPosition().y &&
				z->operator[](i).y + 70 >= pf->plantdoubleptr[j]->getPosition().y && !z->isDead(i) && pf->plantdoubleptr[j]->isplacedongrid)
			{
				pf->plantdoubleptr[j]->ShootPea();
			}
			if (!z->isDead(i)) {
				if (pf->plantdoubleptr[j]->detectcollision((z->operator[](i))))
				{
					if (pf->plantdoubleptr[j]->n == 2) {
						z->zPtr[i]->halfSpeed();
					}
					if (pf->plantdoubleptr[j]->n == 6) {
						z->decLives(i);
					}
					z->decLives(i);
				}
			}

		}

	}
	
}
void Levels::checkwallnutcollison()
{
	for (int i = 0; i < z->getIndex(); i++) {
		for (int j = 0; j < pf->getindex(); j++) {
			if (pf->plantdoubleptr[j] != NULL)
			{


				//if (z[i].x>= pf->plantdoubleptr[j]->getPosition().x-30 && z[i].x <= pf->plantdoubleptr[j]->getPosition().x + 30 && z[i].y >= pf->plantdoubleptr[j]->getPosition().y-30 && z[i].y <= pf->plantdoubleptr[j]->getPosition().y + 30) {
				if (pf->plantdoubleptr[j]->getPosition().x - z->operator[](i).x < 10 &&
					pf->plantdoubleptr[j]->getPosition().x - z->operator[](i).x > 0 &&
					pf->plantdoubleptr[j]->getPosition().y - z->operator[](i).y <= 170 &&
					pf->plantdoubleptr[j]->getPosition().y - z->operator[](i).y >= 0 &&
					!pf->plantdoubleptr[j]->plantdead && pf->plantdoubleptr[j]->n == 2 &&
					pf->plantdoubleptr[j]->isplacedongrid && !z->isDead(i)) {
					
					z->zPtr[i]->die();
					pf->plantdoubleptr[j]->setdiagonalmovement();
					cout << "wall collison called ";

				}
			}


		}
	}

}
void Levels::checkingwallnut()
{
	for (int j = 0; j < pf->getindex(); j++)
	{
		if (pf->plantdoubleptr[j] != nullptr)
		{
			pf->plantdoubleptr[j]->movediagonal();
		}
	}
}
int Levels::getcurrency()
{
	return currency;
}
void Levels::checkMowerCollision() {
	for (int i = 0; i < z->getIndex(); i++)
	{
		for (int j = 0; j < 5; j++)
		{
			float lawnmowerX = mowers[j].getlawncoordinates().x;
			float zombieX = z->operator[](i).x;
			float lawny = mowers[j].getlawncoordinates().y;
			float zombiey = z->operator[](i).y;

			if (lawnmowerX >= zombieX - 10 && lawnmowerX <= zombieX + 10 &&
				!z->isDead(i) && lawny - zombiey <= 80 && lawny - zombiey >= 0) {
				mowers[j].setMove();
				z->zPtr[i]->die();
			}
		}
	}
}

void Levels::checkZombiePlantCollision() {
	//cout << "Check Collision called " << endl;
	for (int i = 0; i < z->getIndex(); i++) {
		for (int j = 0; j < pf->getindex(); j++) {
			if (pf->plantdoubleptr[j] != NULL)
			{


				//if (z->operator[](i).x>= pf->plantdoubleptr[j]->getPosition().x-30 && z->operator[](i).x <= pf->plantdoubleptr[j]->getPosition().x + 30 && z->operator[](i).y >= pf->plantdoubleptr[j]->getPosition().y-30 && z->operator[](i).y <= pf->plantdoubleptr[j]->getPosition().y + 30) {
				if (pf->plantdoubleptr[j]->getPosition().x - z->operator[](i).x < 10 &&
					pf->plantdoubleptr[j]->getPosition().x - z->operator[](i).x > 0 &&
					pf->plantdoubleptr[j]->getPosition().y - z->operator[](i).y == 60 &&
					!pf->plantdoubleptr[j]->plantdead && pf->plantdoubleptr[j]->n!=2 &&
					pf->plantdoubleptr[j]->n!=3 && !z->isDead(i)) {


					z->zPtr[i]->stopMovement();
					z->zPtr[i]->eatPlant();
					pf->plantdoubleptr[j]->decrementhealth();
					if (pf->plantdoubleptr[j]->plantdead)
					{
						//cout << "plant margaya";

						z->zPtr[i]->resumeMovement();
						//new
						for (int i = 0; i < 5; i++) {
							for (int k = 0; k < 9; k++) {
								if (pf->plantdoubleptr[j]->getPosition().x == FIELD_GAME_STATUS[i][k].patchCoordinates.x &&
									pf->plantdoubleptr[j]->getPosition().y == FIELD_GAME_STATUS[i][k].patchCoordinates.y) {
									FIELD_GAME_STATUS[i][k].check = true;
								}
							}
						}
					}
				}
			}
			
				
		}
	}
}
void Levels::checkcherryCollision() {

	for (int i = 0; i < z->getIndex(); i++) {
		for (int j = 0; j < pf->getindex(); j++) {
			if (pf->plantdoubleptr[j] != NULL)
			{


				//if (z[i].x>= pf->plantdoubleptr[j]->getPosition().x-30 && z[i].x <= pf->plantdoubleptr[j]->getPosition().x + 30 && z[i].y >= pf->plantdoubleptr[j]->getPosition().y-30 && z[i].y <= pf->plantdoubleptr[j]->getPosition().y + 30) {
				if (pf->plantdoubleptr[j]->n == 3) {

					CherryBomb* temp=(CherryBomb*)pf->plantdoubleptr[j];
					if (temp->getExploding()) {
						if (z->operator[](i).x >= temp->getPosition().x - 95 &&
							z->operator[](i).x <= temp->getPosition().x + 2 * 95 &&
							z->operator[](i).y +60 >= temp->getPosition().y - 115 &&
							z->operator[](i).y +60<= temp->getPosition().y + 2 * 115) {
							//cout << "in range";
							z->zPtr[i]->boom_die();

						}
					}

				}
			}


		}
	}
}

