#pragma once
#include "Animal.h"

class Wolf : public Animal
{
public:
	Wolf(World& ref);
	Wolf(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	~Wolf();
};

