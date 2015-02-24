#include "BattleEnemy.h"

BattleEnemy* BattleEnemy::create(std::string name, Node *parent, int row)
{
	BattleEnemy *hero = new BattleEnemy();
	hero->setInfo(CharacterInfo::makeDefaultInfo());
	if (hero && hero->init(name, parent, row)){
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}
BattleEnemy* BattleEnemy::create(CharacterInfo *info, Node *parent, int row)
{
	BattleEnemy *hero = new BattleEnemy();
	hero->setInfo(info);
	if (hero && hero->init(info->resourceFolder, parent, row)){
		hero->autorelease();
		return hero;
	}
	CC_SAFE_DELETE(hero);
	return nullptr;
}
bool BattleEnemy::init(std::string name, Node *parent, int row){
	parent->addChild(this);
	this->parent = parent;
	this->resourceFolder = name;
	card = new CharacterCard(true, name);
	this->addChild(card);
	hpBar->setPosition(635, 341 - 41 * row);
	this->addChild(hpBar);
	if (row == 1)
	{
		border = Sprite::create("BattleMain/image 446.png");
		flagIcon = Sprite::create("BattleMain/image 88.png");
		flagIcon->setPosition(788, 367 - 41);
		this->addChild(flagIcon);
	}
	else
		border = Sprite::create("BattleMain/image 444.png");
	border->setPosition(714, 363 - 41 * row);
	this->addChild(border);
	card->setPosition(718, 360 - 41 * row);
	

	currentHpLabel->setPosition(602, 360 - 41 * row);
	currentHpLabel->setAlignment(TextHAlignment::RIGHT);
	maxHpLabel->setPosition(618, 360 - 41 * row);
	this->addChild(currentHpLabel);
	this->addChild(maxHpLabel);

	battleBar = new BattleBar(parent);

	return true;
}
float BattleEnemy::showAttackingAnime(float delay){
	if (closeUp == nullptr)
	{
		closeUp = Sprite::create("Enemy/" + resourceFolder + "/image 3.png");
		parent->addChild(closeUp);
		closeUp->setZOrder(3);
		//closeUp->setScale(0.8);
	}
	closeUp->setPosition(1200, 0);
	AnimationMaker::FlyToPositionAndFadeOut(closeUp, delay,ccp(700,240),0.5);
	updateInformationBoard();
	informationBoard->runAction(Sequence::create(DelayTime::create(delay), FadeIn::create(0.05), DelayTime::create(0.5), FadeOut::create(0.3), NULL));
	return 0;
}
void BattleEnemy::apearAnimation()
{
	Color3B col = card->getColor();
	FiniteTimeAction *tinto = TintTo::create(1.5, Color3B(242,75,75));
	FiniteTimeAction *tinback = TintTo::create(1.2, col);
	Sequence *seq = Sequence::create(tinto, tinback, NULL);
	card->runAction(seq);

	FiniteTimeAction *fadeIn = FadeIn::create(1);
	border->setOpacity(0);
	border->runAction(fadeIn);

	FiniteTimeAction *fadeIn2 = FadeIn::create(0.6);
	hpBar->setOpacity(0);
	hpBar->runAction(fadeIn2);

	maxHpLabel->setCascadeOpacityEnabled(true);
	currentHpLabel->setCascadeOpacityEnabled(true);

	FiniteTimeAction *fadeIn3 = FadeIn::create(0.3);
	maxHpLabel->setOpacity(0);
	maxHpLabel->runAction(fadeIn3);

	FiniteTimeAction *fadeIn4 = FadeIn::create(0.3);
	currentHpLabel->setOpacity(0);
	currentHpLabel->runAction(fadeIn4);

}
void BattleEnemy::showCloseUp()
{

}

void BattleEnemy::stepOut(float delay){
	FiniteTimeAction *out = MoveBy::create(0.3, Point(-40, 0));
	this->runAction(Sequence::create(DelayTime::create(delay), out, NULL));
}
void BattleEnemy::stepBack(float delay){
	FiniteTimeAction *back = MoveBy::create(0.3, Point(40, 0));
	this->runAction(Sequence::create(DelayTime::create(delay), back, NULL));
}

void BattleEnemy::updateInformationBoard()
{
	if (informationBoard == nullptr)
	{
		informationBoard = Sprite::create("BattleMain/image 530.png");
		parent->addChild(informationBoard);
		informationBoard->setPosition(600, 70);
		informationBoard->setZOrder(4);

	}
	informationBoard->setOpacity(0);
}


void BattleEnemy::ThreeDigitMode(){
	currentHpLabel->runAction(MoveBy::create(0.01, ccp(-10, 0)));
	maxHpLabel->runAction(MoveBy::create(0.01, ccp(-3, 0)));
}

void BattleEnemy::setCurrentHp(int hp)
{
	currentHp = hp;
	currentHpLabel->setString(CCString::createWithFormat("%d", currentHp)->_string );
	float persentage = 0;
	if (maxHp != 0)
		persentage = (float)hp / (float)maxHp;

	hpBar->setScaleY(persentage);


	if (persentage>0.75)
	{
		hpBar->setColor(Color3B::GREEN);
	}
	else if (persentage>0.50) //Ð¡ÆÆ
	{
		hpBar->setColor(Color3B::YELLOW);
		setBroken(tiny);
	}
	else if (persentage>0.25)//ÖÐÆÆ
	{
		hpBar->setColor(Color3B::ORANGE);
		setBroken(BrokenType::mid);
	}
	else if (persentage>0)//´óÆÆ
	{
		hpBar->setColor(Color3B::RED);
		setBroken(large);
	}
	else
	{
		setBroken(drown);
	}
}
void BattleEnemy::setMaxHp(int hp)
{
	if (hp > 99)
		ThreeDigitMode();
	this->maxHp = hp;
	this->maxHpLabel->setString("/"+CCString::createWithFormat("%d", maxHp)->_string);
	this->setCurrentHp(hp);
}