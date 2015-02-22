#include "XMLParser.h"

XMLParser * XMLParser::instance = NULL;

XMLParser::XMLParser()
{
	std::string xmlFile = FileUtils::getInstance()->fullPathForFilename("Data/CharacterInfo.xml").c_str();
	//characterDoc.LoadFile(FileUtils::getInstance()->fullPathForFilename("Data\\CharacterInfo.xml").c_str());
	ssize_t bufferSize = 0;
	unsigned char* pBuffer = FileUtils::sharedFileUtils()->getFileData(xmlFile.c_str(), "rb", &bufferSize);
	//pBuffer[bufferSize - 1] = '\0';
	characterDoc.Parse((const char*)pBuffer);
}
CharacterInfo* XMLParser::loadCharacterInfo(std::string name)
{

	


	CharacterInfo *info = new CharacterInfo();
	
	tinyxml2::XMLElement *node = findNodeByName(name, characterInfo);
	
	if (NULL != node)
	{
		
		info->brokenType = normal;

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
		if ("high" == speed)
			info->speed = high;
		else if ("low" == speed)
			info->speed = low;

		const char* range = node->FirstChildElement("range")->GetText();
		if ("long" == range)
			info->range = range_long;
		else if ("mid" == speed)
			info->range = range_mid;
		else if ("short" == range)
			info->range = range_short;
		else if ("exlong" == range)
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
	}
	return info;

	
	return CharacterInfo::makeDefaultInfo();
}


tinyxml2::XMLElement* XMLParser::findNodeByName(std::string name, ScriptType type)
{
	const char* nodeName;
	tinyxml2::XMLDocument* doc;
	switch (type)
	{
	case characterInfo:
		nodeName = "Character";
		doc = &this->characterDoc;
		break;
	default:
		break;
	}
	tinyxml2::XMLElement *root = doc->RootElement();
	tinyxml2::XMLElement *node = root->FirstChildElement(nodeName);
	while (node)
	{
		const char* tempName = node->FirstChildElement("name")->GetText();
		if (name == tempName)
			return node;
		node = node->NextSiblingElement();
	}
	return NULL;
}

