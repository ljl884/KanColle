#include "CharacterDetailPage.h"
#include "PortRemodeLayer.h"
#include "Helper.h"


CharacterDetailPage::CharacterDetailPage()
{
	initPage();

	Hidden = true;

	
	
}

CharacterDetailPage::CharacterDetailPage(PortRemodeLayer* parent)
{

	initPage();

	auto upgradeButton = MenuItemImage::create("commonAssets/image 152.png", "commonAssets/image 154.png", CC_CALLBACK_1(CharacterDetailPage::upgradeButtonCallback, this));
	upgradeButton->setPosition(730, 50);
	auto powerUpButton = MenuItemImage::create("commonAssets/image 161.png", "commonAssets/image 163.png", CC_CALLBACK_1(CharacterDetailPage::powerUpButtonCallback, this));
	powerUpButton->setPosition(610, 50);

	auto menu = Menu::create(upgradeButton, powerUpButton, NULL);
	this->addChild(menu);
	menu->setPosition(0, 0);

	parent->addChild(this);

}
void CharacterDetailPage::initPage()
{
	

	auto bgimg = Sprite::create("RemodelMain/image 169.png");
	this->addChild(bgimg);
	bgimg->setOpacity(250);
	bgimg->setPosition(620, 200);

	auto paramBoard = Sprite::create("commonAssets/image 269.png");
	this->addChild(paramBoard);
	paramBoard->setPosition(450, 90);

	characterImage = Sprite::create();
	this->addChild(characterImage);
	characterImage->setPosition(670, 230);

	auto levelmark = Sprite::create("commonAssets/image 111.png");
	this->addChild(levelmark);
	levelmark->setPosition(485, 370);

	hpBar = new HpBar(1, 1);
	this->addChild(hpBar);
	hpBar->setPosition(370, 340);

	//equipment
	equipmentContainer1 = new EquipmentContainer();
	equipmentContainer2 = new EquipmentContainer();
	equipmentContainer3 = new EquipmentContainer();
	equipmentContainer4 = new EquipmentContainer();
	equipmentContainer1->setPosition(450, 310);
	equipmentContainer2->setPosition(450, 275);
	equipmentContainer3->setPosition(450, 240);
	equipmentContainer4->setPosition(450, 205);
	this->addChild(equipmentContainer1);
	this->addChild(equipmentContainer2);
	this->addChild(equipmentContainer3);
	this->addChild(equipmentContainer4);

	//ability
	Color3B fcolor = Color3B(54, 36, 11);
	name = Label::create("", "fonts/DengXian.ttf", 20);
	name->setColor(fcolor);
	name->setPosition(365, 370);
	level = Label::create("", "fonts/DengXian.ttf", 18);
	level->setColor(fcolor);
	level->setPosition(520, 370);
	HP = Label::create("", "fonts/DengXian.ttf", 10);
	HP->setColor(fcolor);
	HP->setPosition(430, 340);
	maxHP = Label::create("", "fonts/DengXian.ttf", 15);
	maxHP->setColor(fcolor);
	maxHP->setPosition(432, 146);
	firePower = Label::create("", "fonts/DengXian.ttf", 15);
	firePower->setColor(fcolor);
	firePower->setPosition(528, 146);
	armour = Label::create("", "fonts/DengXian.ttf", 15);
	armour->setColor(fcolor);
	armour->setPosition(432, 123);
	torpedo = Label::create("", "fonts/DengXian.ttf", 15);
	torpedo->setColor(fcolor);
	torpedo->setPosition(528, 123);
	agility = Label::create("", "fonts/DengXian.ttf", 15);
	agility->setColor(fcolor);
	agility->setPosition(432, 100);
	antiaircraft = Label::create("", "fonts/DengXian.ttf", 15);
	antiaircraft->setColor(fcolor);
	antiaircraft->setPosition(528, 100);
	capacity = Label::create("", "fonts/DengXian.ttf", 15);
	capacity->setColor(fcolor);
	capacity->setPosition(432, 77);
	antisubmarine = Label::create("", "fonts/DengXian.ttf", 15);
	antisubmarine->setColor(fcolor);
	antisubmarine->setPosition(528, 77);
	scout = Label::create("", "fonts/DengXian.ttf", 15);
	scout->setColor(fcolor);
	scout->setPosition(528, 54);
	luck = Label::create("", "fonts/DengXian.ttf", 15);
	luck->setColor(fcolor);
	luck->setPosition(528, 31);

	speed = Sprite::create();
	speed->setPosition(430, 57);
	range = Sprite::create();
	range->setPosition(430, 33);

	addChild(name);
	addChild(level);
	addChild(HP);
	addChild(maxHP);
	addChild(firePower);
	addChild(antiaircraft);
	addChild(torpedo);
	addChild(armour);
	addChild(agility);
	addChild(capacity);
	addChild(antisubmarine);
	addChild(scout);
	addChild(luck);
	addChild(speed);
	addChild(range);

	stars = new Stars();
	stars->setPosition(470, 340);
	addChild(stars);
}
void CharacterDetailPage::setCharacter(CharacterInfo* info)
{
	if (info->brokenType == BrokenType::normal || info->brokenType == BrokenType::tiny)
		characterImage->setTexture("Character/" + info->resourceFolder + "/image 5.jpg");
	else
		characterImage->setTexture("Character/" + info->resourceFolder + "/image 7.jpg");

	firePower->setString(Helper::int2str(info->firePower));
	torpedo->setString(Helper::int2str(info->torpedo));
	antiaircraft->setString(Helper::int2str(info->antiaircraft));
	armour->setString(Helper::int2str(info->armour));
	name->setString(info->nameCH);
	level->setString(Helper::int2str(info->level));
	HP->setString(Helper::int2str(info->currentHP) + "/" + Helper::int2str(info->maxHP));
	maxHP->setString(Helper::int2str(info->maxHP));
	agility->setString(Helper::int2str(info->agility));
	capacity->setString(Helper::int2str(info->capacity));
	antisubmarine->setString(Helper::int2str(info->antisubmarine));
	scout->setString(Helper::int2str(info->scout));
	luck->setString(Helper::int2str(info->luck));

	hpBar->setHp(info->maxHP, info->currentHP);

	if (info->speed == high)
		speed->setTexture("commonAssets/image 283.png");
	else
		speed->setTexture("commonAssets/image 281.png");

	if (info->range == Shooting_Range::range_exlong)
		range->setTexture("commonAssets/image 294.png");
	else if (info->range == Shooting_Range::range_long)
		range->setTexture("commonAssets/image 292.png");
	else if (info->range == Shooting_Range::range_mid)
		range->setTexture("commonAssets/image 290.png");
	else if (info->range == Shooting_Range::range_short)
		range->setTexture("commonAssets/image 288.png");
	else if (info->range == Shooting_Range::range_non)
		range->setTexture("commonAssets/image 286.png");
	

	if (name->getContentSize().width>80)
		name->setScaleX(0.8);
	else name->setScaleX(1);

	stars->setNumber(info->star);

	equipmentContainer1->updateEquipment(info->equipments[0]);
	equipmentContainer2->updateEquipment(info->equipments[1]);
	equipmentContainer3->updateEquipment(info->equipments[2]);
	equipmentContainer4->updateEquipment(info->equipments[3]);
}
void CharacterDetailPage::moveOut()
{
	if (!Hidden)
	{
		this->runAction(MoveBy::create(0.2, ccp(800, 0)));
		Hidden = true;
	}
	
}
void CharacterDetailPage::moveIn()
{
	if (Hidden)
	{
		this->runAction(MoveBy::create(0.2, ccp(-800, 0)));
		Hidden = false;
	}
}
void CharacterDetailPage::upgradeButtonCallback(Ref* pSender)
{

}
void CharacterDetailPage::powerUpButtonCallback(Ref* pSender)
{
}