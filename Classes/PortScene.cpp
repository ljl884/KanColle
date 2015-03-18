#include"PortScene.h"	
#include "GameModel.h"
#include "PortMainLayer.h"
#include "PortFactoryLayer.h"
#include "PortOrganizeLayer.h"
#include "PortRemodeLayer.h"
#include "PortRepairLayer.h"
#include "PortSupplyLayer.h"
#include "LayerSelecter.h"
#include "PortBattleLayer.h"
PortScene* PortScene::createScene()
{
	auto *scene = new PortScene();
	return scene;
}

PortScene::PortScene()
{	
	mainlayer = nullptr;
	factroylayer = nullptr;
	repairlayer = nullptr;
	remodelayer = nullptr;
	supplylayer = nullptr;
	organizelayer = nullptr;
	battlelayer = nullptr;
	black = nullptr;
	title = nullptr;
	currentLayerType = empty;
	setCurrentLayer(main);
	init();


}
void PortScene::setCurrentLayer(LayerType type)
{
	switch (type)
	{
	case main:
		if (currentLayerType == LayerType::main)
			return;
		//layerSwithEffect();
		if(title!=nullptr)
			title->setTexture("PortMain/image 283.png");
		if (mainlayer == nullptr)
		{
			mainlayer = new PortMainLayer(this);
			this->addChild(mainlayer);
		}
			
		if (currentLayerType != LayerType::empty)
			currentLayer->setVisible(false);
		currentLayer = mainlayer;
		mainlayer->setVisible(true);
		currentLayerType = LayerType::main;
		
		break;
	case battle:
		if (currentLayerType == LayerType::battle)
			return;
		if (title!= nullptr)
			title->setTexture("PortMain/image 295.png");
		layerSelecter->MoveIn();
		if (battlelayer == nullptr)
		{
			battlelayer = new PortBattleLayer(this);
			this->addChild(battlelayer);
		}
		if (currentLayerType != LayerType::empty)
			currentLayer->setVisible(false);
		currentLayer = battlelayer;
		currentLayer->setZOrder(-1);
		battlelayer->setVisible(true);
		battlelayer->hideMissionPage();
		currentLayerType = LayerType::battle;
		break;
	case organize:
		if (currentLayerType == LayerType::organize)
			return;
		//layerSwithEffect();
		title->setTexture("PortMain/image 289.png");
		bgImage->runAction(MoveTo::create(0.3,ccp(800, 210)));
		layerSelecter->MoveIn();
		if (organizelayer == nullptr)
		{
			organizelayer = new PortOrganizeLayer(this);
			this->addChild(organizelayer);
		}
		if (currentLayerType != LayerType::empty)
			currentLayer->setVisible(false);
		currentLayer = organizelayer;
		organizelayer->setVisible(true);
		currentLayerType = LayerType::organize;
		break;
	case supply:
		if (currentLayerType == LayerType::supply)
			return;
		//layerSwithEffect();
		title->setTexture("PortMain/image 285.png");
		bgImage->runAction(MoveTo::create(0.3, ccp(1600, 210)));
		layerSelecter->MoveIn();
		if (supplylayer == nullptr)
		{
			supplylayer = new PortSupplyLayer(this);
			this->addChild(supplylayer);
		}
		if (currentLayerType != LayerType::empty)
			currentLayer->setVisible(false);
		currentLayer = supplylayer;
		supplylayer->setVisible(true);
		currentLayerType = LayerType::supply;
		break;
	case remode:
		if (currentLayerType == LayerType::remode)
			return;
		//layerSwithEffect();
		title->setTexture("PortMain/image 287.png");
		bgImage->runAction(MoveTo::create(0.3, ccp(-780, 210)));
		layerSelecter->MoveIn();
		if (remodelayer == nullptr)
		{
			remodelayer = new PortRemodeLayer(this);
			this->addChild(remodelayer);
		}
		if (currentLayerType != LayerType::empty)
			currentLayer->setVisible(false);
		currentLayer = remodelayer;
		remodelayer->setVisible(true);
		currentLayerType = LayerType::remode;
		break;
	case factory:
		if (currentLayerType == LayerType::factory)
			return;
		//layerSwithEffect();
		title->setTexture("PortMain/image 293.png");
		bgImage->runAction(MoveTo::create(0.3, ccp(-490, 210)));
		layerSelecter->MoveIn();
		if (factroylayer == nullptr)
		{
			factroylayer = new PortFactoryLayer(this);
			this->addChild(factroylayer);
		}
		if (currentLayerType != LayerType::factory)
			currentLayer->setVisible(false);
		currentLayer = factroylayer;
		factroylayer->setVisible(true);
		currentLayerType = LayerType::factory;
		break;
	case repair:
		if (currentLayerType == LayerType::repair)
			return;
		//layerSwithEffect();
		title->setTexture("PortMain/image 291.png");
		bgImage->runAction(MoveTo::create(0.3, ccp(0, 210)));
		layerSelecter->MoveIn();
		if (repairlayer == nullptr)
		{
			repairlayer = new PortRepairLayer(this);
			this->addChild(repairlayer);
		}
		if (currentLayerType != LayerType::repair)
			currentLayer->setVisible(false);
		currentLayer = repairlayer;
		repairlayer->setVisible(true);
		currentLayerType = LayerType::repair;
		break;
	
	default:
		break;
	}
}
void PortScene::layerSwithEffect()
{
	if (nullptr == black)
	{
		black = Sprite::create("PortMain/black.png");
		black->setPosition(400, 240);
		black->setZOrder(20);
		this->addChild(black);
		black->setOpacity(0);
	}
	black->runAction(Sequence::create(FadeIn::create(0.2), FadeOut::create(0.2), NULL));
}
bool PortScene::init()
{

	


	bgImage = Sprite::create("PortMain/image 345.jpg");
	bgImage->setPosition(800, 210);
	bgImage->setZOrder(-3);
	this->addChild(bgImage);
	
	layerSelecter = new LayerSelecter(this,ccp(-50,220));
	

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//top left circle
	auto border_top_left = Sprite::create("PortMain/image 157.png");
	border_top_left->setPosition(48, 439);
	auto *circleAction = RotateBy::create(0.01, 6);
	auto *sequence = Sequence::create(circleAction, DelayTime::create(0.99), NULL);
	auto *repeat = RepeatForever::create((ActionInterval*)sequence);
	border_top_left->runAction(repeat);
	this->addChild(border_top_left);

	auto border_circle = Sprite::create("PortMain/image 281.png");
	border_circle->setPosition(62, 423);
	border_circle->setZOrder(1);
	this->addChild(border_circle);

	title = Sprite::create("PortMain/image 283.png");
	title->setPosition(49, 438);
	title->setZOrder(1);
	auto *circleAction2 = RotateBy::create(1, 13);
	auto *sequence2 = Sequence::create(circleAction2, NULL);
	auto *repeat2 = RepeatForever::create((ActionInterval*)sequence2);
	title->runAction(repeat2);
	this->addChild(title);

	auto *shader = Sprite::create("PortMain/image 300.png");
	shader->setPosition(49, 438);
	shader->setZOrder(1);
	shader->setOpacity(10);
	shader->runAction(RepeatForever::create((ActionInterval*)Sequence::create(FadeTo::create(1.5,170), FadeTo::create(1.5,10), NULL)));
	this->addChild(shader);

	//title bar
	auto *titleBar = Sprite::create("PortMain/image 160.png");
	titleBar->setPosition(400, 447);
	titleBar->setOpacity(200);
	this->addChild(titleBar);

	

	//borders
	auto *border_bottom_1 = Sprite::create("PortMain/image 236.png");
	border_bottom_1->setPosition(550, 5);
	this->addChild(border_bottom_1);

	auto *border_bottom_2 = Sprite::create("PortMain/image 235.png");
	border_bottom_2->setPosition(150, -2);
	this->addChild(border_bottom_2);

	auto *border_left = Sprite::create("PortMain/image 232.png");
	border_left->setPosition(8, 232);
	this->addChild(border_left);

	auto *border_top = Sprite::create("PortMain/image 168.png");
	border_top->setPosition(550, 475);
	this->addChild(border_top);
	//clock
	auto *clockBg = Sprite::create("PortMain/image 233.png");
	clockBg->setPosition(52, 40);
	this->addChild(clockBg);

	//player info
	playerName = Label::create();
	playerName->setString("Made By Wentao");
	playerName->setAlignment(TextHAlignment::LEFT);
	playerName->setPosition(170, 465);
	this->addChild(playerName);

	auto *levelLabel = Sprite::create("PortMain/image 167.png");
	levelLabel->setPosition(345, 463);
	this->addChild(levelLabel);

	playerLevel = Label::create();
	//gamemodel->getPlayerLevel();
	playerLevel->setString("48");
	playerLevel->setPosition(420, 462);
	this->addChild(playerLevel);

	auto *fleetCountLabel = Sprite::create("PortMain/image 223.png");
	fleetCountLabel->setPosition(520, 462);
	this->addChild(fleetCountLabel);

	fleetCount = Label::create();
	fleetCount->setString("4");
	fleetCount->setPosition(560, 462);
	this->addChild(fleetCount);

	auto *shipCountLabel = Sprite::create("PortMain/image 222.png");
	shipCountLabel->setPosition(601, 462);
	this->addChild(shipCountLabel);

	shipCount = Label::create();
	shipCount->setString("48");
	shipCount->setPosition(640, 462);
	this->addChild(shipCount);

	//resources

	Sprite *iconfr = Sprite::create("PortMain/image 161.png");
	iconfr->setPosition(670,462);
	this->addChild(iconfr);

	quickRepairCount = Label::create();
	quickRepairCount->setString("48");
	quickRepairCount->setPosition(710, 462);
	this->addChild(quickRepairCount);

	Sprite *icondt = Sprite::create("PortMain/image 171.png");
	icondt->setPosition(740, 462);
	this->addChild(icondt);

	devToolCount = Label::create();
	devToolCount->setString("48");
	devToolCount->setPosition(780, 462);
	this->addChild(devToolCount);

	int x = 660, y = 441;
	Sprite *icon1 = Sprite::create("PortMain/image 141.png");
	icon1->setPosition(x, y);
	this->addChild(icon1);
	Sprite *icon2 = Sprite::create("PortMain/image 139.png");
	icon2->setPosition(x + 75, y);
	this->addChild(icon2);
	Sprite *icon3 = Sprite::create("PortMain/image 165.png");
	icon3->setPosition(x, y - 19);
	this->addChild(icon3);
	Sprite *icon4 = Sprite::create("PortMain/image 138.png");
	icon4->setPosition(x + 75, y - 19);
	this->addChild(icon4);


	x = x + 40;
	labelFuel = Label::create();
	labelSteel = Label::create();
	labelAmmo = Label::create();
	labelAluminium = Label::create();
	labelFuel->setString("2411");
	labelSteel->setString("2411");
	labelAmmo->setString("2411");
	labelAluminium->setString("2411");
	labelFuel->setAlignment(TextHAlignment::RIGHT);
	labelSteel->setAlignment(TextHAlignment::RIGHT);
	labelAmmo->setAlignment(TextHAlignment::RIGHT);
	labelAluminium->setAlignment(TextHAlignment::RIGHT);
	labelFuel->setColor(Color3B::WHITE);
	labelSteel->setColor(Color3B::WHITE);
	labelAmmo->setColor(Color3B::WHITE);
	labelAluminium->setColor(Color3B::WHITE);
	labelFuel->setPosition(x, y);
	labelSteel->setPosition(x + 75, y);
	labelAmmo->setPosition(x, y - 19);
	labelAluminium->setPosition(x + 75, y - 19);
	this->addChild(labelFuel);
	this->addChild(labelSteel);
	this->addChild(labelAmmo);
	this->addChild(labelAluminium);


	//menu
	

	Layer *layer = Layer::create();
	this->addChild(layer);

	auto recordButton = MenuItemImage::create("PortMain/image 180.png", "PortMain/image 182.png", CC_CALLBACK_1(PortScene::menuHandlingCallback, this));
	recordButton->setPosition(166, 432);

	auto allieButton = MenuItemImage::create("PortMain/image 186.png", "PortMain/image 186.png", CC_CALLBACK_1(PortScene::menuHandlingCallback, this));
	allieButton->setPosition(240, 432);

	auto collectionButton = MenuItemImage::create("PortMain/image 202.png", "PortMain/image 204.png", CC_CALLBACK_1(PortScene::menuHandlingCallback, this));
	collectionButton->setPosition(320, 432);

	auto buyButton = MenuItemImage::create("PortMain/image 207.png", "PortMain/image 209.png", CC_CALLBACK_1(PortScene::menuHandlingCallback, this));
	buyButton->setPosition(400, 432);

	auto furnitureButton = MenuItemImage::create("PortMain/image 212.png", "PortMain/image 214.png", CC_CALLBACK_1(PortScene::changeFurnitureCallback, this));
	furnitureButton->setPosition(480, 432);

	auto missionButton = MenuItemImage::create("PortMain/image 194.png", "PortMain/image 199.png", CC_CALLBACK_1(PortScene::menuHandlingCallback, this));
	missionButton->setPosition(560, 432);

	auto missionShader = Sprite::create("PortMain/image 196.png");
	missionShader->setPosition(missionButton->getPosition());
	layer->addChild(missionShader);
	missionShader->setZOrder(1);
	missionShader->runAction(RepeatForever::create((ActionInterval*)Sequence::create(FadeOut::create(2), FadeIn::create(2), NULL)));
	
	auto buyHouseButton = MenuItemImage::create("PortMain/image 217.png", "PortMain/image 219.png", CC_CALLBACK_1(PortScene::menuHandlingCallback, this));
	buyHouseButton->setPosition(620, 432);

	

	auto menu = Menu::create(recordButton, allieButton, collectionButton, buyButton, furnitureButton, missionButton, buyHouseButton, NULL);
	menu->setPosition(0, 0);
	layer->addChild(menu);


	
	return true;

	
}
void PortScene::updateAssistantGirl()
{
	this->mainlayer->updateGirl();
}
void PortScene::menuSettingCallback(Ref* pSender)
{
	Director::getInstance()->end();
}

void PortScene::menuHandlingCallback(Ref* pSender)
{

}

void PortScene::changeFurnitureCallback(Ref* psSender)
{

}