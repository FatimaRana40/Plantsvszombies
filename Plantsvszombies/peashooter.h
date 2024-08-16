#pragma once
#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include <SFML/Graphics.hpp>
#include "Weapon.h" // Include the Weapon header file
#include "Plants.h"

struct coordinates4 {
    float x;
    float y;
};

class Peashooter:public Plants
{
private:
    Weapon mypea[10]; // Array of weapons (peas)
    int lastPeaIndex; // Index of the last pea shot
    //sf::Texture plantTexture;
    //sf::Sprite plantSprite;
    int shootingInterval;
    float shootingspeed;
    sf::Clock shootTimer;
   // coordinates4 positionP; // Use coordinates struct instead of sf::Vector2f
    int price;
    Texture weapontext;
    //const int numTextures = 5;
    sf::Texture peaTextures[5];
    sf::Clock timer;
    int currentTextureIndex;
public:
    Peashooter();

  virtual  void ShootPea();
  virtual void update();
  virtual void draw(sf::RenderWindow& window);
  virtual int getCurrency();
  bool isActive();
  void collect(Event& event, int& currency);
  virtual void displayplant(sf::RenderWindow& window);
  bool detectcollision(coordinates c);
};

#endif // PEASHOOTER_H
