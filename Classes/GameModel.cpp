#include "GameModel.h"
#include "XMLParser.h"

GameModel * GameModel::instance = NULL;
class GirlFirend;
GameModel::GameModel()
{
	getDataFromSaveFile();
	nextShipId = 0;
	nextEquipmentId = 0;
	for (int i = 0; i < MAX_FLEET_NUMBER; i++)
	{
		fleets.push_back(new Fleet(i));
	}
	
	
	

}
Fleet* GameModel::getFleet(int index)
{
	if (index > fleets.size())
		return nullptr;
	return fleets[index];
}
int GameModel::getShipId()
{
	nextShipId++;
	return nextShipId;
}
int GameModel::getEquipmentId()
{
	nextEquipmentId++;
	return nextEquipmentId;
}
bool GameModel::isSaveFileExist()
{
	if (!UserDefault::sharedUserDefault()->getBoolForKey("isSaveFileExist"))
	{
		UserDefault::sharedUserDefault()->setBoolForKey("isSaveFileExist", true);
		UserDefault::sharedUserDefault()->flush();
		return false;
	}
	else
		return true;
}
void GameModel::initialSaveFile()
{
	UserDefault::sharedUserDefault()->setIntegerForKey("fuel", INIT_FUEL);
	UserDefault::sharedUserDefault()->setIntegerForKey("steel", INIT_STEEL);
	UserDefault::sharedUserDefault()->setIntegerForKey("ammo", INIT_AMMO);
	UserDefault::sharedUserDefault()->setIntegerForKey("aluminum", INIT_ALUMINUM);
	UserDefault::sharedUserDefault()->setIntegerForKey("quickRepair", INIT_REPAIR);
	UserDefault::sharedUserDefault()->setIntegerForKey("devTool", INIT_DEVTOOL);

	

}
void GameModel::getDataFromSaveFile()
{
	if (!isSaveFileExist())
	{
		initialSaveFile();
	}
	this->fuel = UserDefault::sharedUserDefault()->getIntegerForKey("fuel");
	this->steel = UserDefault::sharedUserDefault()->getIntegerForKey("steel");
	this->ammo = UserDefault::sharedUserDefault()->getIntegerForKey("ammo");
	this->aluminium = UserDefault::sharedUserDefault()->getIntegerForKey("aluminum");
	this->quickRepair = UserDefault::sharedUserDefault()->getIntegerForKey("quickRepair");
	this->devTool = UserDefault::sharedUserDefault()->getIntegerForKey("devTool");
}

void GameModel::updateFuel(int fuel)
{
	this->fuel = fuel;
	UserDefault::sharedUserDefault()->setIntegerForKey("fuel", fuel);
}
void GameModel::updateSteel(int steel)
{
	this->steel = steel;
	UserDefault::sharedUserDefault()->setIntegerForKey("steel", steel);
}
void GameModel::updateAmmo(int ammo)
{
	this->ammo = ammo;
	UserDefault::sharedUserDefault()->setIntegerForKey("ammo", ammo);
}
void GameModel::updateAluminium(int aluminium)
{
	this->aluminium = aluminium;
	UserDefault::sharedUserDefault()->setIntegerForKey("aluminium", aluminium);
}
void GameModel::updateDevTool(int devTool)
{
	this->devTool = devTool;
	UserDefault::sharedUserDefault()->setIntegerForKey("devTool", devTool);
}
void GameModel::updateQuickRepair(int quickRepair)
{
	this->quickRepair = quickRepair;
	UserDefault::sharedUserDefault()->setIntegerForKey("quickRepair", quickRepair);
}
void GameModel::setupInitData()
{
	CharacterInfo *info = XMLParser::getInstance()->loadCharacterInfo("JiaHeGai");
	CharacterInfo *info2 = XMLParser::getInstance()->loadCharacterInfo("NaKe");
	CharacterInfo *info3 = XMLParser::getInstance()->loadCharacterInfo("Yi19");
	CharacterInfo *info4 = XMLParser::getInstance()->loadCharacterInfo("XiLiGai2");
	CharacterInfo *info5 = XMLParser::getInstance()->loadCharacterInfo("AiDang");
	CharacterInfo *info6 = XMLParser::getInstance()->loadCharacterInfo("ChuiXue");

	allShips.push_back(info);
	allShips.push_back(info2);
	allShips.push_back(info3);
	allShips.push_back(info4);
	allShips.push_back(info5);
	allShips.push_back(info6);
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("ChiChengGai"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("DaFeng"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("WuZangGai"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("DaHe"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("Bismarck"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("ShiJinFengGai"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("JinGangGai2"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("BiRuiGai2"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("ZhenMingGai2"));
	allShips.push_back(XMLParser::getInstance()->loadCharacterInfo("WuDaoGai2"));


	fleets[0]->addShip(info);
	fleets[0]->addShip(info2);
	fleets[0]->addShip(info3);
	fleets[0]->addShip(info4);
	fleets[0]->addShip(info5);
	fleets[0]->addShip(info6);


}