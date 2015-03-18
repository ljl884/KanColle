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
	floor->setZOrder(-2);
	this->addChild(floor);
	wall = Sprite::create("furniture/wall/012.png");
	wall->setPosition(400, 285);
	wall->setZOrder(-2);
	this->addChild(wall);
	object = Sprite::create("furniture/object/015.png");
	object->setPosition(80, 380);
	object->setZOrder(-2);
	this->addChild(object);
	desk = Sprite::create("furniture/desk/021.png");
	desk->setPosition(170, 200);
	desk->setZOrder(-2);
	this->addChild(desk);
	window = Sprite::create("furniture/window/017.png");
	window->setPosition(450, 300);
	window->setZOrder(-2);
	this->addChild(window);
	
	chest = Sprite::create("furniture/chest/003.png");
	chest->setPosition(700, 250);
	chest->setZOrder(-2);
	this->addChild(chest);

	//girl
	updateGirl();

	//buttons
	initMenu();

	
}

void PortMainLayer::initMenu()
{
	auto battleButton = MenuItemImage::create("PortMain/image 407.png", "PortMain/image 407.png", CC_CALLBACK_1(PortMainLayer::layerSelectCallback, this,LayerType::battle));
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

	MenuItemSprite* settingButton = MenuItemImage::create("PortMain/image 81.png", "PortMain/image 81.png", CC_CALLBACK_1(PortScene::menuSettingCallback, parent));
	settingButton->setPosition(776, 28);


	auto menu = Menu::create(organizeButton, repairButton, factoryButton, battleButton, supplyButton, remodeButton,settingButton, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);

}

void PortMainLayer::updateGirl()
{

	std::string resource = GameModel::getInstance()->getFleet(0)->getShip(0)->resourceFolder;
	if (girl == nullptr)
		girl = Sprite::create("Character/" + resource + "/image 17.png");
	girl->setTexture("Character/" + resource + "/image 17.png");
	Size size = girl->getContentSize();
	if (size.height>799)
		girl->setAnchorPoint(Vec2(0.5, 0.45));
	else if (size.height > 699)
	girl->setAnchorPoint(Vec2(0.5, 0.4));
	else
		girl->setAnchorPoint(Vec2(0.5, 0.25));
	this->addChild(girl);
	girl->setPosition(600, 0);
	girl->setZOrder(-1);
	girl->runAction(RepeatForever::create((ActionInterval*)Sequence::create(ScaleTo::create(4, 1.02), ScaleTo::create(4, 1), NULL)));
}
void  PortMainLayer::menuCallback(Ref* pSender)
{

}
void PortMainLayer::battleCallback(Ref* pSender)
{
	
}
void PortMainLayer::layerSelectCallback(Ref * pSender,LayerType type)
{
	parent->setCurrentLayer(type);
}
PortMainLayer::~PortMainLayer()
{
}
