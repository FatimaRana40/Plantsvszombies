#include "plantfactory.h"
#include<string>
#include <iostream>
using namespace std;
PlantFactory::PlantFactory() : plantptr(nullptr), isDragging(false), shouldDrawPlant(false)
{
	size = 45;
	index = 0;
	plantdoubleptr = new Plants *[size];
	for (int i = 0; i < size; i++)
	{
	
		plantdoubleptr[i] =NULL;
	}
    recentPlantIndex = -1;
	
}

void PlantFactory::createPlant(const std::string& type) {
	if (type == "peashooter")
	{
		/*plantptr= new Peashooter();*/
		plantdoubleptr[index++] = new Peashooter();
	}
	//plantptr->setPositionplant(70, 50);
}
void PlantFactory::run() {
	/*plantptr->update();
	plantptr->ShootPea();*/
	for (int i = 0; i < index; i++) {
		if(plantdoubleptr[i]!=NULL)
		plantdoubleptr[i]->update();
		//plantdoubleptr[i]->ShootPea();
	}
	//managePlants();
}
void PlantFactory::display(RenderWindow& window) {
	/*plantptr->displayplant(window);
	plantptr->draw(window);*/
	for (int i = 0; i < index; i++) {
		if (plantdoubleptr[i] != NULL) {
			if (!plantdoubleptr[i]->plantdead)
			{
				plantdoubleptr[i]->displayplant(window);
				plantdoubleptr[i]->draw(window);
			}
		}
	}
}
//new code 



bool PlantFactory::handleMouseClick(sf::Event event, sf::Vector2i& mousePosition,int& curr, gamefeild arr[][9],int num) {
	if (event.type == sf::Event::MouseButtonPressed) {
		if (event.mouseButton.button == sf::Mouse::Left) {
			int mouseX = mousePosition.x;
			int mouseY = mousePosition.y;
			int regionLeft = 70;
			int regionTop = 0;
			int regionWidth = 65;
			int regionHeight = 90;
			for (int j = 0; j < num; j++) {
				if (mouseX >= regionLeft && mouseX <= regionLeft + regionWidth &&
					mouseY >= regionTop && mouseY <= regionTop + regionHeight && !isDragging) {
					for (int i = 0; i < size; ++i) {
						if (plantdoubleptr[i] == nullptr) {
							if (j == 0 && curr >= 100)
								plantdoubleptr[i] = new Peashooter();
							else if (j == 1 && curr >= 50)
								plantdoubleptr[i] = new sunflower();
							else if (j == 2 && curr >= 50)
								plantdoubleptr[i] = new Wallnut();
							else if (j == 3 && curr >= 150)
								plantdoubleptr[i] = new CherryBomb();
							else if (j == 4 && curr >= 175)
								plantdoubleptr[i] = new SnowPea();
							else if (j == 5 && curr >= 200)
								plantdoubleptr[i] = new Repeater();
							else if (j == 6 && curr >= 75)
								plantdoubleptr[i] = new FumeShroom();
							if( plantdoubleptr[i] != nullptr && curr >= plantdoubleptr[i]->getCurrency())
								curr -= plantdoubleptr[i]->getCurrency();

							if (plantdoubleptr[i] != nullptr) {
								plantdoubleptr[i]->setPositionplant(regionLeft, regionTop);
								isDragging = true;
								recentPlantIndex = i;
								index++;// Update recentPlantIndex when a new plant is created
							}
							break;
						}
					}
				}
				regionLeft = regionLeft + (regionWidth);
			}
			if (recentPlantIndex != -1 && isDragging) {
				if (plantdoubleptr[recentPlantIndex] != nullptr) {
					for (int i = 0; i < 5; i++) {
						for (int k = 0; k < 9; k++) {
							if (mousePosition.x + 20 >= arr[i][k].patchCoordinates.x && mousePosition.x + 20 <= arr[i][k].patchCoordinates.x + 95 &&
								mousePosition.y + 20 >= arr[i][k].patchCoordinates.y && mousePosition.y + 20 <= arr[i][k].patchCoordinates.y + 115 && recentPlantIndex!=-1) {
								if (arr[i][k].check) {
									if (plantdoubleptr[recentPlantIndex]->n != 2 && plantdoubleptr[recentPlantIndex]->n != 3)
									{
										arr[i][k].check = false;
									}
									if (plantdoubleptr[recentPlantIndex]->n == 3) {
										CherryBomb* temp = (CherryBomb*)plantdoubleptr[recentPlantIndex];
										temp->setactive();
									}
									plantdoubleptr[recentPlantIndex]->setPositionplant(arr[i][k].patchCoordinates.x, arr[i][k].patchCoordinates.y);
									plantdoubleptr[recentPlantIndex]->isplacedongrid = true;
									reset();
								}
							}
						}
					}
				}
			}
				
		}
			
	}
	return false;
}

bool PlantFactory::dragPlant(sf::Vector2i& mousePosition) {
	if (isDragging && recentPlantIndex!=-1) {
	
		plantdoubleptr[recentPlantIndex]->setPositionplant(mousePosition.x, mousePosition.y);
		return true;
	}
	return false;
}


bool PlantFactory::isDraggingPlant() const {
    return isDragging;
}

void PlantFactory::movePlant() {
   
}
void PlantFactory:: reset() {
	isDragging = false;
	recentPlantIndex = -1;
}
void PlantFactory::managePlants() {
	for (int i = 0; i < index; i++) {
		if ( plantdoubleptr[i] != nullptr && plantdoubleptr[i]->plantdead) {
			delete plantdoubleptr[i];
			plantdoubleptr[i] = nullptr;

			// Shift plants back by one index
			for (int j = i; j < index - 1; j++) {
				plantdoubleptr[j] = plantdoubleptr[j + 1];
			}

			index--;
			i--; // Decrement i to re-check the new plant at this index
		}
	}
}
PlantFactory::~PlantFactory() {
	for (int i = 0; i < index; i++) {
		if (plantdoubleptr[i] != nullptr) {
			delete plantdoubleptr[i];
		}
	}
}
