#include "Fleet.h"

Fleet::Fleet(int FleetNumber)
{
	this->FleetNumber = FleetNumber;
}

bool Fleet::addShip(CharacterInfo* newShip){
	if (ships.size() > 6)
		return false;
	ships.push_back(newShip);
	newShip->currentFleet = FleetNumber;
	return true;
	
}
bool Fleet::switchShip(CharacterInfo* newShip, int index){
	if (index > ships.size())
		return false;
	if (newShip->currentFleet == this->FleetNumber) //the newShip is from current fleet
	{
		if (ships[index]->inGameId == newShip->inGameId) //switch with itself, return false
			return false;
		int newIndex;
		for (newIndex = 0; newIndex < ships.size(); newIndex++) //get the index of newShip
		{
			if (ships[newIndex]->inGameId == newShip->inGameId)
				break;
		}

		CharacterInfo * temp = ships[index]; 
		ships[index] = newShip;
		ships[newIndex] = temp;

		return true;
	}
	else
	{
		ships[index]->currentFleet = -1;
		ships[index] = newShip;
		ships[index]->currentFleet = FleetNumber;
		return true;
	}
	
}
bool Fleet::removeShip(int index){
	if (index > ships.size())
		return false;
	ships[index]->currentFleet = -1;
	ships.erase(ships.begin() + index);
	return true;
}
CharacterInfo* Fleet::getShip(int index){
	if (index > ships.size())
		return nullptr;
	return ships[index];
}