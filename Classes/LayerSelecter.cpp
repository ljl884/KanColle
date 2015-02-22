#include "LayerSelecter.h"

LayerSelecter::LayerSelecter(PortScene* parent,Point position)
{
	this->parent = parent;
	this->initialPosition = position;
	this->setPosition(initialPosition);
	parent->addChild(this);
	this->setZOrder(2);
	mainbody = Sprite::create("PortMain/image 243.png");
	mainbody->setPosition(-10, 0);
	backgroud = Sprite::create("PortMain/image 242.png");
	backgroud->setPosition(0, 0);
	
	this->addChild(backgroud);
	this->addChild(mainbody);

	portItem = MenuItemImage::create("PortMain/image 275.png", "PortMain/image 277.png", CC_CALLBACK_1(LayerSelecter::layerSelectCallback, this, LayerType::main));
	portItem->setPosition(22, 0);
	organizeItem = MenuItemImage::create("PortMain/image 270.png", "PortMain/image 272.png", CC_CALLBACK_1(LayerSelecter::layerSelectCallback, this, LayerType::organize));
	organizeItem->setPosition(-30, 100);
	supplyItem = MenuItemImage::create("PortMain/image 250.png", "PortMain/image 252.png", CC_CALLBACK_1(LayerSelecter::layerSelectCallback, this, LayerType::supply));
	supplyItem->setPosition(-30, 50);
	remodeItem = MenuItemImage::create("PortMain/image 255.png", "PortMain/image 257.png", CC_CALLBACK_1(LayerSelecter::layerSelectCallback, this, LayerType::remode));
	remodeItem->setPosition(-30, 0);
	repairItem = MenuItemImage::create("PortMain/image 260.png", "PortMain/image 262.png", CC_CALLBACK_1(LayerSelecter::layerSelectCallback, this, LayerType::repair));
	repairItem->setPosition(-30, -50);
	factoryItem = MenuItemImage::create("PortMain/image 265.png", "PortMain/image 267.png", CC_CALLBACK_1(LayerSelecter::layerSelectCallback, this, LayerType::factory));
	factoryItem->setPosition(-30, -100);

	menu = Menu::create(portItem,organizeItem, supplyItem, remodeItem, repairItem, factoryItem, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
	
}
void LayerSelecter::layerSelectCallback(Ref * pSender, LayerType type)
{
	if (type == LayerType::main)
		MoveOut();
	parent->setCurrentLayer(type);

}

void LayerSelecter::MoveOut()
{
	this->runAction(MoveTo::create(0.3, this->initialPosition));
}
void LayerSelecter::MoveIn()
{
	this->runAction(MoveTo::create(0.3, ccp(this->initialPosition.x + 100, this->initialPosition.y)));
}