#pragma once
#ifndef FUMESHROOM_H
#define FUMESHROOM_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Plants.h"
#include "Weapon.h" // Assuming Weapon class is defined in Weapon.h
#include "coordinates.h"
#include "Plants.h"
class FumeShroom:public Plants {
private:
    sf::Clock timer;
    sf::Clock shootTimer;
    int shootingInterval;
    int shootingspeed;
    int lastFumeIndex;
   // sf::Vector2f positionF;

    int price;
    int health;
    bool plantdead;
    int n;
    int currentTextureIndex;
    sf::Texture plantTexture;
    sf::Sprite plantSprite;
    sf::Texture weapontext;
    Weapon fume[10]; // Assuming Weapon class similar to the one used for peas
    sf::Texture fumeTextures[16]; // Updated to hold 16 textures for fume animation

public:
    FumeShroom();
    void ShootPea();
    void update();
    void draw(sf::RenderWindow& window);
    int getCurrency();
    bool isActive();
    void collect(Event& event, int& currency);
    void displayplant(sf::RenderWindow& window);
    bool detectcollision(coordinates c);
};

#endif // FUMESHROOM_H
