#ifndef _HP_BAR_
#define _HP_BAR_

#include "cocos2d.h"
using namespace cocos2d;

class HpBar :public Node{
public:
	HpBar(int maxHp, int currentHp);
	void setCurrentHp(int currentHp);
	void setHp(int maxHp, int currentHp);
private:
	int maxHp;
	int currentHp;
	Sprite * bar;
};

#endif