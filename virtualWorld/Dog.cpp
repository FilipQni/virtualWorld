#include "Dog.h"

Dog::Dog(World& ref)
	:Animal(ref, 6, 6, 0, 'D', "Dog", true, true, false)
{
}

Dog::Dog(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	:Animal(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

PositionStruct Dog::drawNextPosition(int positionX, int positionY) 
{
	random_device randomDevice;
	mt19937 rngGen(randomDevice());
	uniform_int_distribution<> distrib(-2, 2);
	PositionStruct nextPosition{};

	int shiftAxisX, shiftAxisY;
	do {
		shiftAxisX = distrib(rngGen);
		shiftAxisY = distrib(rngGen);
	} while (
		(shiftAxisX == 0 && shiftAxisY == 0) ||
		positionX + shiftAxisX < 0 ||
		positionX + shiftAxisX > 19 ||
		positionY + shiftAxisY < 0 ||
		positionY + shiftAxisY > 19);

	nextPosition.positionX = positionX + shiftAxisX;
	nextPosition.positionY = positionY + shiftAxisY;

	return nextPosition;
}

void Dog::collision(PositionStruct& nextPosition)
{
	Animal::collision(nextPosition);
	strength++;
}

Organism* Dog::getClass()
{
	Organism* org = new Dog(worldReference);
	return org;
}

Dog::~Dog()
{
}
