#ifndef _FORMATION_
#define _FORMATION_
#include "cocos2d.h"
#include "BattleModel.h"
using namespace cocos2d;


class Formation : public Node{
public:
	Formation(int shipCount, FormationType type);
	Formation(int shipCount, FormationType type,bool isEnemy);
	void initialPanel();
	FormationType getType();
	void addBattleBorder();
	void showPoints();
	void hidePoints();
private:
	void organizePoints();
	void danzong();
	void fuzong();
	void danheng();
	void lunxing();
private:
	std::string pointUrl;
	FormationType type;
	int shipCount;
	Sprite *border;
	std::vector<Sprite*> points;
};

#endif