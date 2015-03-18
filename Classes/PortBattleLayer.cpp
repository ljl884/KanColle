#include "PortBattleLayer.h"
#include "MissionSelectPage.h"
PortBattleLayer::PortBattleLayer(Node* parent)
{
	this->parent = parent;
	initLayer();
}

void PortBattleLayer::initLayer()
{
	auto bgimg = Sprite::create("PortMain/image 350.jpg");
	this->addChild(bgimg);
	bgimg->setOpacity(255);
	bgimg->setZOrder(-5);
	bgimg->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	
	auto top_bar = Sprite::create("SallyMain/image 69.png");
	this->addChild(top_bar);
	top_bar->setPosition(450, 397);

	auto top_label = Sprite::create("SallyMain/image 389.png");
	this->addChild(top_label);
	top_label->setPosition(160, 397);

	auto strikeButton = MenuItemImage::create("SallyMain/image 391.png", "SallyMain/image 393.png", CC_CALLBACK_1(PortBattleLayer::ShowMissionSelectPage, this));
	strikeButton->setPosition(230, 240);
	auto strikeDescription = Sprite::create("SallyMain/image 388.png");
	strikeDescription->setPosition(230, 80);
	
	auto playactButton = MenuItemImage::create("SallyMain/image 396.png", "SallyMain/image 398.png", CC_CALLBACK_1(PortBattleLayer::callBack, this));
	playactButton->setPosition(450, 240);
	auto playactDescription = Sprite::create("SallyMain/image 386.png");
	playactDescription->setPosition(450, 80);
	
	auto expeditionButton = MenuItemImage::create("SallyMain/image 401.png", "SallyMain/image 402.png", CC_CALLBACK_1(PortBattleLayer::callBack, this));
	expeditionButton->setPosition(670, 240);
	auto expeditionDescription = Sprite::create("SallyMain/image 387.png");
	expeditionDescription->setPosition(670, 80);
	

	auto menu = Menu::create(strikeButton, playactButton, expeditionButton, NULL);
	menu->addChild(strikeDescription);
	menu->addChild(playactDescription);
	menu->addChild(expeditionDescription);
	menu->setPosition(0, 0);
	this->addChild(menu);

	//Sub Pages
	missionPage = new MissionSelectPage(this);
	missionPage->setPosition(800, 0);
	this->addChild(missionPage);
}

void PortBattleLayer::callBack(Ref* pSender)
{}
void PortBattleLayer::ShowMissionSelectPage(Ref* pSender)
{
	if (missionPage->isHidden())
	{
		missionPage->moveIn();
	}
	
}

void PortBattleLayer::hideMissionPage()
{
	this->missionPage->moveOut();
}