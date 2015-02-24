#include "GameModel.h"
#include "XMLParser.h"

GameModel * GameModel::instance = NULL;

GameModel::GameModel()
{

	nextShipId = 0;
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
void GameModel::setupInitData()
{
	CharacterInfo *info = XMLParser::getInstance()->loadCharacterInfo("JiaHeGai");
	CharacterInfo *info2 = XMLParser::getInstance()->loadCharacterInfo("NaKe");
	CharacterInfo *info3 = XMLParser::getInstance()->loadCharacterInfo("Yi19");
	CharacterInfo *info4 = XMLParser::getInstance()->loadCharacterInfo("XiLiGai2");
	CharacterInfo *info5 = XMLParser::getInstance()->loadCharacterInfo("AiDang");
	CharacterInfo *info6 = XMLParser::getInstance()->loadCharacterInfo("ChuiXue");
	CharacterInfo *info7 = XMLParser::getInstance()->loadCharacterInfo("ChiChengGai");
	CharacterInfo *info8 = XMLParser::getInstance()->loadCharacterInfo("DaFeng");
	CharacterInfo *info9 = XMLParser::getInstance()->loadCharacterInfo("WuZangGai");
	CharacterInfo *info10 = XMLParser::getInstance()->loadCharacterInfo("DaHe");
	CharacterInfo *info11 = XMLParser::getInstance()->loadCharacterInfo("Bismarck");
	CharacterInfo *info12 = XMLParser::getInstance()->loadCharacterInfo("ShiJinFengGai");

	allShips.push_back(info);
	allShips.push_back(info2);
	allShips.push_back(info3);
	allShips.push_back(info4);
	allShips.push_back(info5);
	allShips.push_back(info6);
	allShips.push_back(info7);
	allShips.push_back(info8);
	allShips.push_back(info9);
	allShips.push_back(info10);
	allShips.push_back(info11);
	allShips.push_back(info12);


	fleets[0]->addShip(info);
	fleets[0]->addShip(info2);
	fleets[0]->addShip(info3);
	fleets[0]->addShip(info4);
	fleets[0]->addShip(info5);
	fleets[0]->addShip(info6);

	fleets[0]->switchShip(info10, 2);
}