#ifndef _FLEET_
#define _FLEET_

#include "cocos2d.h"
#include "CharacterInfo.h"
#define MAX_SHIPS_PER_FLEET 6

class Fleet{
public:
	
	Fleet(int fleetNumber);
	bool addShip(CharacterInfo* newShip);
	bool switchShip(CharacterInfo* newShip, int index);
	bool removeShip(int index);
	CharacterInfo* getShip(int index);
	inline int getIndex(){ return FleetNumber; }
	inline int size(){ return ships.size(); }
private:
	std::vector<CharacterInfo*> ships;
	int FleetNumber;
};
#endif