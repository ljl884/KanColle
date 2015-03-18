#ifndef _MISSION_NODE_
#define _MISSION_NODE_

#include "cocos2d.h"
#include "Fleet.h"
#include "Compass.h"
USING_NS_CC;

enum MissionNodeType
{
	node_enemy,
	node_item,
	node_empty,
	node_boss,
	node_home,
	node_disaster
};
class MissionNode{
public:
	MissionNode();
	void setType(std::string type);
	bool available(Fleet *allies);
	void parseEnemyFleet(std::string enemyFleet);
	Compass_Direction compassDirection;
	MissionNodeType type;
	Point position;
	Fleet *enemyFleet;
	std::vector<MissionNode*> children;
};


#endif