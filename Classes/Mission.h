#ifndef _MISSION_
#define _MISSION_

#include "cocos2d.h"
#include "MissionNode.h"
USING_NS_CC;


class Mission{
public:
	Mission();
	MissionNode* getNextNode();
	

	std::string id;
	int areaId;
	int index;
	std::string name;
	std::string missionName;
	std::string detail;

	std::vector<MissionNode*> nodes;
};

#endif 