#pragma once
#include"Animal.h"

class Sloth : public Animal
{
private:
	bool movedPreviousRound;
public:
	Sloth(World& ref);
	Sloth(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	void action(vector<Organism*>& organismVector);
	~Sloth();
};

