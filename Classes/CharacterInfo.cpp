#include "CharacterInfo.h"
#include "GameModel.h"
CharacterInfo::CharacterInfo()
{
	this->inGameId = GameModel::getInstance()->getShipId();
}
CharacterInfo* CharacterInfo::makeDefaultInfo()
{
	return makeDefaultInfo("009CHUIXUE");
}
CharacterInfo* CharacterInfo::makeDefaultInfo(std::string resource)
{
	CharacterInfo *info = new CharacterInfo();
	info->level = 1;
	info->agility = 40;
	info->antiaircraft = 10;
	info->antisubmarine = 20;
	info->capacity = 0;
	info->firePower = 10;
	info->currentHP = 15;
	info->maxHP = 15;
	info->armour = 23;
	info->star = 1;
	info->nameCH = "Fubuki";
	info->id = "011";
	info->type = DD;
	info->level = 1;
	info->nextId = "011b";
	info->luck = 17;
	info->name = "fubuki";
	info->resourceFolder = resource;
	info->brokenType = BrokenType::normal;
	info->range = range_short;
	info->scout = 5;
	info->torpedo = 27;
	info->speed = high;

	info->currentFleet = 0;
	return info;
}

CharacterInfo* CharacterInfo::makeDefaultEnemyInfo()
{
	CharacterInfo *info = new CharacterInfo();
	info->level = 1;
	info->armour = 135;
	info->agility = 10;
	info->antiaircraft = 130;
	info->antisubmarine = 0;
	info->capacity = 130;
	info->firePower = 90;
	info->currentHP = 50;
	info->maxHP = 50;
	info->star = 1;
	info->id = "bfqj";
	info->type = BB;
	info->level = 1;
	info->nextId = "bfqj";
	info->luck = 40;
	info->name = "BeiFangQiJi";
	info->nameCH = "±±·½ÆÜ¼§";
	info->resourceFolder = "BEIFANGQIJI1";
	info->brokenType = BrokenType::normal;
	info->range = range_short;
	info->scout = 5;
	info->torpedo = 27;
	info->speed = high;

	return info;
}