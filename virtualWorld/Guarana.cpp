#include "Guarana.h"

Guarana::Guarana(World& ref)
	:Plant(ref, 0, 0, 0, 'G', "Guarana", true, true, false)
{
}

Guarana::Guarana(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	:Plant(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

Organism* Guarana::getClass()
{
	Organism* org = new Guarana(worldReference);
	return org;
}

Guarana::~Guarana()
{
}
