#include "Grass.h"

Grass::Grass(World& ref)
	:Plant(ref, 0, 0, 0, '#', "Grass", true, true, false)
{
}

Grass::Grass(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	: Plant(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

Organism* Grass::getClass()
{
	Organism* org = new Grass(worldReference);
	return org;
}

Grass::~Grass()
{
}
