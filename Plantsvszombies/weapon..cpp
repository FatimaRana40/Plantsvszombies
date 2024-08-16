#include "weapon.h"
#include "weapon.h"

Weapon::Weapon() {
    isActivev = false;
    weaponCoordinates.x = 0;
    weaponCoordinates.y = 0;
}

void Weapon::setTexture(const sf::Texture& texture) {
    weaponTexture = texture;
    weaponSprite.setTexture(weaponTexture);
}

void Weapon::setSound(const std::string& soundFilePath) {
    if (!weaponBuffer.loadFromFile(soundFilePath)) {
        // Failed to load sound file
        std::cerr << "Failed to load weapon sound file: " << soundFilePath << std::endl;
    }
    weaponSound.setBuffer(weaponBuffer);
}

void Weapon::shoot(float x, float y) {
    weaponCoordinates.x = x;
    weaponCoordinates.y = y;
    isActivev = true;
    weaponSound.play(); // Play the weapon sound
}

void Weapon::update() {
    if (isActivev) {
        // Update position or other logic here
        weaponCoordinates.x += 5; // Example: Move the weapon to the right
        if (weaponCoordinates.x > 1200) {
            isActivev = false; // Deactivate the weapon
        }
    }
}

void Weapon::draw(sf::RenderWindow& window) {
    if (isActivev) {
        weaponSprite.setPosition(weaponCoordinates.x, weaponCoordinates.y);
        window.draw(weaponSprite);
    }
}

bool Weapon::isActive() {
    return isActivev;
}

void Weapon::setActive(bool active) {
    isActivev = active;
}
void Weapon::setPosition(float x, float y) {
    weaponCoordinates.x = x;
    weaponCoordinates.y = y;
}
coordinates3 Weapon::getCoordinates()
{
    return weaponCoordinates;
}
void Weapon::hit()
{
    temptexture.loadFromFile("Images/peadestroy.png");
    hittingbuffer.loadFromFile("audio/tap.wav");
    hittingsound.setBuffer(hittingbuffer);
    hittingsound.play();
    ishit = true;
    //weaponSprite.setTexture(temptexture);

    isActivev = false;

}
void Weapon::reset()
{
    ishit = false;
    weaponSprite.setTexture(weaponTexture);

}
bool Weapon::checkifhit()
{
    return ishit;
}
