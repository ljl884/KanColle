#include "PortMainLayer.h"

#include "BattleModel.h"
#include "GameScene.h"
PortMainLayer::PortMainLayer(PortScene* parent)
{
	this->parent = parent;
	girl = nullptr;
	initLayer();
	girlflag = 0;
}

void PortMainLayer::initLayer()
{
	//furniture
	floor = Sprite::create("furniture/floor/022.png");
	floor->setPosition(400, 100);
	this->addChild(floor);
	wall = Sprite::create("furniture/wall/001.png");
	wall->setPosition(400, 285);
	this->addChild(wall);

	//buttons
	initMenu();

	//girl
	setGirl("153DAFENG");
}

void PortMainLayer::initMenu()
{
	auto battleButton = MenuItemImage::create("PortMain/image 407.png", "PortMain/image 407.png", CC_CALLBACK_1(PortMainLayer::battleCallback, this));
	battleButton->setPosition((145+(300-145)/2), 210);
	Sprite* battleButtonShip = Sprite::create("PortMain/image 408.png");
	Sprite* battleButtonGo = Sprite::create("PortMain/image 409.png");
	battleButtonShip->setPosition(67, 100);
	battleButtonGo->setPosition(67, 50);
	battleButton->addChild(battleButtonShip);
	battleButton->addChild(battleButtonGo);

	auto organizeButton = MenuItemImage::create("PortMain/image 434.png", "PortMain/image 441.png", CC_CALLBACK_1(PortMainLayer::layerSelectCallback, this,LayerType::organize));
	organizeButton->setPosition(battleButton->getPosition().x, 340);
	auto supplyButton = MenuItemImage::create("PortMain/image 454.png", "PortMain/image 461.png", CC_CALLBACK_1(PortMainLayer::layerSelectCallback, this, LayerType::supply));
	supplyButton->setPosition(100, 260);
	auto remodeButton = MenuItemImage::create("PortMain/image 385.png", "PortMain/image 392.png", CC_CALLBACK_1(PortMainLayer::layerSelectCallback, this, LayerType::remode));
	remodeButton->setPosition(345, 260);
	auto repairButton = MenuItemImage::create("PortMain/image 444.png", "PortMain/image 451.png", CC_CALLBACK_1(PortMainLayer::layerSelectCallback, this, LayerType::repair));
	repairButton->setPosition(145, 110);
	auto factoryButton = MenuItemImage::create("PortMain/image 395.png", "PortMain/image 402.png", CC_CALLBACK_1(PortMainLayer::layerSelectCallback, this, LayerType::factory));
	factoryButton->setPosition(300, 110);

	auto menu = Menu::create(organizeButton, repairButton, factoryButton, battleButton, supplyButton, remodeButton, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);

}
void PortMainLayer::switchGirl()
{
	if (girlflag == 0)
	{
		setGirl("003NAKE");
		girlflag = 1;
	}
	else if (girlflag == 1)
	{
		setGirl("136DAHEGAI");
		girlflag = 2;
	}
	else if (girlflag == 2)
	{
		setGirl("144XILIGAIER");
		girlflag = 3;
	}
	else if (girlflag == 3)
	{
		setGirl("278JIAHEGAI");
		girlflag = 4;
	}
	else if (girlflag == 4)
	{
		setGirl("277CHICHENGGAI");
		girlflag = 5;
	}
	else if (girlflag == 5)
	{
		setGirl("153DAFENG");
		girlflag = 0;
	}
	
}
void PortMainLayer::setGirl(std::string resource)
{

	
	if (girl == nullptr)
		girl = Sprite::create("Character/" + resource + "/image 17.png");
	girl->setTexture("Character/" + resource + "/image 17.png");
	this->addChild(girl);
	girl->setPosition(600, 0);
	girl->runAction(RepeatForever::create((ActionInterval*)Sequence::create(ScaleTo::create(4, 1.02), ScaleTo::create(4, 1), NULL)));
}
void  PortMainLayer::menuCallback(Ref* pSender)
{

}
void PortMainLayer::battleCallback(Ref* pSender)
{
	auto model = new BattleModel();
	auto scene = new GameScene(model);
	Director::getInstance()->replaceScene(scene);
}
void PortMainLayer::layerSelectCallback(Ref * pSender,LayerType type)
{
	parent->setCurrentLayer(type);
}
PortMainLayer::~PortMainLayer()
{
}
