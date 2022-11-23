#include "World.h"

World::World()
{
}

void World::takeTurn()
{
	clearTurnLog();
	sortVector();
	makeArrayFromVector();
	for (unsigned int i = 0; i < organismVector.size(); i++) {
		organismVector[i]->setDidMove(false);
	}

	for (unsigned int i = 0; i < organismVector.size(); i++) {
		if (organismVector[i]->getIsAlive() && !organismVector[i]->getDidMove()) {
			if (organismVector[i]->getExtraMove()) {
				organismVector[i]->action();
				organismVector[i]->setExtraMove(false);
			}
			organismVector[i]->action();
			makeArrayFromVector();
		}
	}
}

void World::makeArrayFromFile(World& worldReference, string fileName)
{
	ifstream file(fileName.c_str());
	if (!file.good()) {
		cout << "LOADING FILE - FAIL\n";
	}

	char orgChar;
	int orgPositionX;
	int orgPositionY;
	int boxInt;
	bool boxBool = false;

	Organism* organismBox = nullptr;

	if (!organismVector.empty()) {
		for (unsigned int i = 0; i < organismVector.size(); i++) {
			delete organismVector[i];
		}
	}

	organismVector.clear();


	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mapArray[i][j] = nullptr;
		}
	}

	while (!file.eof()) {
		file >> orgChar;
		switch (orgChar)
		{
		case 'W':
			organismBox = new Wolf(worldReference);
			break;
		case 'S':
			organismBox = new Sheep(worldReference);
			break;
		case 'F':
			organismBox = new Fox(worldReference);
			break;
		case '$':
			organismBox = new Sloth(worldReference);
			break;
		case 'D':
			organismBox = new Dog(worldReference);
			break;
		case '#':
			organismBox = new Grass(worldReference);
			break;
		case 'C':
			organismBox = new Coca(worldReference);
			break;
		case 'G':
			organismBox = new Guarana(worldReference);
			break;
		default:
			break;
		}
		file >> orgPositionX;
		organismBox->setPositionX(orgPositionX);

		file >> orgPositionY;
		organismBox->setPositionY(orgPositionY);

		file >> boxInt;
		organismBox->setAge(boxInt);

		file >> boxInt;
		organismBox->setStrength(boxInt);

		file >> boxBool;
		organismBox->setExtraMove(boxBool);

		organismVector.push_back(organismBox);
		mapArray[orgPositionX][orgPositionY] = organismVector.back();

		/* loading from file in order:
		1 positionX
		2 positionY
		3 age
		4 strength
		5 extraMove
		*/
	}
	file.close();
}

void World::saveGame(const string fileName)
{
	ofstream file;
	file.open(fileName, ios::trunc | ios::out);

	for (unsigned int i = 0; i < organismVector.size(); i++)
	{
		file << organismVector[i]->getSymbol() << ' ' << organismVector[i]->getPositionX() << ' ' << organismVector[i]->getPositionY() << ' '
			<< organismVector[i]->getAge() << ' ' << organismVector[i]->getStrength() << ' ' << organismVector[i]->getExtraMove() << '\n';
	}
	file.close();
}

void World::makeArrayFromVector()
{
	int x;
	int y;
	for (unsigned int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			mapArray[i][j] = nullptr;
		}
	}

	for (unsigned int i = 0; i < organismVector.size(); i++) {
		if (organismVector[i]->getIsAlive()) {
			x = organismVector[i]->getPositionX();
			y = organismVector[i]->getPositionY();
			mapArray[x][y] = organismVector[i];
		}
	}
}

void World::sortVector()
{
	for (unsigned int i = 0; i < organismVector.size(); i++) {
		if (!organismVector[i]->getIsAlive()) {
			delete organismVector[i];
			organismVector.erase(organismVector.begin() + i);
		}
	}
	unsigned int vectorSize = organismVector.size();
	for (unsigned int i = 0; i < vectorSize - 1; i++) {
		for (unsigned int j = 0; j < vectorSize - 1 - i; j++) {
			if (organismVector[j]->getAgility() < organismVector[j + 1]->getAgility()) swap(organismVector[j], organismVector[j + 1]);
			if (organismVector[j]->getAgility() == organismVector[j + 1]->getAgility()) {
				if (organismVector[j]->getAge() < organismVector[j + 1]->getAge()) swap(organismVector[j], organismVector[j + 1]);
			}
		}
	}
}

bool World::isEmptyFieldAround(PositionStruct& positionCoordinates) {
	/*
			|7|8|1|
			|6|X|2|   <- it checks fields on the map around the object in this order
			|5|4|3|
	*/

	positionCoordinates.positionX += 1;
	positionCoordinates.positionY -= 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionY += 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionY += 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionX -= 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionX -= 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionY -= 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionY -= 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	positionCoordinates.positionX += 1;
	if (isFieldEmptyAndOnTheMap(positionCoordinates)) return true;

	return false;
}

bool World::isFieldEmptyAndOnTheMap(const PositionStruct& positionCoordinates) {

	if (positionCoordinates.positionX >= 0 &&
		positionCoordinates.positionX <= 19 &&
		positionCoordinates.positionY >= 0 &&
		positionCoordinates.positionY <= 19 &&
		mapArray[positionCoordinates.positionX][positionCoordinates.positionY] == nullptr
		) return true;

	return false;
}

bool World::isFieldEmpty(const PositionStruct& positionCoordinates) {
	if (mapArray[positionCoordinates.positionX][positionCoordinates.positionY] == nullptr) return true;
	return false;
}

void World::clearField(const int positionX, const int positionY) {
	mapArray[positionX][positionY] = nullptr;
}

char World::getSymbolFromOccupiedField(const PositionStruct& positionCoordinates) {
	return mapArray[positionCoordinates.positionX][positionCoordinates.positionY]
		->getSymbol();
}

int World::getStrenghFromOccupiedField(const PositionStruct& positionCoordinates) {
	return mapArray[positionCoordinates.positionX][positionCoordinates.positionY]
		->getStrength();
}

string World::getNameFromOccupiedField(const PositionStruct& positionCoordinates) {
	return mapArray[positionCoordinates.positionX][positionCoordinates.positionY]
		->getName();
}

void World::moveAnimalToAnotherField(Animal* animal, const PositionStruct& positionCoordinates) {
	if (!isFieldEmpty(positionCoordinates)) {
		mapArray[positionCoordinates.positionX][positionCoordinates.positionY]->setIsAlive(false);
	}
	mapArray[positionCoordinates.positionX][positionCoordinates.positionY] = animal;
}

void World::createNewOrganism(Organism* organism, const PositionStruct& positionCoordinates) {
	organismVector.push_back(organism->getClass());
	organismVector.back()->setPositionX(positionCoordinates.positionX);
	organismVector.back()->setPositionY(positionCoordinates.positionY);
	organismVector.back()->setIsAlive(true);
	organismVector.back()->setDidMove(true);

}


vector<Organism*> World::getOrganismVector()
{
	return organismVector;
}

void World::addToTurnLog(string actionData)
{
	turnLog.push_back(actionData);
}

vector<string> World::getTurnLog()
{
	return turnLog;
}

void World::clearTurnLog()
{
	turnLog.clear();
}

World::~World()
{
	for (unsigned int i = 0; i < organismVector.size(); i++) {
		delete organismVector[i];
	}
}
