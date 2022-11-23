#pragma once
#include "Plant.h"

class Grass : public Plant
{
public: 
	Grass(World& ref);
	Grass(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	~Grass();
};

