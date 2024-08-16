#pragma once
#ifndef WEAPON_H
#define WEAPON_H
//using namespace sf;
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>


struct coordinates3 {
    float x;
    float y;
};

class Weapon {
protected:
    /*bool isActivev;*/
    sf::Texture weaponTexture;
    sf::Sprite weaponSprite;
    sf::Sound weaponSound;
    sf::SoundBuffer weaponBuffer;
    coordinates3 weaponCoordinates;
    sf::Texture temptexture;
    sf::Sound hittingsound;
   sf:: SoundBuffer hittingbuffer;
    bool ishit;


public:
    Weapon();
    bool isActivev; 

    void setTexture(const sf::Texture& texture);

    void setSound(const std::string& soundFilePath);

    void shoot(float x, float y);

    void update();

    void draw(sf::RenderWindow& window);

    bool isActive();

    void setActive(bool active);
    void setPosition(float x, float y);
    coordinates3 getCoordinates();
    void hit();
    void reset();
    bool checkifhit();

};

#endif // WEAPON_H
