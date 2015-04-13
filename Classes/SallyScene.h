#ifndef _SALLY_SCENE_
#define _SALLY_SCENE_

#include "cocos2d.h"
#include "Mission.h"
#include "Compass.h"
#include "GameModel.h"
#include "formation.h"
using namespace cocos2d;

enum SallyStatus{
	sally_start,
	sally_move,
	sally_formation,
	sally_battle,
};
class SallyScene : public Scene{
public:
	SallyScene(Mission* mission);
	void setFormationCallback(Ref* pSender, FormationType formation);
private:

	SallyStatus status;

	
	Mission* mission;
	MissionNode* currentMissionNode;

	Sprite* bgImg;
	Sprite* sallyMap;
	Compass * bottomCompass;
	Sprite* bottomBorder;
	Label* bottomLabel;
	Sprite* temptimer;
	Sprite* ship;
	Sprite *flagShip;

	bool showingBottomPanel;

	Sprite* nodePointShader;

	std::vector<Formation*> formations;
	void initializeFormationPanel();
private: 
	void sallyStart();
	void sallyMove();
	void sallyBattle();
	void sallyFormation();
	void sallyFinish();
	void onStatusOverCallBack();
	void nextStatus(float DelayTime);
	
private://Bottom Panel
	void hideBottomPanel();
	void showBottomPanel();


};

#endif // _SALLY_SCENE_
