#ifndef _GAME_START_SCENE_
#define _GAME_START_SCENE_


#include "cocos2d.h"
using namespace cocos2d;

class GameStartScene :public Scene{
public:
	GameStartScene();
	void startGame(Ref* pSender);
private:
	
};
#endif