#include "MissionNode.h"
#include "Helper.h"
MissionNode::MissionNode()
{
	this->enemyFleet = nullptr;
}
bool MissionNode::available(Fleet* allies)
{
	return true;
}
void MissionNode::setType(std::string type)
{
	if (type == "enemy")
		this->type = node_enemy;
	else if (type == "boss")
		this->type = node_boss;
	else if (type == "item")
		this->type = node_item;
	else if (type == "home")
		this->type = node_home;
	else
		this->type = node_empty;
}
void MissionNode::parseEnemyFleet(std::string FleetText)
{
	std::vector<std::string> strings;
	Helper::split(FleetText, "#", strings); //split text in script by "#"
	enemyFleet = new Fleet(0);
	for (int i = 0; i < strings.size(); i++)
	{
		enemyFleet->addShip(XMLParser::getInstance()->loadCharacterInfo(strings[i]));
	}

}