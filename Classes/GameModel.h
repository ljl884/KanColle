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
	inline std::vector<CharacterInfo*> getAllShips(){ return allShips; }
	int getShipId();
	int getEquipmentId();
	void setupInitData();
	

	inline int getFuel(){ return fuel; }
	inline int getSteel(){ return steel; }
	inline int getAmmo(){ return ammo; }
	inline int getAluminium(){ return aluminium; }
	inline int getDevTool(){ return devTool; }
	inline int getQuickRepair(){ return quickRepair; }

private:
	GameModel();
	bool isSaveFileExist();
	static GameModel* instance;
	std::vector<Fleet*> fleets;
	std::vector<CharacterInfo*> allShips;
	int nextShipId;
	int nextEquipmentId;

	//resource
	int fuel;
	int steel;
	int ammo;
	int aluminium;

	int quickRepair;
	int devTool;

};

#endif