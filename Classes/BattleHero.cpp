#include "BattleHero.h"




std::string int2str(int &i) {
	std::string s;
	std::stringstream ss(s);
	ss << i;

	return ss.str();
}
BattleHero* BattleHero::create(CharacterInfo *info, Node *parent, int row)
{
	BattleHero *hero = new BattleHero();
	hero->setInfo(info);
	if (hero && hero->init(info->resourceFolder, parent, row)){
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}
BattleHero* BattleHero::create(std::string name, Node *parent, int row)
{
	BattleHero *hero = new BattleHero();
	hero->setInfo(CharacterInfo::makeDefaultInfo());
	if (hero && hero->init( name,parent, row)){
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}
bool BattleHero::init(std::string name, Node *parent, int row){
	this->parent = parent;
	parent->addChild(this);
	this->resourceFolder = name;
	card = new CharacterCard(name);

	this->addChild(card);
	hpBar->setPosition(163, 391 - 41 * row);
	this->addChild(hpBar);
	if (row == 1)
	{
		border = Sprite::create("BattleMain/image 442.png");
		flagIcon = Sprite::create("BattleMain/image 88.png");
		flagIcon->setPosition(148, 417 - 41);
		this->addChild(flagIcon);
	}
	
	else
		border = Sprite::create("BattleMain/image 437.png");
	border->setPosition(84, 413 - 41 * row);
	this->addChild(border);
	card->setPosition(80, 410 - 41 * row);

	currentHpLabel->setPosition(180, 410 - 41 *row);
	maxHpLabel->setPosition(197, 410 - 41 * row);
	this->addChild(currentHpLabel);
	this->addChild(maxHpLabel);
	
	battleBar = new BattleBar(parent);

	//default
	this->setMaxHp(50);
	
	
	return true;
}
float BattleHero::showCloseUp(float delay)
{
	if (closeUp == nullptr)
	{
		closeUp = Sprite::create("Character/" + resourceFolder + "/image 9.png");
		parent->addChild(closeUp);
		closeUp->setZOrder(3);
		closeUp->setScale(0.8);
		
	}	
	closeUp->setPosition(1200, -240);
	return AnimationMaker::FlyToCenterLeftAndFadeOut(closeUp,delay);

	//this->setZOrder(0);
}
float BattleHero::showAttackingAnime(float delay){
	if (closeUp == nullptr)
	{
		closeUp = Sprite::create("Character/" + resourceFolder + "/image 9.png");
		parent->addChild(closeUp);
		closeUp->setZOrder(3);
		//closeUp->setScale(0.8);
	}
	closeUp->setPosition(-400, -0);
	AnimationMaker::FlyToPositionAndFadeOut(closeUp, delay,ccp(100,240),0.5);
	updateInformationBoard();

	if (equipmentLabel != nullptr)
		delete equipmentLabel;
	equipmentLabel = Sprite::create("btxt_flat/063.png");
	equipmentLabel->setPosition(650, 100);
	equipmentLabel->setOpacity(0);

	battleBar->openAndCloseAnimation(bottom, equipmentLabel, delay);
	informationBoard->runAction(Sequence::create(DelayTime::create(delay),FadeIn::create(0.05), DelayTime::create(0.5), FadeOut::create(0.3),NULL));
	return 0;
}
void BattleHero::stepOut(float delay){
	FiniteTimeAction *out = MoveBy::create(0.2, Point(40, 0));
	this->runAction(Sequence::create(DelayTime::create(delay), out, NULL));
}
void BattleHero::stepBack(float delay){
	FiniteTimeAction *back = MoveBy::create(0.2, Point(-40, 0));
	this->runAction(Sequence::create(DelayTime::create(delay),back,NULL));
}
void BattleHero::updateInformationBoard()
{
	if (informationBoard == nullptr)
	{
		informationBoard = Sprite::create("BattleMain/image 530.png");
		parent->addChild(informationBoard);
		informationBoard->setPosition(200, 70);
		informationBoard->setZOrder(4);


		firePowerLabel = Label::create("","fonts/STXINWEI.ttf",20);
		torpedoLabel = Label::create("", "fonts/STXINWEI.ttf", 20);
		antiaircraftLabel = Label::create("", "fonts/STXINWEI.ttf", 20);
		armourLabel = Label::create("", "fonts/STXINWEI.ttf", 20);
		nameLabel = Label::create("", "fonts/STXINWEI.ttf", 35);
		levelLabel = Label::create("", "fonts/STXINWEI.ttf", 25);


		
		firePowerLabel->setPosition(80, 17);
		torpedoLabel->setPosition(160, 17);
		antiaircraftLabel->setPosition(240, 17);
		armourLabel->setPosition(320, 17);
		nameLabel->setPosition(45, 80);
		levelLabel->setPosition(60, 40);

		informationBoard->setCascadeOpacityEnabled(true);

		informationBoard->addChild(firePowerLabel);
		informationBoard->addChild(torpedoLabel);
		informationBoard->addChild(antiaircraftLabel);
		informationBoard->addChild(armourLabel);
		informationBoard->addChild(nameLabel);
		informationBoard->addChild(levelLabel);
	}
	firePowerLabel->setString(int2str(info->firePower));
	
	torpedoLabel->setString(int2str(info->torpedo));
	
	antiaircraftLabel->setString(int2str(info->antiaircraft));
	
	armourLabel->setString(int2str(info->armour));
	
	nameLabel->setString(info->nameCH);
	levelLabel->setString(int2str(info->level));
	

	

	informationBoard->setOpacity(0);
}


