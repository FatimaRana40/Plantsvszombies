#include "Plants.h"
#include "peashooter.h"


Peashooter::Peashooter() {
    shootingInterval = 2;
    shootingspeed = 20;
    lastPeaIndex = 0;
    positionP.x = 0;
    positionP.y = 0;
    price = 100;
    health = 150;
    plantdead = false;
    n = 0;
    currentTextureIndex = 0;
    plantTexture.loadFromFile("Images/peashooter.png");
    plantSprite.setTexture(plantTexture);
    if (!weapontext.loadFromFile("Images/pea.png")) {
        // Failed to load weapon texture
        std::cerr << "Failed to load weapon texture!" << std::endl;
    }

    for (int i = 0; i < 10; ++i) {
        mypea[i].setTexture(weapontext); // Set pea texture
        mypea[i].setSound("audio/firepea.wav"); // Set pea sound
        mypea[i].setActive(false); // Initially, no pea is active
        mypea[i].setPosition(0, 0); // Set initial position of pea

    }
    for (int i = 0; i < 5; ++i) {
        std::string path = "Images/peashooter/mypea" + std::to_string(i + 1) + ".png";
        peaTextures[i].loadFromFile(path);
    }
}

void Peashooter::ShootPea() {
    if (shootTimer.getElapsedTime().asSeconds() >= 1.5f + 0.5*(rand()%3)) {
        for (int i = 0; i < 10; ++i) {
            if (!mypea[i].isActive()) {
                mypea[i].shoot(positionP.x, positionP.y); // Shoot the pea from the peashooter's position
               
                lastPeaIndex = (lastPeaIndex + 1) % 10; // Move to the next index in the array
                shootTimer.restart(); // Restart the clock
                break; // Exit the loop after shooting one pea
            }
        }
    }
}

void Peashooter::update() {
    for (int i = 0; i < 10; ++i) {
        if (mypea[i].isActive()) {
            mypea[i].update(); // Update all peas
        }
        //updated
        if (mypea[i].checkifhit()) {
            mypea[i].reset(); // Reset pea immediately
        }
        //endofupdate
    }
    if (timer.getElapsedTime().asSeconds() >= 0.3f) {
        timer.restart();
        currentTextureIndex = (currentTextureIndex + 1) % 5; // Assuming we have 5 textures for peashooter animation
        plantSprite.setTexture(peaTextures[currentTextureIndex]);
    }

}

void Peashooter::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 10; ++i) {
        mypea[i].draw(window); // Draw all peas
    }
}
int Peashooter::getCurrency()
{
    return price;
}
bool Peashooter:: isActive()
{
    return true;
}
void Peashooter::collect(Event& event, int& currency)
{

}
void Peashooter::displayplant(sf::RenderWindow& window) {
    plantSprite.setPosition(positionP.x, positionP.y);
    window.draw(plantSprite);
}
bool Peashooter:: detectcollision(coordinates c)
{
    for (int i = 0; i < 10; ++i) {
        float peaX = mypea[i].getCoordinates().x;
        float peaY = mypea[i].getCoordinates().y;

        
       // if (peaX >= c.x + 20){

         if(peaX >= c.x && peaX <= c.x + 10 && peaY - c.y <= 60 && peaY- c.y>= 0 && mypea[i].isActivev)
         {

            mypea[i].hit();
            return true; 
        }
    }
    return false; 
}

