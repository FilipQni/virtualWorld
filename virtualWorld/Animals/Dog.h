#pragma once
#include "Animal.h"

class Dog : public Animal
{
public:
	Dog(World& ref);
	Dog(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	Organism* getClass();
	void collision(PositionStruct& nextPosition);
	PositionStruct drawNextPosition(int positionX, int positionY) override;
	~Dog();
};

