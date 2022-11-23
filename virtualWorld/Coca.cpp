#include "Coca.h"

Coca::Coca(World& ref)
	:Plant(ref, 0, 0, 0, 'C', "Coce", true, true, false)
{
}

Coca::Coca(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	: Plant(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

Organism* Coca::getClass()
{
	Organism* org = new Coca(worldReference);
	return org;
}

Coca::~Coca()
{
}
