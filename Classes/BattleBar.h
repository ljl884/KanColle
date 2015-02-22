#ifndef _BATTLE_BAR_
#define _BATTLE_BAR_

#include "cocos2d.h"

using namespace cocos2d;
enum GreenBarPosition
{
	top,
	topleft,
	center,
	bottom
};
enum GreenBarLableType
{
	scout_start,
	scouter_doesnt_back,
	enemy_scouted,
	enemy_scouted_scouter_doesnt_back,
	enemy_not_scouted,
	enemy_seen
};
class BattleBar{
public:
	BattleBar(Node* parent);
	void openAndCloseAnimation(GreenBarPosition position, Sprite*label);
	void openAndCloseAnimation(GreenBarPosition position, Sprite*label,float delay);
	void openAndCloseAnimation(GreenBarPosition position, GreenBarLableType type);
	void openAndCloseAnimation(GreenBarPosition position, GreenBarLableType type,float delay);
	void runAction(Action* action, GreenBarPosition position);
private:
	void init();
	void openAndCloseAnimation(Sprite * border, Sprite*label,float delay);
	Node* parent;
	Sprite *centerGreenBar;
	Sprite *topGreenBar;
	Sprite *bottomGreenBar;
	
	
};

#endif