#include "Organism.h"

using namespace std;

Organism::Organism(World& wordReference_, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	:worldReference(wordReference_), strength(strength_), agility(agility_), age(age_), symbol(symbol_), name(name_), isAlive(isAlive_), didMove(didMove_),
	extraMove(extraMove_)
{
}

PositionStruct Organism::drawNextPosition(int positionX, int positionY) {

	random_device randomDevice;
	mt19937 rngGen(randomDevice());
	uniform_int_distribution<> distrib(-1, 1);
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

void Organism::setPositionX(int value)
{
	positionX = value;
}

void Organism::setPositionY(int value)
{
	positionY = value;
}


int Organism::getPositionX()
{
	return positionX;
}

int Organism::getPositionY()
{
	return positionY;
}

string Organism::getName()
{
	return name;
}

bool Organism::getIsAlive()
{
	return isAlive;
}

void Organism::setIsAlive(bool isAlive_)
{
	isAlive = isAlive_;
}

bool Organism::getDidMove()
{	
	return didMove;
}

void Organism::setDidMove(bool didMove_)
{
	didMove = didMove_;
}

bool Organism::getExtraMove()
{
	return extraMove;
}

void Organism::setExtraMove(bool extraMove_)
{
	extraMove = extraMove_;
}

char Organism::getSymbol()
{
	return symbol;
}

int Organism::getAgility()
{
	return agility;
}

int Organism::getAge()
{
	return age;
}

void Organism::setAge(int age_)
{
	age = age_;
}

int Organism::getStrength()
{
	return strength;
}

void Organism::setStrength(int strength_)
{
	strength = strength_;
}

Organism::~Organism()
{
}

std::ostream& operator<<(std::ostream& out, Organism& org)
{
	out << org.getSymbol();
	return out;
}
