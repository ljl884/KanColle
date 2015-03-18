#ifndef _PORT_BATTLE_LAYER_
#define _PORT_BATTLE_LAYER_

#include "cocos2d.h"
using namespace cocos2d;
class MissionSelectPage;
class PortBattleLayer : public Layer
{
public:
	PortBattleLayer(Node *parent);

	void callBack(Ref* pSender);
	void ShowMissionSelectPage(Ref* pSender);
	void hideMissionPage();

private:
	Node * parent;

private:
	void initLayer();
	
	MissionSelectPage * missionPage;

};


#endif