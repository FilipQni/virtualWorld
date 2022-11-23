#pragma once
#include "Plant.h"

class Guarana : public Plant
{
public:
	Guarana(World& ref);
	Guarana(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	~Guarana();
};

