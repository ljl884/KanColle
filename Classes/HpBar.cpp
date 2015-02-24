#include "HpBar.h"

HpBar::HpBar(int maxHp, int currentHp)
{
	auto bgBar = Sprite::create("commonAssets/image 169.png");
	this->addChild(bgBar);
	bar = Sprite::create("commonAssets/hpBar.png");
	bar->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	this->addChild(bar);
	bar->setPosition(-30, 0);
	setHp(maxHp, currentHp);

}

void HpBar::setCurrentHp(int currentHp)
{
	this->currentHp = currentHp;
	float persentage = (float)currentHp / (float)maxHp;
	bar->setScaleX(persentage);
	if (persentage > 0.75)
		bar->setColor(Color3B::GREEN);
	else if (persentage >0.5)
		bar->setColor(Color3B::ORANGE);
	else if (persentage >0.25)
		bar->setColor(Color3B::YELLOW);
	else 
		bar->setColor(Color3B::RED);

}
void HpBar::setHp(int maxHp, int currentHp)
{
	this->maxHp = maxHp;
	setCurrentHp(currentHp);
}