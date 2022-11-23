#pragma once
#include "Organism.h"

class Plant : public Organism
{
public:
	Plant(World& wordReference_, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraTurn_);
	void action();
	~Plant();
};

