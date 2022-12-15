#pragma once
#include "Animal.h"
#include "../World.h"

class Fox : public Animal
{
public:
	Fox(World& ref);
	Fox(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	void action();
	Organism* getClass();
	~Fox();
};

