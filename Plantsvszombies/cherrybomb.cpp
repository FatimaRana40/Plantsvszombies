#include "Plants.h"
#include "cherrybomb.h"


CherryBomb::CherryBomb() {
    //explosionrange = 3;
    	//health = 30;
    	positionP.x = 850;
    	positionP.y = 850;
    	price = 150;
        n = 3;
    	plantTexture.loadFromFile("Images/cherry.png");
    	plantSprite.setTexture(plantTexture);
        plantdead = false;
    active = false; 
    exploding = false;
    hasExploded = false;
    explosionTimer.restart();
    // Initially, the cherry bomb is not active

    // Load the cherry bomb texture
    if (!explosionTexture.loadFromFile("Images/bomb.jpeg")) {
        // Failed to load cherry bomb texture
        std::cerr << "Failed to load cherry bomb texture!" << std::endl;
    }

    // Set the cherry bomb sprite texture
    explosionSprite.setTexture(explosionTexture);

    // Load the explosion sound
    if (!explosionBuffer.loadFromFile("audio/ignite.wav")) {
        // Failed to load explosion sound
        std::cerr << "Failed to load explosion sound!" << std::endl;
    }

    // Set the explosion sound buffer
    explosionSound.setBuffer(explosionBuffer);
}

 int CherryBomb::getCurrency()
{
     return price;
}
void CherryBomb::update() {
    if (active && !exploding) {
       

        if (explosionTimer.getElapsedTime().asSeconds() >= 2.0f) {
            explode(); // If three seconds have passed, explode
        }
    }
}
void CherryBomb::explode() {
    active = true;
    exploding = true;
    //plantSprite.setTexture(explosionTexture); // Change texture to explosion image
    explosionSound.play(); // Play explosion sound

    

}
bool CherryBomb::getExploding() {
    return (active&&!hasExploded);
}
bool CherryBomb::isActive()
{
    return active;
}
void CherryBomb::draw(sf::RenderWindow& window) {
    if (exploding && !hasExploded) {
        // If not active, draw the explosion sprite (initial display)
        explosionSprite.setPosition(positionP.x, positionP.y);
        window.draw(explosionSprite);
        hasExploded = true;
        /*plantSprite.setTexture(explosionTexture);
        displayplant(window);*/
    }
    else if (hasExploded) {
        explosionSprite.setPosition(-100, -100);
    }

    else {
        // If active, draw the plant sprite (explosion)
       /* displayplant(window);*/
        plantSprite.setPosition(positionP.x, positionP.y);
        window.draw(plantSprite);
        //window.draw(plantSprite);

    }
   
    

}
void CherryBomb::setactive() {
    active = true;
}
void CherryBomb::ShootPea()
{

}
void CherryBomb::collect(Event& event, int& currency)
{

}
void CherryBomb::displayplant(sf::RenderWindow& window) {
    //plantSprite.setPosition(positionP.x, positionP.y);
    //window.draw(plantSprite);
}