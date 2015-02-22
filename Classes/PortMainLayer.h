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
	void setGirl(std::string resource);
	void switchGirl();

private:

	int girlflag;
	PortScene * parent;
	Sprite * floor;
	Sprite * wall;

	Sprite *girl;

private:
	void initLayer();
	void initMenu();

	void menuCallback(Ref* pSender);
	void battleCallback(Ref* pSender);
	void layerSelectCallback(Ref * pSender, LayerType type);
};


#endif