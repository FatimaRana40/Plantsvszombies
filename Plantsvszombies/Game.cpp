#include"SFML/Audio.hpp"
#include <SFML/Graphics.hpp>
using namespace sf;
#include "Game.h"

Game::Game(float width, float height, int posX, int posY) {
	userInput = "";
	if (!font1.loadFromFile("Images/Font.ttf")) {
		std::cerr << "Failed to load font" << std::endl;
		return;
	}
	inputText = sf::Text("", font1, 40);
	textBoxClicked = false;
	passwordBoxClicked = false;
	userinput2 = "";
	passwordText = sf::Text("", font1, 40);
	enabled[0] = true;
	for (int i = 1; i < 6; i++) {
		//cout << "entered loop";
		enabled[i] = false;
	}
	
	playlevel = NULL;
	playbutton.LevelTexture.loadFromFile("Images/playbutton.jpeg");
	playbutton.LevelSprite.setTexture(playbutton.LevelTexture);
	playbutton.LevelSprite.setTextureRect(sf::IntRect(35,100,280,100));
	playbutton.LevelSprite.setPosition(450, 500);
	
	for (int i = 0; i < 6; i++) {
		disabled[i].loadFromFile("Images/level_disabled.jpg");
		mainMenu[i].LevelTexture.loadFromFile("Images/Levels1.jpeg");
		mainMenu[i].LevelSprite.setTextureRect(sf::IntRect((i % 2) * 250 + width, (i / 2) * 99 + height, 200, 70));
		mainMenu[i].LevelSprite.setPosition(posX + ((i % 2) * 210), posY + ((i / 2) * 110));
	}
	mainMenu[6].LevelTexture.loadFromFile("Images/ins2.png");
	mainMenu[6].LevelSprite.setTexture(mainMenu[6].LevelTexture);
	mainMenu[6].LevelSprite.setTextureRect(sf::IntRect(0, 0,115,115));
	mainMenu[6].LevelSprite.setPosition(100,10);
	mainMenu[7].LevelTexture.loadFromFile("Images/prof.png");
	mainMenu[7].LevelSprite.setTexture(mainMenu[7].LevelTexture);
	mainMenu[7].LevelSprite.setTextureRect(IntRect(0,0,115,115));
	mainMenu[7].LevelSprite.setPosition(100,580);
	mainMenu[8].LevelTexture.loadFromFile("Images/scoringpic3.png");
	mainMenu[8].LevelSprite.setTexture(mainMenu[8].LevelTexture);
	mainMenu[8].LevelSprite.setPosition(60, 200);

	MainMenuSelected = -1;
	gameStart = false;
	scorecreated = false;
	gamescore = new Score();
}
void Game::start(RenderWindow& window) {
	
	while (window.isOpen())
	{
		bool levelcheck = false;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (gameStart == false && (handleMouseStart(window, event))) {
				gameStart = true;
				window.clear();
				levelcheck = true;
				drawProfile(window, levelcheck);
				drawMainMenu(window);
				window.display();
			}
			

			if (gameStart == true && handleLevel(window, event)) {
				int x = MainMenuPressed();
				if (x < 6) {
					levelcheck = true;
					
					while (levelcheck == true) {
						if (playlevel == NULL) {
							if (x == 0) {
								playlevel = new BegginersGarden;
							}
							else if (x == 1) {
								playlevel = new ZombieOutskirts;
							}
							if (x == 2) {
								playlevel = new SunflowerFeilds;
							}
							if (x == 3) {
								playlevel = new FoggyForest;
							}
							if (x == 4) {
								playlevel = new NighttimeSeIge;
							}
							if (x == 5) {
								playlevel = new Level6;
							}
						}
						window.clear();
						playlevel->manageGameLogic(window);
						
						
						Event aevent;
						while (window.pollEvent(aevent))
						{
							if (aevent.type == Event::Closed)
								window.close();
							if (playlevel->handleEvents(window, aevent)) {
								levelcheck = false;
							}
							
						}
						if (playlevel->checkLooseCondition()) {
							drawLostScreen(window, levelcheck);
						}
						else if (playlevel->checkWinCondition(window)) {
							gamescore->incrementscorelevel1();
							drawWonScreen(window, levelcheck);
							if (x < 5) {
								if (enabled[x + 1] == false) {
									enabled[x + 1] = true;
								}
								if (levelcheck == true) {
									window.clear();
									x++;
								}
							}
							else if (x == 5) {
								levelcheck = false;
							}

						}
						window.display();
					}
				}
				else {
					levelcheck = true;
					while (levelcheck == true) {
						window.clear();
						if (x == 6) {
							drawIns(window);
						}
						else if (x == 7) {
							drawProfile(window,levelcheck);
						}
						else if (x == 8) {
							drawHighScoreScreen(window);
						}
						if (x == 6 || x==8) {
							Event aevent;
							while (window.pollEvent(aevent))
							{
								if (aevent.type == Event::Closed)
									window.close();
								if (handleMouseIns(window, aevent)) {
									levelcheck = false;
								}
							}
						}
						window.display();
					}
				}
			}

		}
		window.clear();
		if (gameStart == false) {
			drawStartScreen(window);
		}
		else {
			drawMainMenu(window);
		}
		window.display();

		//window.setSize(sf::Vector2u(1100, 680));
	}
	
}
void Game::drawWonScreen(RenderWindow& window, bool& levelcheck) {
	Texture won;
	won.loadFromFile("Images/winloose.png");
	Sprite wonSprite;
	wonSprite.setTexture(won);
	wonSprite.setPosition(300, 50);
	window.draw(wonSprite);
	sf::Text wonText;
	wonText.setString("You Win!!!");
	wonText.setFont(font1);
	wonText.setCharacterSize(100);
	wonText.setFillColor(sf::Color::Black);
	wonText.setPosition(350, 50);
	window.draw(wonText);
	sf::Texture next;
	next.loadFromFile("Images/next.png");
	sf::Sprite nextSprite;
	nextSprite.setTexture(next);
	nextSprite.setPosition(400, 240);
	window.draw(nextSprite);
	Texture menuB;
	Sprite menuBSprite;
	menuB.loadFromFile("Images/menuB.jpeg");
	menuBSprite.setTexture(menuB);
	menuBSprite.setPosition(350, 380);
	window.draw(menuBSprite);
	window.display();
	sf::Event event;
	while (!(levelcheck == false || playlevel == NULL)) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;

				if (event.mouseButton.x >= 400 && event.mouseButton.x <= 400 + 250 &&
					event.mouseButton.y >= 240 && event.mouseButton.y <= 240 + 90) {
					delete playlevel;
					playlevel = NULL;
				}
				if (event.mouseButton.x >= 350 && event.mouseButton.x <= 350 + 350 &&
					event.mouseButton.y >= 380 && event.mouseButton.y <= 380 + 90) {
					levelcheck = false;
				}
			}
		}
	}
}
void Game::drawLostScreen(RenderWindow& window, bool& levelcheck) {
	sf::Texture lost;
	lost.loadFromFile("Images/winloose.png");
	sf::Sprite lostSprite;
	lostSprite.setTexture(lost);
	lostSprite.setPosition(300, 50);
	window.draw(lostSprite);
	sf::Text lostText;
	lostText.setString("You Loose!!!");
	lostText.setFont(font1);
	lostText.setCharacterSize(90);
	lostText.setFillColor(sf::Color::Black);
	lostText.setPosition(350, 50);
	window.draw(lostText);
	sf::Texture restart;
	restart.loadFromFile("Images/restart.jpg");
	sf::Sprite restartSprite;
	restartSprite.setTexture(restart);
	restartSprite.setPosition(400, 240);
	window.draw(restartSprite);
	Texture menuB;
	Sprite menuBSprite;
	menuB.loadFromFile("Images/menuB.jpeg");
	menuBSprite.setTexture(menuB);
	menuBSprite.setPosition(350, 380);
	window.draw(menuBSprite);
	window.display();
	sf::Event event;
	while (!(levelcheck == false || playlevel == NULL)) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				int mouseX = event.mouseButton.x;
				int mouseY = event.mouseButton.y;

				if (event.mouseButton.x >= 400 && event.mouseButton.x <= 400 + 250 &&
					event.mouseButton.y >= 250 && event.mouseButton.y <= 240 + 90) {
					delete playlevel;
					playlevel = NULL;
				}
				if (event.mouseButton.x >= 350 && event.mouseButton.x <= 350 + 350 &&
					event.mouseButton.y >= 380 && event.mouseButton.y <= 380 + 90) {
					levelcheck = false;
				}
			}
		}
	}
}
bool Game::handleLevel(RenderWindow& window, Event event) {
	if (event.type == Event::MouseButtonPressed) {
		int mouseX = event.mouseButton.x;
		int mouseY = event.mouseButton.y;
		// Define the region of your play icon
		for (int i = 0; i < 9; i++) {
			int iconLeft = mainMenu[i].LevelSprite.getPosition().x;
			int iconTop = mainMenu[i].LevelSprite.getPosition().y;
			int iconWidth;
			int iconHeight;
			if (i < 6) {
				iconWidth = 200;
				iconHeight = 60;
			}
			else if (i == 8)
			{
				iconWidth = 191;
				iconHeight = 247;
			}

			else {
				iconWidth = 80;
				iconHeight = 80;
			}
			if (mouseX >= iconLeft && mouseX <= iconLeft + iconWidth &&
				mouseY >= iconTop && mouseY <= iconTop + iconHeight) {
				if (i < 6) {
					if (playlevel != nullptr) {
						delete playlevel;
						
					}
					
					playlevel = NULL;
				}
				MainMenuSelected = i;
				if (i < 6 && enabled[i])
					return true;
				else if (i > 5)
					return true;
			}
		}

	}
	return false;
}

