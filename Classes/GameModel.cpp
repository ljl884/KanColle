#include "GameModel.h"
#include "XMLParser.h"

GameModel * GameModel::instance = NULL;
class GirlFirend;
GameModel::GameModel()
{

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