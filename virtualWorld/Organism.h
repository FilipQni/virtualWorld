#pragma once
#include<string>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>
#include<random>

using namespace std;

class World;

struct PositionStruct {
	int positionX;
	int positionY;
};

class Organism
{
protected:
	int strength;
	int agility;
	int positionX;
	int positionY;
	int age;
	char symbol;
	string name;
	World& worldReference;
	bool isAlive;
	bool didMove;
	bool extraMove;


public:
	Organism(World& wordReference_, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_);
	int getPositionX();
	void setPositionX(int value);
	int getPositionY();
	void setPositionY(int value);
	int getAgility();
	char getSymbol();
	int getAge();
	void setAge(int age_);
	int getStrength();
	void setStrength(int strength_);
	string getName();
	bool getIsAlive();
	void setIsAlive(bool isAlive_);
	bool getDidMove();
	void setDidMove(bool didMove_);
	bool getExtraMove();
	void setExtraMove(bool extraMove_);
	virtual Organism* getClass() = 0;
	virtual void action() = 0;
	virtual PositionStruct drawNextPosition(int positionX, int positionY);
	~Organism();
};

