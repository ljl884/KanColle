#ifndef _GAME_MODEL_
#define _GAME_MODEL_

#include "Fleet.h"
#define MAX_FLEET_NUMBER 4



class GameModel{
public:
	static GameModel* getInstance(){
		if (instance == NULL)
			instance = new GameModel();
		return instance;
	}
	Fleet* getFleet(int index);

private:
	GameModel();
	static GameModel* instance;
	std::vector<Fleet*> fleets;
	std::vector<CharacterInfo*> allShips;

};

#endif