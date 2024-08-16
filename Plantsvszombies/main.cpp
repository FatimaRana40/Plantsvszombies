//Seerat E Zahra
//23i-0640
//Cs-E
//Fatima Farrukh
//23i-0773
//Cs-E
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include"Game.h"
//#include"../SFML/Images/"
using namespace sf;
using namespace std;


int main()
{

	//Create a window, n*n
	RenderWindow window(VideoMode(1200, 700), "Plants Vs Zombies", Style::Titlebar | Style::Close);
	//Game icon
	Image icon;
	if (!icon.loadFromFile("Images/icon.png"))
	{
		return 1;
	}
	window.setIcon(32, 32, icon.getPixelsPtr());

	///////////////////////////////////////

	//Game field (5*9)
	//Point 137*79 - leftmost point
	//length 41; width 53
	const int ROWS = 5;
	const int COLS = 9;

	bool FIELD_GAME_STATUS[ROWS][COLS];

	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			FIELD_GAME_STATUS[i][j] = true;
		}
	}

	

	//RenderWindow Menu(VideoMode(1200, 700), "Main Menu");
	Game game(134, 136, 620, 180);
	game.start(window);

	

	return 0;
};