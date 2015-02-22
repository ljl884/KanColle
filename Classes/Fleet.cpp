#include "Fleet.h"

bool Fleet::addShip(CharacterInfo* newShip){
	if (ships.size() > 6)
		return false;
	ships.push_back(newShip);
	return true;
	
}
bool Fleet::switchShip(CharacterInfo* newShip, int index){
	if (index > ships.size())
		return false;
	ships[index] = newShip;
}
bool Fleet::removeShip(int index){
	if (index > ships.size())
		return false;
	ships.erase(ships.begin() + index);
	return true;
}
CharacterInfo* Fleet::getShip(int index){
	if (index > ships.size())
		return nullptr;
	return ships[index];
}