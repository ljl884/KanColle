#ifndef _LAYER_SELECTER_
#define _LAYER_SELECTER_

#include "cocos2d.h"
#include "PortScene.h"
using namespace cocos2d;

class LayerSelecter: public Node{
public:
	LayerSelecter(PortScene *parent,Point position);
	void MoveOut();
	void MoveIn();
private:
	PortScene *parent;
	Point initialPosition;
	Sprite *mainbody;
	Sprite *backgroud;

	Menu *menu;
	MenuItemImage *portItem;
	MenuItemImage *organizeItem;
	MenuItemImage *supplyItem;
	MenuItemImage *remodeItem;
	MenuItemImage *repairItem;
	MenuItemImage *factoryItem;



	void layerSelectCallback(Ref * pSender, LayerType type);
};

#endif