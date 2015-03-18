#include "MissionSelectPage.h"
#include "PortBattleLayer.h"
#include "SallyScene.h"
#include "XMLParser.h"
#include "Helper.h"

MissionSelectPage::MissionSelectPage(PortBattleLayer *parent)
{
	this->parent = parent;
	Hidden = true;
	
	auto bgimg = Sprite::create("SallyMain/image 67.png");
	this->addChild(bgimg);
	bgimg->setOpacity(250);
	bgimg->setPosition(450, 197);

	auto top_bar = Sprite::create("SallyMain/image 69.png");
	this->addChild(top_bar);
	top_bar->setPosition(450, 397);

	auto top_label = Sprite::create("SallyMain/image 410.png");
	this->addChild(top_label);
	top_label->setPosition(160, 397);

	auto title_label = Sprite::create("SallyMain/image 409.png");
	this->addChild(title_label);
	title_label->setPosition(280, 365);

	//containers
	currentArea = 1;
	container1 = new MissionContainer(currentArea, 0);
	container2 = new MissionContainer(currentArea, 1);
	container3 = new MissionContainer(currentArea, 2);
	container4 = new MissionContainer(currentArea, 3);
	container1->setPosition(290, 280);
	container2->setPosition(620, 280);
	container3->setPosition(290, 140);
	container4->setPosition(620, 140);
	this->addChild(container1);
	this->addChild(container2);
	this->addChild(container3);
	this->addChild(container4);
	//mission buttons
	auto mb = Sprite::create("SallyMain/image 481.png");
	mb->setOpacity(0);
	auto missionButton1 = MenuItemSprite::create(mb, Sprite::create("SallyMain/image 481.png"),CC_CALLBACK_1(MissionSelectPage::startMission,this,0));
	missionButton1->setPosition(290, 280);

	auto missionButton2 = MenuItemSprite::create(mb, Sprite::create("SallyMain/image 481.png"), CC_CALLBACK_1(MissionSelectPage::startMission, this, 1));
	missionButton2->setPosition(620, 280);

	auto missionButton3 = MenuItemSprite::create(mb, Sprite::create("SallyMain/image 481.png"), CC_CALLBACK_1(MissionSelectPage::startMission, this, 2));
	missionButton3->setPosition(290, 140);

	auto missionButton4 = MenuItemSprite::create(mb, Sprite::create("SallyMain/image 481.png"), CC_CALLBACK_1(MissionSelectPage::startMission, this, 3));
	missionButton4->setPosition(620, 140);

	//top right buttons
	auto strikeButton = MenuItemImage::create("SallyMain/image 87.png", "SallyMain/image 85.png", CC_CALLBACK_1(PortBattleLayer::ShowMissionSelectPage, parent));
	strikeButton->setPosition(580, 365);
	auto playactButton = MenuItemImage::create("SallyMain/image 73.png", "SallyMain/image 75.png", CC_CALLBACK_1(PortBattleLayer::callBack, parent));
	playactButton->setPosition(660, 365);
	auto expeditionButton = MenuItemImage::create("SallyMain/image 78.png", "SallyMain/image 80.png", CC_CALLBACK_1(PortBattleLayer::callBack, parent));
	expeditionButton->setPosition(740, 365);
	
	//area buttons
	auto area1 = MenuItemImage::create("SallyMain/image 91.png", "SallyMain/image 93.png", CC_CALLBACK_1(MissionSelectPage::setCurrentArea, this,1));
	area1->setPosition(160, 50);
	auto area2 = MenuItemImage::create("SallyMain/image 96.png", "SallyMain/image 100.png", CC_CALLBACK_1(MissionSelectPage::setCurrentArea, this, 2));
	area2->setPosition(230, 50);
	auto area3 = MenuItemImage::create("SallyMain/image 103.png", "SallyMain/image 105.png", CC_CALLBACK_1(MissionSelectPage::setCurrentArea, this, 3));
	area3->setPosition(300, 50);
	auto area4 = MenuItemImage::create("SallyMain/image 108.png", "SallyMain/image 112.png", CC_CALLBACK_1(MissionSelectPage::setCurrentArea, this, 4));
	area4->setPosition(370, 50);
	auto area5 = MenuItemImage::create("SallyMain/image 115.png", "SallyMain/image 117.png", CC_CALLBACK_1(MissionSelectPage::setCurrentArea, this, 5));
	area5->setPosition(440, 50);
	auto area6 = MenuItemImage::create("SallyMain/image 120.png", "SallyMain/image 122.png", CC_CALLBACK_1(MissionSelectPage::setCurrentArea, this, 6));
	area6->setPosition(510, 50);

	menu = Menu::create(missionButton1, missionButton2 ,missionButton3,missionButton4,strikeButton, playactButton, expeditionButton, area1, area2, area3, area4, area5, area6, NULL);
	this->addChild(menu);
	menu->setPosition(0, 0);
}
void MissionSelectPage::moveOut()
{
	if (!Hidden)
	{
		this->runAction(MoveBy::create(0.2, ccp(800, 0)));
		Hidden = true;
	}

}
void MissionSelectPage::moveIn()
{
	if (Hidden)
	{
		this->runAction(MoveBy::create(0.2, ccp(-800, 0)));
		Hidden = false;
	}
}
void  MissionSelectPage::setCurrentArea(Ref* pSender, int areaId)
{
	this->currentArea = areaId;
	container1->updateContainer(currentArea, 0);
	container2->updateContainer(currentArea, 1);
	container3->updateContainer(currentArea, 2);
	container4->updateContainer(currentArea, 3);
}
void MissionSelectPage::startMission(Ref* pSender, int index)
{
	//auto model = new BattleModel(GameModel::getInstance()->getFleet(0), new Fleet(5), DanZong, LunXing);
	//auto scene = new GameScene(model);
	auto scene = new SallyScene(XMLParser::getInstance()->loadMissionInfo(Helper::getMissionId(currentArea, index)));
	Director::getInstance()->replaceScene(scene);
}