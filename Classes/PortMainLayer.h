#ifndef _PORT_MAIN_LAYER_
#define _PORT_MAIN_LAYER_


#include "cocos2d.h"
#include "PortScene.h"
using namespace cocos2d;

class PortMainLayer : public Layer
{
public:
	PortMainLayer(PortScene *parent);
	~PortMainLayer();
	void updateGirl();
	

private:

	int girlflag;
	PortScene * parent;
	Sprite * floor;
	Sprite * desk;
	Sprite * wall;
	Sprite *window;
	Sprite*object;
	Sprite* chest;
	Sprite *girl;

private:
	void initLayer();
	void initMenu();

	void menuCallback(Ref* pSender);
	void battleCallback(Ref* pSender);
	void layerSelectCallback(Ref * pSender, LayerType type);
};


#endif