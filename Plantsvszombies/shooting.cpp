#include"header.h"
void Shooting::movement(int m)
{
	shootingcoordinates.x += 10;
}
void Shooting::drawShootingDevice(RenderWindow& window)
{	
	shootingsprite.setPosition(shootingcoordinates.x, shootingcoordinates.y);
	window.draw(shootingsprite);

}
void Shooting::update() {
    // Update the position of the pea based on its speed
    shootingcoordinates.x +=10; // Move the pea horizontally
}
void Shooting::shoot()
{
    shootingcoordinates.x = 0; // Set initial x-position to the left side of the window
    shootingcoordinates.y = 0;
}
void Shooting::playShootingSound() {
    
    sound.play();
}
coordinates Shooting:: getShootingCoordinates() {
    return shootingcoordinates;
}

// Getter function for shooting texture
Texture& Shooting::getShootingTexture() {
    return shootingtexture;
}
