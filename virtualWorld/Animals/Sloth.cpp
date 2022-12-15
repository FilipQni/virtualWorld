#include "Sloth.h"

Sloth::Sloth(World& ref)
	:Animal(ref, 2, 1, 0, '$', "Sloth", true, true, false)
{
	this->movedPreviousRound = false;
}

Sloth::Sloth(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	:Animal(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

Organism* Sloth::getClass()
{
	Organism* org = new Sloth(worldReference);
	return org;
}

void Sloth::action(vector<Organism*>& organismVector)
{
	if (!movedPreviousRound) {
		movedPreviousRound = true;
		Animal::action();
	}
	else {
		movedPreviousRound = false;
		didMove = true;
	}
}

Sloth::~Sloth()
{
}
