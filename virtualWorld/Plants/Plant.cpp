#include "Plant.h"
#include "../World.h"

Plant::Plant(World& wordReference_, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraTurn_)
	:Organism(wordReference_, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraTurn_)
{
}

void Plant::action()
{
	random_device randomDevice;
	mt19937 rngGen(randomDevice());
	uniform_int_distribution<> distrib(1, 100);
	PositionStruct nextPosition{};

	int chanceToMultiplay = distrib(rngGen);
	if (chanceToMultiplay > 92) {
		PositionStruct adjacentField = { positionX, positionY };

		if (worldReference.isEmptyFieldAround(adjacentField)) {
			string actionLog;
			worldReference.createNewOrganism(this, adjacentField);
			actionLog =
				+"A "
				+ getName()
				+ " has grown at ("
				+ std::to_string(adjacentField.positionX + 1)
				+ ","
				+ std::to_string(adjacentField.positionY + 1)
				+ ")";
			worldReference.addToTurnLog(actionLog);
		}
	}
	setDidMove(true);
	setAge(age + 1);
}

Plant::~Plant()
{
}
