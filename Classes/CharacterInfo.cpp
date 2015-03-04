#include "CharacterInfo.h"
#include "GameModel.h"
CharacterInfo::CharacterInfo()
{
	this->inGameId = GameModel::getInstance()->getShipId();
	for (int i = 0; i < MAX_EQUIPMENT_NUMBER;i++)
		equipments.push_back(nullptr);
	 type = DD;	 brokenType = normal;
	 level = 1;	 maxHP=0;	currentHP=0;
	 star=1;	 firePower=0;	 armour=0;
	 torpedo=0;	 agility=0;	 antiaircraft=0;
	 capacity=0;	 antisubmarine=0;	 speed = low;
	 scout=0;	range=range_short;	 luck=0;
	 bomb=0;	 hitRate=0;

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
	info->nameCH = "北方栖姬";
	info->resourceFolder = "BEIFANGQIJI1";
	info->brokenType = BrokenType::normal;
	info->range = range_short;
	info->scout = 5;
	info->torpedo = 27;
	info->speed = high;

	return info;
}
Equipment* CharacterInfo::getMainCannon()
{
	for (int i = 0; i < MAX_EQUIPMENT_NUMBER; i++)
	{
		if (equipments[i] != nullptr)
		{
			if (equipments[i]->type == Equipment_Type::small_cannon || equipments[i]->type == Equipment_Type::mid_cannon || equipments[i]->type == Equipment_Type::large_cannon)
				return equipments[i];
		}
	}
	return nullptr;
}
bool CharacterInfo::canAirBattle()
{
	if (type != CV && type != CVL && type != CVA &&type != BBCV && type != AV)
		return false;
	for (int i = 0; i < MAX_EQUIPMENT_NUMBER; i++)
	{
		if (equipments[i] != nullptr)
		{
			if (equipments[i]->type == Equipment_Type::fighter || 
				equipments[i]->type == Equipment_Type::attacker || 
				equipments[i]->type == Equipment_Type::bomber || 
				equipments[i]->type == Equipment_Type::seaplane)
				return true;
		}
	}
	return false;
}
bool CharacterInfo::getAirCraftId(std::string &plane1, std::string &plane2, std::string plane3)
{
	return false;
}
void CharacterInfo::getDamage(int damage)
{
	if (damage > 0)
	{
		this->currentHP = currentHP - damage;
		
		if (currentHP < 0)
			currentHP = 0;
		float persentage = (float)currentHP/(float)maxHP;
		if (persentage>0.75)
		{
			brokenType = BrokenType::normal;
		}
		else if (persentage>0.50) //小破
		{
			brokenType = BrokenType::tiny;
		}
		else if (persentage>0.25)//中破
		{
			brokenType = BrokenType::mid;
		}
		else if (persentage>0)//大破
		{
			brokenType = BrokenType::large;
		}
		else
		{
			brokenType = BrokenType::drown;
		}
	}
}
bool CharacterInfo::canAttack()
{
	if (type == CV || type == CVL)
	{
		float persentage = currentHP / maxHP;
		if (persentage <= 0.5)
			return false;
	}


	if (currentHP == 0)
		return false;

	return true;
}
void CharacterInfo::addEquipment(Equipment* equipment,int index)
{
	if (equipment != nullptr)
	{
		this->firePower += equipment->firePower;
		this->torpedo += equipment->torpedo;
		this->bomb += equipment->bomb;
		this->antiaircraft += equipment->antiaircraft;
		this->antisubmarine += equipment->antisubmarine;
		this->scout += equipment->scout;
		this->hitRate += equipment->hitRate;
		this->agility += equipment->agility;

		equipments[index] = equipment;
	}

}