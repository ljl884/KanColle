#include "BattleBar.h"

BattleBar::BattleBar(Node* parent)
{
	this->parent = parent;
	init();
}
void BattleBar::openAndCloseAnimation(Sprite * border, Sprite*label,float delay)
{
	border->setScaleY(0.2);
	CCFiniteTimeAction *fadeIn = FadeIn::create(0.01);
	CCFiniteTimeAction *scaleUp = ScaleBy::create(0.3, 1, 5, 0);
	CCFiniteTimeAction *scaleDown = ScaleBy::create(0.3, 1, 0.2, 0);
	CCFiniteTimeAction *fadeOut = FadeOut::create(0.2);
	auto action = Sequence::create(DelayTime::create(delay),fadeIn, scaleUp, CCDelayTime::create(0.7), scaleDown, fadeOut, NULL);
	border->runAction(action);

	Point labelPosition = label->getPosition();
	CCFiniteTimeAction *fadeIn2 = FadeIn::create(0.01);
	CCFiniteTimeAction *moveLeft = MoveTo::create(0.6, Point(labelPosition.x - 30, labelPosition.y));
	CCFiniteTimeAction *fadeOut2 = FadeOut::create(0.2);
	auto action2 = Sequence::create(DelayTime::create(delay), fadeIn2,moveLeft, CCDelayTime::create(0.5), fadeOut2, NULL);
	label->runAction(action2);
}
void BattleBar::openAndCloseAnimation(GreenBarPosition position, Sprite*label)
{
	openAndCloseAnimation(position, label, 0);
}
void BattleBar::openAndCloseAnimation(GreenBarPosition position, Sprite*label,float delay){
	bool labelPositionSet = true;
	Point p = label->getPosition();
	if (p.x == 0 && p.y == 0)
		labelPositionSet = false;
	switch (position)
	{
	case topleft:
		if (!labelPositionSet)
			label->setPosition(220, 400);
		parent->addChild(label);
		label->setZOrder(1);
		openAndCloseAnimation(topGreenBar, label,delay);
		break;
	case center:
		if (!labelPositionSet)
			label->setPosition(400, 240);
		parent->addChild(label);
		label->setZOrder(1);
		openAndCloseAnimation(centerGreenBar, label,delay);
		break;
	case bottom:
		if (!labelPositionSet)
			label->setPosition(400, 100);
		parent->addChild(label);
		label->setZOrder(1);
		openAndCloseAnimation(bottomGreenBar, label, delay);
	default:
		break;
	}
}
void BattleBar::openAndCloseAnimation(GreenBarPosition position, GreenBarLableType type)
{
	openAndCloseAnimation(position, type, 0);
}
void BattleBar::openAndCloseAnimation(GreenBarPosition position, GreenBarLableType type,float delay)
{
	Sprite *label = nullptr;
	switch (type)
	{
	case scout_start:
		label = Sprite::create("BattleMain/image 517.png");
		break;
	case scouter_doesnt_back:
		label = Sprite::create("BattleMain/image 516.png");
		break;
	case enemy_scouted:
		label = Sprite::create("BattleMain/image 520.png");
		break;
	case enemy_scouted_scouter_doesnt_back:
		label = Sprite::create("BattleMain/image 518.png");
		break;
	case enemy_not_scouted:
		label = Sprite::create("BattleMain/image 519.png");
		break;
	case enemy_seen:
		label = Sprite::create("BattleMain/image 521.png");
		break;
	default:
		break;
	}
	this->openAndCloseAnimation(position, label,delay);

}
void BattleBar::init()
{
	centerGreenBar = Sprite::create("BattleMain/image 512.png");
	centerGreenBar->setZOrder(1);
	centerGreenBar->setPosition(400, 240);
	centerGreenBar->setOpacity(0);
	parent->addChild(centerGreenBar);

	topGreenBar = Sprite::create("BattleMain/image 512.png");
	topGreenBar->setZOrder(1);
	topGreenBar->setPosition(400, 400);
	topGreenBar->setOpacity(0);
	parent->addChild(topGreenBar);

	bottomGreenBar = Sprite::create("BattleMain/image 512.png");
	bottomGreenBar->setZOrder(1);
	bottomGreenBar->setPosition(400, 100);
	bottomGreenBar->setOpacity(0);
	parent->addChild(bottomGreenBar);

}

void BattleBar::runAction(Action* action, GreenBarPosition position)
{
	switch (position)
	{
	case top:
		topGreenBar->runAction(action);
		break;
	case topleft:
		break;
	case center:
		centerGreenBar->runAction(action);
		break;
	case bottom:
		bottomGreenBar->runAction(action);
		break;
	default:
		break;
	}
}