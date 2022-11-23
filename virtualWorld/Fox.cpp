#include "Fox.h"
#include "World.h"

Fox::Fox(World& ref)
	:Animal(ref, 3, 7, 0, 'F', "Fox",true, true, false)
{
}

Fox::Fox(World& ref, int strength_, int agility_, int age_, char symbol_, string name_, bool isAlive_, bool didMove_, bool extraMove_)
	: Animal(ref, strength_, agility_, age_, symbol_, name_, isAlive_, didMove_, extraMove_)
{
}

void Fox::action()
{
	PositionStruct nextPosition = drawNextPosition(positionX, positionY);
	
	//empty field
	if (worldReference.isFieldEmpty(nextPosition)) {
		worldReference.clearField(positionX, positionY);
		worldReference.moveAnimalToAnotherField(this, nextPosition);
		setPositionX(nextPosition.positionX);
		setPositionY(nextPosition.positionY);
	}
	else {

		//if there is the same type of the unit
		if (symbol == worldReference.getSymbolFromOccupiedField(nextPosition)) {
			if (worldReference.isFieldEmptyAndOnTheMap(nextPosition)) {
				collision(nextPosition);
			}
		}
		else {
			string actionLog;

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
			//there is a stronger unit fox does not move
			if (strength < worldReference.getStrenghFromOccupiedField(nextPosition)) {
				actionLog =
					+"A "
					+ getName()
					+ " avoided death from the "
					+ worldReference.getNameFromOccupiedField(nextPosition)
					+ " at ("
					+ std::to_string(nextPosition.positionX + 1)
					+ ","
					+ std::to_string(nextPosition.positionY + 1)
					+ ")";
				worldReference.addToTurnLog(actionLog);
			}
		}
	}
	setDidMove(true);
}

Organism* Fox::getClass()
{
	Organism* org = new Fox(worldReference);
	return org;
}

Fox::~Fox()
{
}
