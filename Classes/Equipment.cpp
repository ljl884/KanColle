#include "Equipment.h"
#include "Helper.h"
#include "GameModel.h"
#define CARD_FOLDER "Equipment/card/"
#define LABEL_FOLDER "Equipment/btxt_flat/"
#define ITEM_UP_FOLDER "Equipment/item_up/"
#define ITEM_DOWN_FOLDER "Equipment/item_down/"
#define CARD_FOLDER "Equipment/card/"
#define REMODAL_FOLDER "Equipment/remodal/"
#define STATUS_FOLDER "Equipment/statustop_item/"

Equipment::Equipment()
{
	firePower = 0;
	torpedo = 0;
	bomb = 0;
	antiaircraft = 0;
	antisubmarine = 0;
	scout = 0;
	hitRate = 0;
	agility = 0;
	range = Shooting_Range::range_non;
	inGameId = GameModel::getInstance()->getEquipmentId();

}
std::string Equipment::getIcon()
{	

	switch (type)
	{
	case Equipment_Type::small_cannon:
		return "icons/image 3.png";
		break;
	case Equipment_Type::mid_cannon:
		return "icons/image 5.png";
		break;
	case Equipment_Type::large_cannon:
		return "icons/image 7.png";
		break;
	case Equipment_Type::secondary_cannon:
		return "icons/image 9.png";
		break;
	case Equipment_Type::air_defense_artillery:
		return "icons/image 31.png";
		break;
	case Equipment_Type::shell:
		return "icons/image 25.png";
		break;
	case Equipment_Type::torpedo:
		return "icons/image 11.png";
		break;
	case Equipment_Type::fighter:
		return "icons/image 13.png";
		break;
	case Equipment_Type::attacker:
		return "icons/image 17.png";
		break;
	case Equipment_Type::bomber:
		return "icons/image 15.png";
		break;
	case Equipment_Type::scout:
		return "icons/image 19.png";
		break;
	case Equipment_Type::seaplane:
		return "icons/image 21.png";
		break;
	case Equipment_Type::radio_detector:
		return "icons/image 23.png";
		break;
	case Equipment_Type::water_detecter:
		return "icons/image 37.png";
		break;
	case Equipment_Type::cast_machine:
		return "icons/image 35.png";
		break;
	case Equipment_Type::other:
		return "icons/image 1.png";
		break;
	default:
		return "icons/image 1.png";
		break;
	}
	
}
std::string Equipment::getCard()
{
	return CARD_FOLDER + id  + ".png";
}
std::string Equipment::getLabel()
{
	return LABEL_FOLDER + id + ".png";
}
std::string Equipment::getItemUp()
{
	return ITEM_UP_FOLDER + id + ".png";
}
std::string Equipment::getItemDown()
{
	return ITEM_DOWN_FOLDER + id + ".png";
}
std::string Equipment::getStatusTop()
{
	return STATUS_FOLDER + id + ".png";
}