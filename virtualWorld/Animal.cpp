#include "Animal.h"
#include "World.h"


Animal::Animal(World& wordReference_, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraTurn_)
	:Organism(wordReference_, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraTurn_)
{

}

void Animal::action()
{
	PositionStruct nextPosition = drawNextPosition(positionX, positionY);

	//empty field
	if (worldReference.isFieldEmpty(nextPosition)){
		worldReference.clearField(positionX, positionY);
		worldReference.moveAnimalToAnotherField(this, nextPosition);
		setPositionX(nextPosition.positionX);
		setPositionY(nextPosition.positionY);
		setDidMove(true);
	}
	else {
		string actionLog;

		//if there is the same type of the unit
		if (symbol == worldReference.getSymbolFromOccupiedField(nextPosition)){
			if (worldReference.isFieldEmptyAndOnTheMap(nextPosition)) {
				collision(nextPosition);
			}
		}
		else {
			//if there is a weaker unit
			if (strength >= worldReference.getStrenghFromOccupiedField(nextPosition)) {
				if (worldReference.getSymbolFromOccupiedField(nextPosition) == 'C') setExtraMove(true);
				if (worldReference.getSymbolFromOccupiedField(nextPosition) == 'G') setStrength(getStrength() + 1);
				setPositionX(nextPosition.positionX);
				setPositionY(nextPosition.positionY);
				actionLog =
					+"A "
					+ getName()
					+ " ate the "
					+ worldReference.getNameFromOccupiedField(nextPosition)
					+ " at ("
					+ std::to_string(nextPosition.positionX + 1)
					+ ","
					+ std::to_string(nextPosition.positionY + 1)
					+ ")";
				worldReference.addToTurnLog(actionLog);
				worldReference.moveAnimalToAnotherField(this, nextPosition);
			}
			//there is a stronger unit
			if (strength < worldReference.getStrenghFromOccupiedField(nextPosition)) {
				setIsAlive(false);
				actionLog =
					+ "A "
					+ getName()
					+ " died from the "
					+ worldReference.getNameFromOccupiedField(nextPosition)
					+ " at ("
					+ std::to_string(nextPosition.positionX + 1)
					+ ","
					+ std::to_string(nextPosition.positionY + 1)
					+ ")";
				worldReference.clearField(nextPosition.positionX, nextPosition.positionY);
				worldReference.addToTurnLog(actionLog);
			}
		}
	}
	setDidMove(true);
	setAge(age + 1);
}

void Animal::collision(PositionStruct& nextPosition)
{
	string actionLog;
	worldReference.createNewOrganism(this, nextPosition);
	actionLog =
		+"A "
		+ getName()
		+ " was born at "
		+ std::to_string(nextPosition.positionX + 1)
		+ ","
		+ std::to_string(nextPosition.positionY + 1)
		+ ")";
	worldReference.addToTurnLog(actionLog);
}

Animal::~Animal()
{
}
