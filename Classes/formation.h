#ifndef _FORMATION_
#define _FORMATION_
#include "cocos2d.h"
#include "BattleModel.h"
using namespace cocos2d;

class SallyScene;
class Formation : public Node{
public:
	Formation(int shipCount, FormationType type);
	Formation(int shipCount, FormationType type,bool isEnemy);
	Formation(FormationType type,SallyScene* parent);//initial with Formation panel with button. Used only in sally scene
	void initializePanel(SallyScene *parentSallyScene);
	FormationType getType();
	void addBattleBorder();
	void showPoints();
	void hidePoints();
	void rotatePoints();
private:
	void organizePoints();
	void danzong();
	void fuzong();
	void tixing();
	void danheng();
	void lunxing();
	
private:
	std::string pointUrl;
	FormationType type;
	int shipCount;
	Sprite *border;
	std::vector<Sprite*> points;
	

	//Sally Panel
	Sprite* panelBg;
	MenuItemImage * button;
	SallyScene *parentSallyScene;
};

#endif