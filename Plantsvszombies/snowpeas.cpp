#include "Plants.h"
#include "snowpeas.h"


SnowPea::SnowPea() {
    shootingInterval = 2;
    shootingSpeed = 20;
    positionP.x = 80;
    positionP.y = 80;
    lastSnowPeaIndex = 0;
    currentTextureIndex = 1;
    plantTexture.loadFromFile("Images/snow.png");
    plantSprite.setTexture(plantTexture);
    price = 175;
    n = 4;
    health = 200;
    plantdead = false;
    // Load snow pea texture and sound
    sf::Texture snowpeaTexture;
    if (!snowpeaTexture.loadFromFile("Images/spea.png")) {
        std::cerr << "Failed to load snow pea texture!" << std::endl;
    }
    sf::SoundBuffer snowpeaBuffer;
    if (!snowpeaBuffer.loadFromFile("audio/frozen.wav")) {
        std::cerr << "Failed to load snow pea sound!" << std::endl;
    }

    // Initialize snow peas
    for (int i = 0; i < 10; ++i) {
        mysnowpea[i].setTexture(snowpeaTexture);
        mysnowpea[i].setSound("audio/frozen.wav");
        mysnowpea[i].setActive(false);
        mysnowpea[i].setPosition(positionP.x, positionP.y);
    }
    for (int i = 0; i < 5; ++i) {
        std::string path = "Images/snowpea/mysnowpea" + std::to_string(i + 1) + ".png";
        peaTextures[i].loadFromFile(path);
    }
}

void SnowPea::ShootPea() {
    if (shootTimer.getElapsedTime().asSeconds() >= 2.0f) {
        for (int i = 0; i < 10; ++i) {
            if (!mysnowpea[i].isActive()) {
                mysnowpea[i].shoot(positionP.x, positionP.y);
                lastSnowPeaIndex = (lastSnowPeaIndex + 1) % 10;
                shootTimer.restart();
                break;
            }
        }
    }
}

void SnowPea::update() {
    for (int i = 0; i < 10; ++i) {
        if (mysnowpea[i].isActive()) {
            mysnowpea[i].update();
        }
    }
    if (timer.getElapsedTime().asSeconds() >= 0.3f) {
        timer.restart();
        currentTextureIndex = (currentTextureIndex + 1) % 5; // Assuming you have 5 textures for peashooter animation
        plantSprite.setTexture(peaTextures[currentTextureIndex]);
    }
}

void SnowPea::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 10; ++i) {

        mysnowpea[i].draw(window);
    }
}
int SnowPea::getCurrency()
{
    return price;
}
bool SnowPea::isActive()
{
    return true;
}
void SnowPea::collect(Event& event, int& currency)
{

}
void SnowPea::displayplant(sf::RenderWindow& window) {
    plantSprite.setPosition(positionP.x, positionP.y);
    window.draw(plantSprite);
}
bool SnowPea::detectcollision(coordinates c)
{
    for (int i = 0; i < 10; ++i) {
        float peaX = mysnowpea[i].getCoordinates().x;
        float peaY = mysnowpea[i].getCoordinates().y;


        // if (peaX >= c.x + 20){

        if (peaX >= c.x && peaX <= c.x + 10 && peaY - c.y <= 60 && peaY - c.y >= 0 && mysnowpea[i].isActivev)
        {

            mysnowpea[i].hit();
            return true;
        }
    }
    return false;
}