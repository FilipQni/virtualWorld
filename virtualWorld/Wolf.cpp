#include "Wolf.h"

Wolf::Wolf(World& ref)
	:Animal(ref, 9, 5, 0, 'W',"Wolf", true, true, false)
{
}

Wolf::Wolf(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	:Animal(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

Organism* Wolf::getClass()
{
	Organism* org = new Wolf(worldReference);
	return org;
}

Wolf::~Wolf()
{
}
