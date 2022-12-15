#pragma once
#include "Animal.h"

class Sheep : public Animal
{
public:
	Sheep(World& ref);
	Sheep(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	~Sheep();
};

