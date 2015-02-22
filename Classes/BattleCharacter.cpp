#include "BattleCharacter.h"
#include "AnimationMaker.h"

BattleCharacter::BattleCharacter()
{
	mainSprite = nullptr;
	border = nullptr;
	flagIcon = nullptr;
	closeUp = nullptr;
	brokenMark = nullptr;
	shader = nullptr;
	informationBoard = nullptr;
	equipmentLabel = nullptr;
	
	




	hpBar = Sprite::create("BattleMain/image 430.png");
	maxHpLabel = Label::create();
	currentHpLabel = Label::create();
	maxHpLabel->setColor(Color3B::WHITE);
	currentHpLabel->setColor(Color3B::WHITE);
}

void BattleCharacter::setCurrentHp(int hp)
{
	currentHp = hp;
	currentHpLabel->setString(CCString::createWithFormat("%d", currentHp)->_string+"/");
	float persentage = 0;
	if (maxHp!=0)
	 persentage = (float)hp / (float)maxHp;

	hpBar->setScaleY(persentage);
	if (persentage > 0 && persentage < 1)
	{
		float distance = 0.5 * 40 * (1 - persentage);
		hpBar->runAction(MoveBy::create(0.01, ccp(0, -distance)));
	}
	

	if (persentage>0.75)
	{
		hpBar->setColor(Color3B::GREEN);
	}
	else if (persentage>0.50) //Ð¡ÆÆ
	{
		hpBar->setColor(Color3B::YELLOW);
		setBroken(BrokenType::tiny);
	}
	else if (persentage>0.25)//ÖÐÆÆ
	{
		hpBar->setColor(Color3B::ORANGE);
		setBroken(BrokenType::mid);
	}
	else if (persentage>0)//´óÆÆ
	{
		hpBar->setColor(Color3B::RED);
		setBroken(BrokenType::large);
	}
	else
	{
		setBroken(drown);
	}
}
void BattleCharacter::setMaxHp(int hp)
{
	if (hp > 99)
		ThreeDigitMode();
	this->maxHp = hp;
	this->maxHpLabel->setString(CCString::createWithFormat("%d", maxHp)->_string);
	this->setCurrentHp(hp);
}
void BattleCharacter::getDamage(int damage)
{
	int newHp = this->currentHp;
	if (damage > 0)
	{
		newHp = this->currentHp - damage;
		if (newHp <= 0)
		newHp = 0;
	}
	setCurrentHp(newHp);
}
void BattleCharacter::showAttackedAnime(float delay){
	AnimationMaker::playShakingAnimation(this, delay);
}

bool BattleCharacter::canAttack()
{
	if (info->type == CV || info->type == CVL)
	{
		float persentage = currentHp / maxHp;
		if (persentage <= 0.5)
			return false;
	}
	
	
	if (currentHp == 0)
			return false;
	
	return true;
}

Point BattleCharacter::getRealPosition()
{
	return this->mainSprite->getPosition();
}
void BattleCharacter::showDamageAnime(float delay, bool miss, bool critical, int damage)
{
	auto callFunc = CallFunc::create(CC_CALLBACK_0(BattleCharacter::getDamage, this,damage));
	AnimationMaker::playDamageNumberAnimation(this->getRealPosition(),this->parent, delay, miss, critical, damage,callFunc);
}
void BattleCharacter::setBroken(BrokenType type)
{
	info->brokenType = type;
	Point p = mainSprite->getPosition();

	if (brokenMark!=nullptr)
		delete brokenMark;
	switch (type)
	{
	case BrokenType::tiny:
		brokenMark = Sprite::create("commonAssets/image 344.png");
		this->addChild(brokenMark);
		brokenMark->setPosition(p);
		break;
	case BrokenType::mid:
		brokenMark = Sprite::create("commonAssets/image 346.png");
		this->addChild(brokenMark);
		brokenMark->setPosition(p);
		break;
	case BrokenType::large:
		brokenMark = Sprite::create("commonAssets/image 348.png");
		this->addChild(brokenMark);
		brokenMark->setPosition(p);
		break;
	case BrokenType::drown:
		brokenMark = Sprite::create("commonAssets/image 350.png");
		mainSprite->setColor(Color3B(90, 90, 96));//GRAY
		this->addChild(brokenMark);
		brokenMark->setPosition(p);
		break;
	default:
		break;
	}
}
float BattleCharacter::receiveDamage(float delay, bool miss, bool critical, int damage,int explodeTimes)
{
	float time = AnimationMaker::playExplodeAnimation(this->parent, delay, this->getRealPosition(), explodeTimes);
	this->showAttackedAnime(delay);
	this->showDamageAnime(delay + 0.1, miss, critical, damage);
	return time;
}

std::string BattleCharacter::int2str(int &i) {
	std::string s;
	std::stringstream ss(s);
	ss << i;

	return ss.str();
}