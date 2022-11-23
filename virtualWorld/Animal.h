#pragma once
#include "Organism.h"

class Animal : public Organism
{
public:
	Animal (World& wordReference_, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	void action();
	void collision(PositionStruct& positionCoordinates);
	~Animal();
};


