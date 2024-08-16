#pragma once
#ifndef CHERRYBOMB_H
#define CHERRYBOMB_H

#include "Plants.h"
//struct coordinates4 {
//    float x;
//    float y;
//};

class CherryBomb : public Plants {
private:
    Sprite explosionSprite;
    sf::Texture explosionTexture;
    sf::Sound explosionSound;
    sf::SoundBuffer explosionBuffer;
    bool exploding;
    Clock explosionTimer;
    bool hasExploded;
    //coordinates4 positionC;
    bool active;
public:
    CherryBomb();
    void setactive();
    virtual void update();
    virtual void draw(sf::RenderWindow& window);
    bool isActive();
    void explode();
    virtual void ShootPea();
    virtual int getCurrency();
    void collect(Event& event, int& currency);
    virtual void displayplant(sf::RenderWindow& window);
    bool getExploding();
    bool detectcollision(coordinates c)
    {
        return false;
    }
};

#endif // CHERRYBOMB_H
