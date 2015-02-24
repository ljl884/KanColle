#include "OrganizeContainer.h"
#include "PortOrganizeLayer.h"
#include "Helper.h"


OrganizeContainer::OrganizeContainer(PortOrganizeLayer * parent, int index)
{
	

	if (index<0 || index>NUMBER_OF_CONTAINERS)
		return;
	this->parent = parent;
	this->Index = index;
	bg = Sprite::create("OrganizeMain/image 221.png");
	this->addChild(bg);
	parent->addChild(this);

	//index icon
	if (index == 0)
		IndexIcon = Sprite::create("OrganizeMain/image 195.png");
	else if (index ==1)
		IndexIcon = Sprite::create("OrganizeMain/image 197.png");
	else if (index == 2)
		IndexIcon = Sprite::create("OrganizeMain/image 199.png");
	else if (index == 3)
		IndexIcon = Sprite::create("OrganizeMain/image 201.png");
	else if (index == 4)
		IndexIcon = Sprite::create("OrganizeMain/image 203.png");
	else if (index == 5)
		IndexIcon = Sprite::create("OrganizeMain/image 205.png");
	this->addChild(IndexIcon);
	IndexIcon->setPosition(-160, 41);

	//exp
	auto expBar = Sprite::create("OrganizeMain/image 247.png");
	expBar->setPosition(78, -8);
	this->addChild(expBar);

	//hp
	hpBar = new HpBar(1, 1);
	hpBar->setPosition(-45, 13);
	this->addChild(hpBar);

	//menu

	

	detailButton = MenuItemImage::create("OrganizeMain/image 208.png", "OrganizeMain/image 210.png", CC_CALLBACK_1(OrganizeContainer::detailCallback, this));
	detailButton->setPosition(35, -30);
	changeButton = MenuItemImage::create("OrganizeMain/image 214.png", "OrganizeMain/image 216.png", CC_CALLBACK_1(OrganizeContainer::changeCallback, this));
	changeButton->setPosition(118, -30);
	auto menu = Menu::create(detailButton, changeButton, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu);

	//context
	/*characterImage = Sprite::create();
	characterImage->setPosition(78, 20);
	addChild(this->characterImage);*/
	card = new CharacterCard();
	card->setPosition(78, 20);
	addChild(card);

	name = Label::create("", "fonts/DengXian.ttf", 25);
	name->setPosition(-120, 22);
	level = Label::create("", "fonts/DengXian.ttf", 18);
	level->setPosition(-23, 30);
	HP = Label::create("", "fonts/DengXian.ttf", 10);
	HP->setPosition(-25, 0);
	firePower = Label::create("", "fonts/DengXian.ttf", 15);
	firePower->setPosition(-95, -15);
	antiaircraft = Label::create("", "fonts/DengXian.ttf", 15);
	antiaircraft->setPosition(-20, -15);
	torpedo = Label::create("", "fonts/DengXian.ttf", 15);
	torpedo->setPosition(-95, -35);
	armour = Label::create("", "fonts/DengXian.ttf", 15);
	armour->setPosition(-20, -35);
	addChild(name);
	addChild(level);
	addChild(HP);
	addChild(firePower);
	addChild(antiaircraft);
	addChild(torpedo);
	addChild(armour);
	stars = new Stars();
	stars->setPosition(-145, 5);
	addChild(stars);


}
void OrganizeContainer::updateCharacterInfo(CharacterInfo* info)
{
	
	/*if (info->brokenType == BrokenType::normal || info->brokenType == BrokenType::tiny)
	{
		characterImage->setTexture("Character/" + info->resourceFolder + "/image 1.png");
		if (Sprite::create("Character/" + info->resourceFolder + "/image 1.png") == nullptr)
			characterImage->setTexture("Character/" + info->resourceFolder + "/image 1.jpg");
	}
		
	else
	{
		characterImage->setTexture("Character/" + info->resourceFolder + "/image 3.png");
		if (Sprite::create("Character/" + info->resourceFolder + "/image 3.png") == nullptr)
			characterImage->setTexture("Character/" + info->resourceFolder + "/image 3.jpg");
	}*/
	card->updateCharacter(info->resourceFolder, info->brokenType);
	

	firePower->setString(Helper::int2str(info->firePower));
	torpedo->setString(Helper::int2str(info->torpedo));
	antiaircraft->setString(Helper::int2str(info->antiaircraft));
	armour->setString(Helper::int2str(info->armour));
	name->setString(info->nameCH);
	level->setString(Helper::int2str(info->level));
	HP->setString(Helper::int2str(info->currentHP) + "/" + Helper::int2str(info->maxHP));
	hpBar->setHp(info->maxHP, info->currentHP);
	if (name->getContentSize().width>80)
		name->setScaleX(0.8);
	else name->setScaleX(1);

	stars->setNumber(info->star);
	
}
void OrganizeContainer::detailCallback(Ref* pSender)
{
	parent->setSelectedShipIndex(Index);
	parent->showDetail(Index);
}
void OrganizeContainer::changeCallback(Ref* pSender)
{
	parent->setSelectedShipIndex(Index);
	parent->showList(Index);
}