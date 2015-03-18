#include "XMLParser.h"

XMLParser * XMLParser::instance = NULL;

XMLParser::XMLParser()
{
	std::string xmlFile = FileUtils::getInstance()->fullPathForFilename("Data/CharacterInfo.xml").c_str();
	ssize_t bufferSize = 0;
	unsigned char* pBuffer = FileUtils::sharedFileUtils()->getFileData(xmlFile.c_str(), "rb", &bufferSize);
	characterDoc.Parse((const char*)pBuffer);

	std::string xmlFile2 = FileUtils::getInstance()->fullPathForFilename("Data/Strings.xml").c_str();
	unsigned char* pBuffer2 = FileUtils::sharedFileUtils()->getFileData(xmlFile2.c_str(), "rb", &bufferSize);
	stringsDoc.Parse((const char*)pBuffer2);

	std::string xmlFile3 = FileUtils::getInstance()->fullPathForFilename("Data/Equipment.xml").c_str();
	unsigned char* pBuffer3 = FileUtils::sharedFileUtils()->getFileData(xmlFile3.c_str(), "rb", &bufferSize);
	equipmentDoc.Parse((const char*)pBuffer3);

	std::string xmlFile4 = FileUtils::getInstance()->fullPathForFilename("Data/Mission.xml").c_str();
	unsigned char* pBuffer4 = FileUtils::sharedFileUtils()->getFileData(xmlFile4.c_str(), "rb", &bufferSize);
	missionDoc.Parse((const char*)pBuffer4);
}
Equipment* XMLParser::loadEquipmentInfo(std::string id)
{
	tinyxml2::XMLElement *node = findNodeByName(id, equipment);
	Equipment * equipment;
	if (NULL != node)
	{
		equipment = new Equipment();
		equipment->id = id;
		equipment->nameCH = node->FirstChildElement("name")->GetText();
		tinyxml2::XMLElement *firePower = node->FirstChildElement("firePower");
		if (firePower != nullptr)
			equipment->firePower = atoi(firePower->GetText());
		tinyxml2::XMLElement *torpedo = node->FirstChildElement("torpedo");
		if (torpedo != nullptr)
			equipment->torpedo = atoi(torpedo->GetText());
		tinyxml2::XMLElement *bomb = node->FirstChildElement("bomb");
		if (bomb != nullptr)
			equipment->bomb = atoi(bomb->GetText());
		tinyxml2::XMLElement *antiaircraft = node->FirstChildElement("antiaircraft");
		if (antiaircraft != nullptr)
			equipment->antiaircraft = atoi(antiaircraft->GetText());
		tinyxml2::XMLElement *antisubmarine = node->FirstChildElement("antisubmarine");
		if (antisubmarine != nullptr)
			equipment->antisubmarine = atoi(antisubmarine->GetText());
		tinyxml2::XMLElement *scout = node->FirstChildElement("scout");
		if (scout != nullptr)
			equipment->scout = atoi(scout->GetText());
		tinyxml2::XMLElement *hitRate = node->FirstChildElement("hitRate");
		if (hitRate != nullptr)
			equipment->hitRate = atoi(hitRate->GetText());
		tinyxml2::XMLElement *agility = node->FirstChildElement("agility");
		if (agility != nullptr)
			equipment->agility = atoi(agility->GetText());
		tinyxml2::XMLElement *range = node->FirstChildElement("range");
		if (range != nullptr)
		{
			const char* rangetxt = range->GetText();
			if ("long" == std::string(rangetxt))
				equipment->range = range_long;
			else if ("mid" == std::string(rangetxt))
				equipment->range = range_mid;
			else if ("short" == std::string(rangetxt))
				equipment->range = range_short;
			else if ("exlong" == std::string(rangetxt))
				equipment->range = range_exlong;
		}

		const char* type = node->FirstChildElement("type")->GetText();
		std::string str(type);
		if ("small_cannon" == str)
			equipment->type = small_cannon;
		else if ("mid_cannon" == str)
			equipment->type = mid_cannon;
		else if ("large_cannon" == str)
			equipment->type = large_cannon;
		else if ("secondary_cannon" == str)
			equipment->type = secondary_cannon;
		else if ("air_defense_artillery" == str)
			equipment->type = air_defense_artillery;
		else if ("shell" == str)
			equipment->type = shell;
		else if ("torpedo" == str)
			equipment->type = Equipment_Type::torpedo;
		else if ("fighter" == str)
			equipment->type = fighter;
		else if ("attacker" == str)
			equipment->type = attacker;
		else if ("bomber" == str)
			equipment->type = bomber;
		else if ("scout" == str)
			equipment->type = Equipment_Type::scout;
		else if ("seaplane" == str)
			equipment->type = seaplane;
		else if ("radio_detector" == str)
			equipment->type = radio_detector;
		else if ("water_detecter" == str)
			equipment->type = water_detecter;
		else if ("cast_machine" == str)
			equipment->type = cast_machine;
		else if ("other" == str)
			equipment->type = other;
		else if ("no_equipment" == str)
			equipment->type = no_equipment;
		else if ("unavailable" == str)
			equipment->type = unavailable;
		
			

	}
	return equipment;
}
CharacterInfo* XMLParser::loadCharacterInfo(std::string name)
{

	


	CharacterInfo *info = new CharacterInfo();
	
	tinyxml2::XMLElement *node = findNodeByName(name, characterInfo);
	
	if (NULL != node)
	{
		
		info->brokenType = normal;
		info->star = 1;//TODO
		info->currentFleet = -1;
		info->id = node->FirstChildElement("id")->GetText();
		info->nextId = node->FirstChildElement("nextId")->GetText();
		info->resourceFolder = node->FirstChildElement("resource")->GetText();
		info->name = node->FirstChildElement("name")->GetText();
		info->nameCH = node->FirstChildElement("nameCH")->GetText();
		info->level = atoi(node->FirstChildElement("level")->GetText());
		int hp = atoi(node->FirstChildElement("maxHP")->GetText());
		info->maxHP = hp;
		info->currentHP = hp;
		info->firePower = atoi(node->FirstChildElement("firePower")->GetText());
		info->armour = atoi(node->FirstChildElement("armour")->GetText());
		info->torpedo = atoi(node->FirstChildElement("torpedo")->GetText());
		info->agility = atoi(node->FirstChildElement("agility")->GetText());
		info->antiaircraft = atoi(node->FirstChildElement("antiaircraft")->GetText());
		info->capacity = atoi(node->FirstChildElement("capacity")->GetText());
		info->antisubmarine = atoi(node->FirstChildElement("antisubmarine")->GetText());
		info->scout = atoi(node->FirstChildElement("scout")->GetText());
		info->luck = atoi(node->FirstChildElement("luck")->GetText());
		info->fuelConsume = atoi(node->FirstChildElement("fuelConsume")->GetText());
		info->ammoConsume = atoi(node->FirstChildElement("ammoConsume")->GetText());
		info->steelConsume = atoi(node->FirstChildElement("steelConsume")->GetText());
		const char* speed = node->FirstChildElement("speed")->GetText();
		if ("high" == std::string(speed))
			info->speed = high;
		else if ("low" == std::string(speed))
			info->speed = low;

		const char* range = node->FirstChildElement("range")->GetText();
		if ("long" == std::string(range))
			info->range = range_long;
		else if ("mid" == std::string(range))
			info->range = range_mid;
		else if ("short" == std::string(range))
			info->range = range_short;
		else if ("exlong" == std::string(range))
			info->range = range_exlong;

		const char* type = node->FirstChildElement("type")->GetText();
		std::string str(type);
		if ("DD" == str)
			info->type = DD;
		else if ("CL" == str)
			info->type = CL;
		else if ("CA" == str)
			info->type = CA;
		else if ("CLT" == str)
			info->type = CLT;
		else if ("CAV" == str)
			info->type = CAV;
		else if ("BB" == str)
			info->type = BB;
		else if ("CVA" == str)
			info->type = CVA;
		else if ("CV" == str)
			info->type = CV;
		else if ("CVL" == str)
			info->type = CVL;
		else if ("AV" == str)
			info->type = AV;
		else if ("SS" == str)
			info->type = SS;
		else if ("SSV" == str)
			info->type = SSV;
		else if ("SUP" == str)
			info->type = SUP;		


		//Equipment
		tinyxml2::XMLElement *e1 = node->FirstChildElement("Equipment1");
		if (e1!=NULL)
			info->addEquipment( loadEquipmentInfo(e1->GetText()),0);
		tinyxml2::XMLElement *e2 = node->FirstChildElement("Equipment2");
		if (e2 != NULL)
			info->addEquipment(loadEquipmentInfo(e2->GetText()), 1);
		tinyxml2::XMLElement *e3 = node->FirstChildElement("Equipment3");
		if (e3 != NULL)
			info->addEquipment(loadEquipmentInfo(e3->GetText()), 2);
		tinyxml2::XMLElement *e4 = node->FirstChildElement("Equipment4");
		if (e4 != NULL)
			info->addEquipment(loadEquipmentInfo(e4->GetText()), 3);
		
	}
	return info;

	
	return CharacterInfo::makeDefaultInfo();
}

