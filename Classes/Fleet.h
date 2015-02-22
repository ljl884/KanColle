#ifndef _FLEET_
#define _FLEET_

#include "cocos2d.h"
#include "CharacterInfo.h"

class Fleet{
public:
	
	bool addShip(CharacterInfo* newShip);
	bool switchShip(CharacterInfo* newShip, int index);
	bool removeShip(int index);
	CharacterInfo* getShip(int index);
private:
	std::vector<CharacterInfo*> ships;
};
#endif