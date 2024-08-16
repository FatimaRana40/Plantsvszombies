#include "Fumeshroom.h"
#include "FumeShroom.h"

FumeShroom::FumeShroom() {
    shootingInterval = 2;
    shootingspeed = 20;
    lastFumeIndex = 0;
    positionP.x = 0;
    positionP.y = 0;
    price = 300;
    health = 200;
    plantdead = false;
    n = 0;
    currentTextureIndex = 0;
    plantTexture.loadFromFile("Images/fumeshroom.gif");
    plantSprite.setTexture(plantTexture);
    if (!weapontext.loadFromFile("Images/poison.png")) {
        // Failed to load weapon texture
        std::cerr << "Failed to load weapon texture!" << std::endl;
    }

    for (int i = 0; i < 10; ++i) {
        fume[i].setTexture(weapontext); // Set fume texture
        fume[i].setSound("audio/bleep.wav"); // Set fume sound
        fume[i].setActive(false); // Initially, no fume is active
        fume[i].setPosition(0, 0); // Set initial position of fume
    }
    for (int i = 0; i < 16; ++i) {
        std::string path = "Images/fumeshroom/myfume (" + std::to_string(i + 1) + ").gif";
        fumeTextures[i].loadFromFile(path);
    }
}

void FumeShroom::ShootPea() {
    if (shootTimer.getElapsedTime().asSeconds() >= 1.5f + 0.5 * (rand() % 3)) {
        for (int i = 0; i < 10; ++i) {
            if (!fume[i].isActive()) {
                fume[i].shoot(positionP.x, positionP.y); // Shoot the fume from the fumeshroom's position
                lastFumeIndex = (lastFumeIndex + 1) % 10; // Move to the next index in the array
                shootTimer.restart(); // Restart the clock
                break; // Exit the loop after shooting one fume
            }
        }
    }
}

void FumeShroom::update() {
    for (int i = 0; i < 10; ++i) {
        if (fume[i].isActive()) {
            fume[i].update(); // Update all fumes
        }
        if (fume[i].checkifhit()) {
            fume[i].reset(); // Reset fume immediately if it hits
        }
    }
    if (timer.getElapsedTime().asSeconds() >= 0.3f) {
        timer.restart();
        currentTextureIndex = (currentTextureIndex + 1) % 16; // Assuming we have 16 textures for fume animation
        plantSprite.setTexture(fumeTextures[currentTextureIndex]);
    }
}

void FumeShroom::draw(sf::RenderWindow& window) {
    for (int i = 0; i < 10; ++i) {
        fume[i].draw(window); // Draw all fumes
    }
}

int FumeShroom::getCurrency() {
    return price;
}

bool FumeShroom::isActive() {
    return true; 
}

void FumeShroom::collect(Event& event, int& currency) {
    
}

void FumeShroom::displayplant(sf::RenderWindow& window) {
    plantSprite.setPosition(positionP.x, positionP.y);
    window.draw(plantSprite);
}

bool FumeShroom::detectcollision(coordinates c) {
    for (int i = 0; i < 10; ++i) {
        float fumeX = fume[i].getCoordinates().x;
        float fumeY = fume[i].getCoordinates().y;

        if (fumeX >= c.x && fumeX <= c.x + 20 && fumeY - c.y <= 60 && fumeY - c.y >= 0 && fume[i].isActivev) {
            fume[i].hit();
            return true;
        }
    }
    return false;
}
