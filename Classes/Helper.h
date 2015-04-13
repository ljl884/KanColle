#ifndef _HELPER_
#define _HELPER_

#include "cocos2d.h"
#include "XMLParser.h"

enum Ship_Type;

class Helper{
public:
	static std::string int2str(int i);
	static std::string getString(std::string name);
	static std::string getShipType(Ship_Type type);
	static std::string getMissionId(int areaId, int index);
	static void split(const std::string& src, const std::string& separator, std::vector<std::string>& dest);
};



#endif