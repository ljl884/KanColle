#ifndef _XMLPARSER_
#define _XMLPARSER_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "tinyxml2\tinyxml2.h"

using namespace cocos2d;
enum ScriptType{
	characterInfo
};
class XMLParser{
public :
	static XMLParser* getInstance()
	{
		if (instance == NULL)
			instance = new XMLParser();
		return instance;
	}
	 CharacterInfo* loadCharacterInfo(std::string name);
	
private:
	XMLParser();
	static XMLParser *instance;
	tinyxml2::XMLDocument characterDoc;
	tinyxml2::XMLElement* findNodeByName(std::string name, ScriptType type);
};
#endif