#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include "levels.h"
#include "ZombieOutskirts.h"
#include "SunflowerFeilds.h"
#include "FoggyForest.h"
#include "NighttimeSeIge.h"
#include "level6.h"
#include "BeginnersGarden.h"
#include <fstream>
#include<string>
#include <sstream>
#include "score.h"
using namespace sf;
using namespace std;

struct menuItem {
	Texture LevelTexture;
	Sprite LevelSprite;
};

class Game {
	bool prevUser;
	Levels* playlevel;
	bool gameStart;
	int MainMenuSelected;
	menuItem playbutton;
	bool enabled[6];
	Texture disabled[6];
	menuItem mainMenu[9];
	Text inputText;
	string userInput;
	Font font1;
	bool textBoxClicked;
	bool passwordBoxClicked;
	Text passwordText;
	string userinput2;
	Score* gamescore;
	bool scorecreated;
public:

	void start(RenderWindow& window);
	Game(float width, float height, int posX, int posY);
	bool handleLevel(RenderWindow& window, Event event);
	bool handleMouseStart(RenderWindow& window, Event event);
	bool handleMouseIns(RenderWindow& window,Event event);
	void drawProfile(RenderWindow& window,bool& levelcheck);
	void drawWonScreen(RenderWindow& window, bool& levelcheck);
	void drawLostScreen(RenderWindow& window, bool& levelcheck);
	void readLevel();
	void saveLevel();
	void drawIns(RenderWindow& window);
	void drawStartScreen(RenderWindow& window);
	void drawMainMenu(RenderWindow& window);
	void drawHighScoreScreen(RenderWindow& window);
	int MainMenuPressed();
	~Game();
};