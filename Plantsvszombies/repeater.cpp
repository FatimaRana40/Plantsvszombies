#include"Plants.h"
#include "repeater.h"


Repeater::Repeater() {
    shootingInterval = 2;
    shootingSpeed = 20;
    lastRepeaterIndex = 0;
    plantTexture.loadFromFile("Images/rept.png");
    plantSprite.setTexture(plantTexture);
    positionP.x = 100;
    positionP.y = 100;
    price = 200;
    n = 5;
    plantdead = false;
    currentTextureIndex = 0;
    health = 200;
    // Load repeater texture and sound
    sf::Texture repeaterTexture;
    if (!repeaterTexture.loadFromFile("Images/pear.png")) {
        std::cerr << "Failed to load repeater texture!" << std::endl;
    }
    sf::SoundBuffer repeaterBuffer;
    if (!repeaterBuffer.loadFromFile("audio/plant1.wav")) {
        std::cerr << "Failed to load repeater sound!" << std::endl;
    }

    // Initialize repeaters
    for (int i = 0; i < 10; ++i) {
        myrepeater[i].setTexture(repeaterTexture);
        myrepeater[i].setSound("audio/plant1.wav");
        myrepeater[i].setActive(false);
        myrepeater[i].setPosition(positionP.x, positionP.y);
    }
    for (int i = 0; i < 5; ++i) {
        std::string path = "Images/repeater/myrep" + std::to_string(i + 1) + ".png";
        peaTextures[i].loadFromFile(path);
    }
}

void Repeater::ShootPea() {
    if (shootTimer.getElapsedTime().asSeconds() >= 2.0f) {
        for (int i = 0; i < 10; ++i) {
            if (!myrepeater[i].isActive()) {
                myrepeater[i].shoot(positionP.x, positionP.y);
                lastRepeaterIndex = (lastRepeaterIndex + 1) % 10;
                shootTimer.restart();
                break;
            }
        }
    }
}

void Repeater::update() {
    for (int i = 0; i < 10; ++i) {
        if (myrepeater[i].isActive()) {
            myrepeater[i].update();
        }
    }
    if (timer.getElapsedTime().asSeconds() >= 0.3f) {
        timer.restart();
        currentTextureIndex = (currentTextureIndex + 1) % 5; // Assuming you have 5 textures for peashooter animation
        plantSprite.setTexture(peaTextures[currentTextureIndex]);
    }
}

void Repeater::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 10; ++i) {
        myrepeater[i].draw(window);
    }
}
int Repeater::getCurrency()
{
    return price;
}
bool Repeater::isActive()
{
    return true;
}
void Repeater::collect(Event& event, int& currency)
{

}
void Repeater::displayplant(sf::RenderWindow& window) {
    plantSprite.setPosition(positionP.x, positionP.y);
    window.draw(plantSprite);

}
bool Repeater::detectcollision(coordinates c)
{
    for (int i = 0; i < 10; ++i) {
        float peaX = myrepeater[i].getCoordinates().x;
        float peaY = myrepeater[i].getCoordinates().y;


        // if (peaX >= c.x + 20){

        if (peaX >= c.x && peaX <= c.x + 10 && peaY - c.y <= 60 && peaY - c.y >= 0 && myrepeater[i].isActivev)
        {

            myrepeater[i].hit();
            return true;
        }
    }
    return false;
}