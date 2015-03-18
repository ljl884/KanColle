#ifndef _MISSION_CONTAINER_
#define _MISSION_CONTAINER_

#include "cocos2d.h"

using namespace cocos2d;

class MissionContainer :public Node{
public:
	MissionContainer(int areaId,int index);
	void updateContainer(int areaId, int index);
private:
	Sprite* image;
	Sprite* passedIcon;
	bool locked;

};

#endif