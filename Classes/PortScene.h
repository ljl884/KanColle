#ifndef _PORT_SCENE_
#define _PORT_SCENE_

#include "cocos2d.h"

class PortMainLayer;
class PortFactoryLayer;
class PortOrganizeLayer;
class PortRemodeLayer;
class PortRepairLayer;
class PortSupplyLayer;
class LayerSelecter;
using namespace cocos2d;

enum LayerType{
	main,
	organize,
	supply,
	remode,
	factory,
	repair,
	battle,
	empty
};
class PortScene : public Scene{
public:
	static Scene* createScene();
	void setCurrentLayer(LayerType type);
	void menuSettingCallback(Ref* pSender);
	void menuHandlingCallback(Ref* pSender);
	void changeFurnitureCallback(Ref* psSender);
	PortScene();
private:
	
	bool init();
	void layerSwithEffect();

private:

	Sprite *black;

	LayerSelecter *layerSelecter;
	LayerType currentLayerType;
	Layer* currentLayer;
	PortMainLayer * mainlayer;
	PortFactoryLayer *factroylayer;
	PortOrganizeLayer *organizelayer;
	PortRemodeLayer *remodelayer;
	PortRepairLayer *repairlayer;
	PortSupplyLayer *supplylayer;

	Sprite *bgImage;

	Label *labelFuel;
	Label *labelSteel;
	Label *labelAmmo;
	Label *labelAluminium;

	Sprite *title;
	Label *playerName;
	Label  *playerLevel;
	Label  *playerTitle;
	Label *fleetCount;
	Label *shipCount;
	Label *quickRepairCount;
	Label *devToolCount;
};

#endif