#ifndef _MISSION_SELECT_PAGE_
#define _MISSION_SELECT_PAGE_
#include "cocos2d.h"
#include "GameModel.h"
#include "MissionContainer.h"
using namespace cocos2d;
class PortBattleLayer;
class MissionSelectPage :public Node{

public:
	MissionSelectPage(PortBattleLayer *parent);
	void moveOut();
	void moveIn();
	void setCurrentArea(Ref* pSender, int areaId);
	void startMission(Ref* pSender, int index);
	inline bool isHidden(){ return Hidden; }
private:
	int currentArea;
	PortBattleLayer* parent;
	Menu *menu;
	bool Hidden;
	MissionContainer *container1, *container2, *container3, *container4;

};
#endif