#pragma once
#include <vector>
#include <fstream>
#include "Organism.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Sloth.h"
#include "Dog.h"
#include "Grass.h"
#include "Coca.h"
#include "Guarana.h"

using namespace std;

class World
{
private:
	Organism* mapArray[20][20];
	vector<Organism*> organismVector;
	vector<string> turnLog;

public:
	World();
	void takeTurn();
	void makeArrayFromFile(World& worldReference, string fileName);
	void saveGame(const string fileName);
	void makeArrayFromVector();
	void sortVector();
	vector<Organism*> getOrganismVector();
	void addToTurnLog(string actionData);
	vector<string> getTurnLog();
	void clearTurnLog();
	bool isEmptyFieldAround(PositionStruct& positionCoordinates);
	bool isFieldEmpty(const PositionStruct& positionCoordinates);
	bool isFieldEmptyAndOnTheMap(const PositionStruct& positionCoordinates);
	void clearField(const int positionX, const int positionY);
	char getSymbolFromOccupiedField(const PositionStruct& positionCoordinates);
	int getStrenghFromOccupiedField(const PositionStruct& positionCoordinates);
	string getNameFromOccupiedField(const PositionStruct& positionCoordinates);
	void moveAnimalToAnotherField(Animal* animal, const PositionStruct& positionCoordinates);
	void createNewOrganism(Organism* organism, const PositionStruct& positionCoordinates);

	~World();
};

