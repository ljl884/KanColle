#ifndef _XMLPARSER_
#define _XMLPARSER_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "Mission.h"
#include "tinyxml2\tinyxml2.h"

using namespace cocos2d;
enum ScriptType{
	characterInfo,
	equipment,
	strings,
	mission
};
class XMLParser{
public :
	static XMLParser* getInstance()
	{
		if (instance == NULL)
			instance = new XMLParser();
		return instance;
	}
	Equipment* loadEquipmentInfo(std::string id);
	CharacterInfo* loadCharacterInfo(std::string name);
	Mission* loadMissionInfo(std::string id);
	std::string getStringByName(std::string name);
	 
	
private:
	XMLParser();
	static XMLParser *instance;
	tinyxml2::XMLDocument characterDoc;
	tinyxml2::XMLDocument equipmentDoc;
	tinyxml2::XMLDocument stringsDoc;
	tinyxml2::XMLDocument missionDoc;
	tinyxml2::XMLElement* findNodeByName(std::string name, ScriptType type);
};
#endif