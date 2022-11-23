#pragma once
#include "Plant.h"

class Coca :
	public Plant
{
public:
	Coca(World& ref);
	Coca(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	~Coca();
};

