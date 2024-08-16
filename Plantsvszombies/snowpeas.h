#pragma once
#ifndef SNOWPEA_H
#define SNOWPEA_H

#include "Weapon.h"
#include"Plants.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class SnowPea:public Plants
{
private:
    Weapon mysnowpea[10]; // Array of weapons (snow peas)
    int lastSnowPeaIndex; // Index of the last snow pea shot
    //sf::Texture plantTexture;
    //sf::Sprite plantSprite;
    int shootingInterval;
    float shootingSpeed;
    sf::Clock shootTimer;
    sf::Texture peaTextures[5];
    sf::Clock timer;
    int currentTextureIndex;

public:
    SnowPea();

    virtual void ShootPea();

    virtual void update();

    virtual void draw(sf::RenderWindow& window);
    virtual int getCurrency();
    bool isActive();
    void collect(Event& event, int& currency);
    virtual void displayplant(sf::RenderWindow& window);
    bool detectcollision(coordinates c);
    
};

#endif // SNOWPEA_H
