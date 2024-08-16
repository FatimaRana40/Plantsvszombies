#pragma once
#include"SFML/Audio.hpp"
#include "sun.h"
#include"lawnmower.h"
#include "sunflower.h"
#include "cherrybomb.h"
#include <SFML/Graphics.hpp>
#include"plantfactory.h"
#include "Plants.h"
#include "Zombies.h"
#include "ZombieFactory.h"
using namespace sf;
using namespace std;

const int ROWS = 5;
const int COLS = 9;

class Levels {
protected:
	bool diagnol;
	bool wavedone;
	int gameover;
	bool start;
	Texture exit;
	Sprite exitSprite;
	string pathbg;
	string name;
	Lawnmower mowers[5];
	Sun sun;
	Sprite Background;
	Texture bgTexture;
	ZombieFactory *z;
	int currency;
	Clock track;
	PlantFactory* pf;
	gamefeild FIELD_GAME_STATUS[ROWS][COLS];
	bool paused;
public:
	sf::Text scored;
	Levels(int zombies);
	//void loadLevel();
	virtual void update();
	void checkingwallnut();
	int getcurrency();
	virtual bool checkWinCondition(RenderWindow& window);
	bool checkLooseCondition();
	//void detectcollision(coordinates c1, coordinates c2);
	virtual void manageGameLogic(RenderWindow& window);
	virtual bool  handleEvents(RenderWindow& window, Event event);
	bool handleMouse(RenderWindow& window, Event event);
	void draw(RenderWindow& window, string str1, string str2, string str3);
	virtual void drawOptions(RenderWindow& window);
	virtual void draw(RenderWindow& window) = 0;
	virtual void introducezombies()=0;
	void drawIns(RenderWindow& window, string str1, string str2, string str3);
	void checkZombiePlantCollision();
	void checkwallnutcollison();
	void checkMowerCollision();
	void checkcherryCollision();
	bool isPaused() {
		return paused;
	}
	void pauseGame(RenderWindow& window) {
		Texture pausetext;
		Sprite pausesprite;
		pausetext.loadFromFile("Images/inslevel3pause.jpg");
		pausesprite.setTexture(pausetext);
		pausesprite.setPosition(0, 0);
		Font font;
		font.loadFromFile("Images/Font.ttf");
		Text text;
		text.setFont(font);
		text.setString("Your game is paused!\n press space key to continue");
		text.setCharacterSize(88);
		text.setFillColor(sf::Color::White);
		text.setPosition(200, 200);

		while (isPaused()) {
			Event event;
			//cout << "game paused ";
			//window.clear();
			window.draw(pausesprite);
			window.draw(text);
			window.display();
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::KeyPressed) {
					if (event.key.code == sf::Keyboard::Space) {
						paused = false;
					}
				}
			}

		}

	}


	virtual ~Levels()
	{

	}

};