Mission* XMLParser::loadMissionInfo(std::string id)
{
	auto mission = new Mission();

	tinyxml2::XMLElement *node = findNodeByName(id, ScriptType::mission);
	if (node != NULL)
	{
		mission->id = id;
		mission->areaId = atoi( node->FirstChildElement("area")->GetText());
		mission->index = atoi(node->FirstChildElement("index")->GetText());
		mission->name = node->FirstChildElement("name")->GetText();
		mission->missionName = node->FirstChildElement("missionName")->GetText();
		mission->detail = node->FirstChildElement("Detail")->GetText();

		//MissionNode
		tinyxml2::XMLElement *missionnode = node->FirstChildElement("Node");
		while (missionnode != NULL)
		{
			auto newMissionNode = new MissionNode();
			newMissionNode->setType(missionnode->FirstChildElement("type")->GetText());
			newMissionNode->position = 
				Point(atoi(missionnode->FirstChildElement("positionX")->GetText()),
					  atoi(missionnode->FirstChildElement("positionY")->GetText()));
			tinyxml2::XMLElement *directionNode = missionnode->FirstChildElement("direction");
			if (directionNode != NULL)
				newMissionNode->compassDirection = Compass::parseDirection(directionNode->GetText());
			tinyxml2::XMLElement *enemyFleetNode= missionnode->FirstChildElement("enemy");
			if (enemyFleetNode != NULL)
				newMissionNode->parseEnemyFleet(enemyFleetNode->GetText());
			int parentIndex = atoi(missionnode->FirstChildElement("parent")->GetText());
			if (parentIndex != -1)
				mission->nodes[parentIndex]->children.push_back(newMissionNode);
			mission->nodes.push_back(newMissionNode);
			missionnode = missionnode->NextSiblingElement();

		}

	}
	return mission;
}
tinyxml2::XMLElement* XMLParser::findNodeByName(std::string name, ScriptType type)
{
	const char* nodeName;
	tinyxml2::XMLDocument* doc;
	std::string nameOrId = "name";
	switch (type)
	{
	case characterInfo:
		nodeName = "Character";
		doc = &this->characterDoc;
		break;
	case strings:
		nodeName = "String";
		doc = &this->stringsDoc;
		break;
	case equipment:
		nodeName = "Equipment";
		doc = &this->equipmentDoc;
		nameOrId = "id";
		break;
	case mission:
		nodeName = "Mission";
		doc = &this->missionDoc;
		nameOrId = "id";
	default:
		break;
	}
	tinyxml2::XMLElement *root = doc->RootElement();
	tinyxml2::XMLElement *node = root->FirstChildElement(nodeName);
	while (node)
	{
		const char* tempName = node->FirstChildElement(nameOrId.c_str())->GetText();
		if (name == tempName)
			return node;
		node = node->NextSiblingElement();
	}
	return NULL;
}

std::string XMLParser::getStringByName(std::string name)
{
	std::string string="";
	tinyxml2::XMLElement *node = findNodeByName(name, strings);
	if (node != NULL)
	{
		string = node->FirstChildElement("context")->GetText();
	}
	return string;
}