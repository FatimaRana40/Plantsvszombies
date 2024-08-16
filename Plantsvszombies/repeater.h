#pragma once
#ifndef REPEATER_H
#define REPEATER_H

#include "Weapon.h"
#include "Plants.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Repeater:public Plants
{
private:
    Weapon myrepeater[10]; // Array of weapons (pears)
    int lastRepeaterIndex; // Index of the last pear shot
    //sf::Texture plantTexture;
    //sf::Sprite plantSprite;
    int shootingInterval;
    float shootingSpeed;
    sf::Clock shootTimer;
    sf::Texture peaTextures[5];
    sf::Clock timer;
    int currentTextureIndex;
public:
    Repeater();

   virtual void ShootPea();

   virtual  void update();

   virtual void draw(sf::RenderWindow& window);
   virtual int getCurrency();
   bool isActive();
   void collect(Event& event, int& currency);
   virtual void displayplant(sf::RenderWindow& window);
   bool detectcollision(coordinates c);
  
};

#endif // REPEATER_H
