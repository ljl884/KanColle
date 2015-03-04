#ifndef _ANIMATION_MAKER_
#define _ANIMATION_MAKER_

#include "cocos2d.h"
using namespace cocos2d;

class AnimationMaker
{
public:
	static float playPlaneAnimation(Node* parent,float delay);
	static float playAirBattleAnimation(Node* parent, float delay);
	static float playExplodeAnimation(Node* parent, float delay, Point position);
	static float playExplodeAnimation(Node* parent, float delay, Point position,int times);
	static float FlyToCenterLeftAndFadeOut(Node* target,float delay);
	static float FlyToPositionAndFadeOut(Node* target, float delay,Point position,float stayingTime);
	static void makeExplodeAnimation();
	static void playShakingAnimation(Node* target, float delay);
	static void playDamageNumberAnimation(Point position, Node*parent, float delay, bool miss, bool critical, int damage,CallFunc* callback);
	static void InitDamageNumber();
private:
	static bool damageNumberInitialized;
	static std::string int2str(int &);
};
#endif