bool Game::handleMouseStart(RenderWindow& window, Event event) {

	if (event.type == Event::MouseButtonPressed) {
		int mouseX = event.mouseButton.x;
		int mouseY = event.mouseButton.y;
		// Define the region of your play icon
			int iconLeft = playbutton.LevelSprite.getPosition().x;
			int iconTop = playbutton.LevelSprite.getPosition().y;
			int iconWidth = 280;
			int iconHeight = 120;
			if (mouseX >= iconLeft && mouseX <= iconLeft + iconWidth &&
				mouseY >= iconTop && mouseY <= iconTop + iconHeight) {
				return true;
			}
	}
	return false;
}
bool Game::handleMouseIns(RenderWindow& window, Event event) {

	if (event.type == Event::MouseButtonPressed) {
		int mouseX = event.mouseButton.x;
		int mouseY = event.mouseButton.y;
		// Define the region of your play icon
		int iconLeft = 450;
		int iconTop = 600;
		int iconWidth = 260;
		int iconHeight = 100;
		if (mouseX >= iconLeft && mouseX <= iconLeft + iconWidth &&
			mouseY >= iconTop && mouseY <= iconTop + iconHeight) {
			return true;
		}
	}
	return false;
}
void Game::drawMainMenu(RenderWindow& window) {
	//Drawing the background
	Image bg_image;
	bg_image.loadFromFile("Images/MainMenu.png");
	Texture bg;
	bg.loadFromImage(bg_image);
	Sprite s_bg;
	s_bg.setTexture(bg);
	s_bg.setPosition(0, 0);
	window.draw(s_bg);
	sf::Font font;
	font.loadFromFile("Images/Font.ttf");
	sf::Text text;
	text.setFont(font);
	text.setString("Adventure!");
	text.setCharacterSize(88);
	text.setFillColor(sf::Color::White);
	text.setPosition(660, 70);
	window.draw(text);
	
	for (int i = 0; i < 9; i++) {

		if (i < 6) {
			if (enabled[i]) {
				mainMenu[i].LevelSprite.setTexture(mainMenu[i].LevelTexture);
				//cout << i << "enabled";
			}
			else {
				mainMenu[i].LevelSprite.setTexture(disabled[i]);
				//cout << i << "disabled";
			}
		}
		window.draw(mainMenu[i].LevelSprite);
	}
}
void Game::drawStartScreen(RenderWindow& window) {
	menuItem startScreen;
	startScreen.LevelTexture.loadFromFile("Images/bgop1.jpeg");
	startScreen.LevelSprite.setTexture(startScreen.LevelTexture);
	startScreen.LevelSprite.setPosition(0, 0);
	window.draw(startScreen.LevelSprite);
	window.draw(playbutton.LevelSprite);
}
void Game::drawProfile(RenderWindow& window, bool& levelcheck ) {
	//window.clear();
	Texture menuB;
	Sprite menuBSprite;
	menuB.loadFromFile("Images/menuB.jpeg");
	menuBSprite.setTexture(menuB);
	menuBSprite.setPosition(450, 600);
	menuItem Screen;
	//Screen.LevelTexture.loadFromFile("Images/bgop2.jpeg");
	Screen.LevelTexture.loadFromFile("Images/profilebg1.jpeg");
	Screen.LevelSprite.setTexture(Screen.LevelTexture);

	Screen.LevelSprite.setPosition(0, 0);
	
	sf::RectangleShape textBox(sf::Vector2f(400, 50));
	textBox.setPosition(400, 300);
	textBox.setFillColor(sf::Color::White);
	textBox.setOutlineThickness(1);
	textBox.setOutlineColor(sf::Color::Black);
	sf::Text nameText;
	nameText.setString("Name");
	nameText.setFont(font1);
	nameText.setCharacterSize(40);
	nameText.setFillColor(sf::Color::Black);
	nameText.setPosition(textBox.getPosition().x - 100, textBox.getPosition().y);

	inputText.setPosition(textBox.getPosition().x, textBox.getPosition().y);
	inputText.setFillColor(sf::Color::Red);
	sf::RectangleShape passwordBox(sf::Vector2f(400, 50));
	passwordBox.setPosition(400, 400);
	passwordBox.setFillColor(sf::Color::White);
	passwordBox.setOutlineThickness(1);
	passwordBox.setOutlineColor(sf::Color::Black);
	sf::Text passwordTextagain;
	passwordTextagain.setString("Password");
	passwordTextagain.setFont(font1);
	passwordTextagain.setCharacterSize(40);
	passwordTextagain.setFillColor(sf::Color::Black);
	passwordTextagain.setPosition(passwordBox.getPosition().x - 140, passwordBox.getPosition().y);
	passwordText.setPosition(passwordBox.getPosition().x, passwordBox.getPosition().y);
	passwordText.setFillColor(sf::Color::Red);

	sf::Text profileDetailsText;
	profileDetailsText.setString("Your Profile Details");
	profileDetailsText.setFont(font1);
	profileDetailsText.setCharacterSize(80);
	profileDetailsText.setFillColor(sf::Color::Black);
	profileDetailsText.setPosition(300, 50);





	//bool textBoxClicked = false;
	sf::Event event;
	while (levelcheck == true) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {

					sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

					if (mousePosition.x >= textBox.getPosition().x && mousePosition.x <= textBox.getPosition().x + textBox.getSize().x &&
						mousePosition.y >= textBox.getPosition().y && mousePosition.y <= textBox.getPosition().y + textBox.getSize().y) {
						textBoxClicked = true;
						passwordBoxClicked = false;

						//cout << "click detectd";
					}
					else if (mousePosition.x >= passwordBox.getPosition().x && mousePosition.x <= passwordBox.getPosition().x + passwordBox.getSize().x &&
						mousePosition.y >= passwordBox.getPosition().y && mousePosition.y <= passwordBox.getPosition().y + passwordBox.getSize().y) {
						passwordBoxClicked = true;
						textBoxClicked = false;
					}
					else {
						textBoxClicked = false;
						passwordBoxClicked = false;

					}
				}
			}
			if (event.type == sf::Event::TextEntered) {
				if (textBoxClicked)
				{


					if (event.text.unicode < 128 && event.text.unicode != '\b') {

						userInput += static_cast<char>(event.text.unicode);
						inputText.setString(userInput);
						//cout << "input being taken";
					}
					else if (event.text.unicode == '\b' && !userInput.empty()) {

						userInput.pop_back();
						inputText.setString(userInput);
					}
				}
				else if (passwordBoxClicked)
				{
					if (event.text.unicode < 128 && event.text.unicode != '\b') {
						userinput2 += static_cast<char>(event.text.unicode);
						passwordText.setString(userinput2);
					}
					else if (event.text.unicode == '\b' && !userinput2.empty()) {
						userinput2.pop_back();
						passwordText.setString(userinput2);
					}

				}
				

			}
			if (handleMouseIns(window, event) && userInput!="" && userinput2 !="") {

				ifstream readFile("players2.txt");
				ofstream writeFile("new_players.txt", ios::app);

				string line;
				bool nameAndPasswordMatch1 = false;

				while (getline(readFile, line)) {
					istringstream iss(line);
					string name, password, dummy;
					getline(iss, name, ',');
					getline(iss, password, ',');
					getline(iss, dummy);

					// Check if the name already exists in the file
					if (name == userInput && password==userinput2) {
						nameAndPasswordMatch1 = true;
					}

					// Copy the existing data to new_players.txt
					writeFile << line << endl;
				}
				readFile.close();
				// If the name doesn't exist, add it to new_players.txt
				if (!nameAndPasswordMatch1) {
					writeFile << userInput << "," << userinput2 << "," << 0 << endl;
				}


				writeFile.close();

				// Remove the original file
				remove("players2.txt");

				// Rename the new file
				rename("new_players.txt", "players2.txt");
				levelcheck = false;
			}
		}
		window.draw(Screen.LevelSprite);
		window.draw(menuBSprite);
		window.draw(textBox);
		window.draw(inputText);
		window.draw(nameText);
		window.draw(passwordBox);
		window.draw(passwordText);
		window.draw(passwordTextagain);
		window.draw(profileDetailsText);
		window.display();
	}
	if (!scorecreated)
	{
		//gamescore = new Score(userInput, userinput2);
		gamescore->setnameandpass(userInput, userinput2);
		scorecreated = true;
	}

	//cout << userInput;
	

}
void Game::drawIns(RenderWindow& window) {
	menuItem Screen;
	Screen.LevelTexture.loadFromFile("Images/Ins.jpeg");
	Screen.LevelSprite.setTexture(Screen.LevelTexture);
	Screen.LevelSprite.setPosition(50, 0);
	window.draw(Screen.LevelSprite);
	
}
int Game::MainMenuPressed() {
	return MainMenuSelected;
}
Game::~Game() {
	if(playlevel!=nullptr)
	delete playlevel;
}
void Game::drawHighScoreScreen(RenderWindow& window) {
	Texture menuB;
	Sprite menuBSprite;
	menuB.loadFromFile("Images/menuB.jpeg");
	menuBSprite.setTexture(menuB);
	menuBSprite.setPosition(450, 600);



	menuItem highScoreScreen;
	highScoreScreen.LevelTexture.loadFromFile("Images/highsbg.jpg");
	highScoreScreen.LevelSprite.setTexture(highScoreScreen.LevelTexture);
	highScoreScreen.LevelSprite.setPosition(0, 0);
	window.draw(highScoreScreen.LevelSprite);
	window.draw(menuBSprite);
	Text highScoreText("High Scores", font1, 80);
	highScoreText.setFillColor(Color::Red);
	highScoreText.setPosition(450, 0); // Adjust the position as needed

	// Draw the "High Scores" text
	window.draw(highScoreText);
	gamescore->sortScores();
	//gamescore->sortScores();
	ifstream readFile("players2.txt");
	if (!readFile.is_open()) {
		cout << "Error opening file\n";
		return;
	}

	// Array to store player data
	struct Player {
		string name;
		int score;
	} players[3];

	// Read player data from file
	string line;
	int count = 0;
	while (getline(readFile, line) && count < 3) {
		istringstream iss(line);
		string name, password, scoreStr;
		getline(iss, name, ',');
		getline(iss, password, ',');
		getline(iss, scoreStr, ',');
		name.erase(0, name.find_first_not_of(" \t\r\n"));
		name.erase(name.find_last_not_of(" \t\r\n") + 1);
		scoreStr.erase(0, scoreStr.find_first_not_of(" \t\r\n"));
		scoreStr.erase(scoreStr.find_last_not_of(" \t\r\n") + 1);
		int score = stoi(scoreStr);
		players[count].name = name;
		players[count].score = score;
		count++;
	}

	// Close the file
	readFile.close();

	// Sort players by score
	for (int i = 0; i < 2; i++) {
		for (int j = i + 1; j < 3; j++) {
			if (players[i].score < players[j].score) {
				//swap(players[i], players[j]);
				Player temp = players[i];
				players[i] = players[j];
				players[j] = temp;
			}
		}
	}
	Texture texture1;
	texture1.loadFromFile("Images/gold.png");
	Texture texture2;
	texture2.loadFromFile("Images/silver.png");
	Texture texture3;
	texture3.loadFromFile("Images/bronze.png");
	// Display top 3 scores
	int x = 450, y = 200;
	for (int i = 0; i < 3; i++) {
		Text text(players[i].name + " - " + to_string(players[i].score), font1, 50);
		text.setPosition(x, y);
		//text.setFillColor(Color::Magenta);
		text.setFillColor(Color(255, 192, 203, 200));
		window.draw(text);
		Sprite badgeSprite;
		if (i == 0) {
			badgeSprite.setTexture(texture1); // Assuming texture1 is the texture for the first badge
		}
		else if (i == 1) {
			badgeSprite.setTexture(texture2); // Assuming texture2 is the texture for the second badge
		}
		else {
			badgeSprite.setTexture(texture3); // Assuming texture3 is the texture for the third badge
		}
		badgeSprite.setPosition(x + 210, y + 40); // Adjust the position as needed
		window.draw(badgeSprite);

		y += 100; //access violation reading here exception thrown 
	}



}