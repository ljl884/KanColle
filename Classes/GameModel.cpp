#include "GameModel.h"
#include "XMLParser.h"

GameModel * GameModel::instance = NULL;

GameModel::GameModel()
{
	for (int i = 0; i < MAX_FLEET_NUMBER; i++)
	{
		fleets.push_back(new Fleet());
	}

	CharacterInfo *info = XMLParser::getInstance()->loadCharacterInfo("JiaHeGai");	
	CharacterInfo *info2 = XMLParser::getInstance()->loadCharacterInfo("NaKe");
	CharacterInfo *info3 = XMLParser::getInstance()->loadCharacterInfo("Yi19");
	CharacterInfo *info4 = XMLParser::getInstance()->loadCharacterInfo("XiLiGai2");
	CharacterInfo *info5 = XMLParser::getInstance()->loadCharacterInfo("AiDang");
	CharacterInfo *info6 = XMLParser::getInstance()->loadCharacterInfo("ChuiXue");

	fleets[0]->addShip(info);
	fleets[0]->addShip(info2);
	fleets[0]->addShip(info3);
	fleets[0]->addShip(info4);
	fleets[0]->addShip(info5);
	fleets[0]->addShip(info6);

}
Fleet* GameModel::getFleet(int index)
{
	if (index > fleets.size())
		return nullptr;
	return fleets[index];
}