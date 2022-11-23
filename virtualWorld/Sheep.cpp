#include "Sheep.h"

Sheep::Sheep(World& ref)
	:Animal(ref, 4, 4, 0, 'S', "Sheep", true, true, false)
{
}

Sheep::Sheep(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	: Animal(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

Organism* Sheep::getClass()
{
	Organism* org = new Sheep(worldReference);
	return org;
}

Sheep::~Sheep()
{
}
