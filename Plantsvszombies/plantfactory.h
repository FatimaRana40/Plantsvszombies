#pragma once
// PlantFactory.h
#ifndef PLANTFACTORY_H
#define PLANTFACTORY_H

#include "Plants.h" // Include the base class header
#include "Sunflower.h" // Include headers for specific plant types
#include "CherryBomb.h"
#include "Peashooter.h"
#include "gamefeild.h"
#include "wallnut.h"
#include "snowpeas.h"
#include"repeater.h"
#include "Fumeshroom.h"
// Include headers for other plant types if necessary


class PlantFactory {
protected:
    Plants* plantptr;
    bool isDragging;
    //Plants** plantdoubleptr;
    int index;
    int size;

public:
    Plants** plantdoubleptr;
    bool shouldDrawPlant;
    int recentPlantIndex;
    PlantFactory();
    // Method to create instances of different plant types
    void createPlant( const std::string& type);
    void run();
    void display(sf::RenderWindow& window);
    bool handleMouseClick(Event event, Vector2i &mousePosition,int& curr, gamefeild arr[][9],int num);
    bool isDraggingPlant() const;
    void movePlant();
    bool dragPlant(sf::Vector2i& mousePosition);
    void reset();
    int getindex()
    {
        return index;
    }
    void managePlants();
    virtual ~PlantFactory();
    // Additional methods if needed...
};

#endif // PLANTFACTORY_H
