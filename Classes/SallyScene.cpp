#include "SallyScene.h"
#include "GameScene.h"

SallyScene::SallyScene(Mission *mission)
{
	this->mission = mission;
	this->currentMissionNode = mission->nodes[0];

	bgImg = Sprite::create("SallyMain/image 1.jpg");
	bgImg->setPosition(400, 240);
	bgImg->setOpacity(0);
	this->addChild(bgImg);
	sallyMap = Sprite::create("Map/" + mission->id + "/image 1.png");
	this->addChild(sallyMap);
	sallyMap->setPosition(400, 240);
	sallyMap->setOpacity(0);
	bottomBorder = Sprite::create("SallyMain/image 935.png");
	bottomBorder->setPosition(400, -250);
	this->addChild(bottomBorder);
	bottomCompass = new Compass();
	this->addChild(bottomCompass);
	bottomCompass->setPosition(40, -260);
	bottomCompass->setRotation(45);
	bottomLabel=Label::create();
	this->addChild(bottomLabel);
	temptimer = Sprite::create("BattleMain/image 478.png");
	this->addChild(temptimer);

	ship = Sprite::create("SallyMain/image 1023.png");
	this->addChild(ship);
	ship->setZOrder(1);
	ship->setVisible(false);

	status = sally_start;
	sallyStart();
}
void SallyScene::onStatusOverCallBack()
{
	if (status == SallyStatus::sally_start)
	{
		status = sally_move;
		sallyMove();
	}
	else if (status == SallyStatus::sally_battle)
	{
		sallyBattle();
	}
	else if (status == SallyStatus::sally_formation)
	{
		sallyFormation();
	}
}
void SallyScene::nextStatus(float DelayTime)
{
	auto callFunc = CallFunc::create(CC_CALLBACK_0(SallyScene::onStatusOverCallBack, this));
	auto *seq = Sequence::create(DelayTime::create(DelayTime), callFunc, NULL);
	temptimer->runAction(seq);
}
void SallyScene::sallyStart()
{
	
	auto slide = Sprite::create("SallyMain/image 611.png");
	auto start = Sprite::create("SallyMain/image 614.png");
	auto startShader = Sprite::create("SallyMain/image 614.png");
	slide->setPosition(1200, 240);
	start->setPosition(400, 240);
	start->setOpacity(0);
	startShader->setOpacity(0);
	startShader->setScale(1.15);
	startShader->setPosition(400, 240);
	this->addChild(slide);
	this->addChild(start);
	this->addChild(startShader);

	

	//animation
	slide->runAction(Sequence::create(MoveTo::create(0.3, ccp(400, 240)), DelayTime::create(1.3), FadeOut::create(0.3),NULL));
	start->runAction(Sequence::create(DelayTime::create(0.3), FadeIn::create(0.3),DelayTime::create(1),FadeOut::create(0.3), NULL));
	startShader->runAction(Sequence::create(DelayTime::create(0.3), FadeIn::create(0.3), ScaleTo::create(0.1, 1), DelayTime::create(1), FadeOut::create(0.3), NULL));
	bgImg->runAction(Sequence::create(DelayTime::create(1.6), FadeIn::create(0.3),NULL));
	sallyMap->runAction(Sequence::create(DelayTime::create(1.6), FadeIn::create(0.3), NULL));

	nextStatus(1.9);
}

void SallyScene::sallyMove()
{
	showBottomPanel();
	bool needRollCompass=false;
	float timepassed = 0;
	ship->setVisible(true);
	ship->setPosition(currentMissionNode->position);

	MissionNode* nextNode;
	if (currentMissionNode->children.size() == 0)
	{
		//sally end
		return;
	}
	else if (currentMissionNode->children.size() == 1)
	{
		nextNode = currentMissionNode->children[0];
	}
	else //currentMissionNode->children.size() > 1
	{
		needRollCompass = true;
		nextNode = currentMissionNode->children[1];
	}
	timepassed += 2;
	ship->runAction(Sequence::create(DelayTime::create(timepassed),MoveTo::create(1, nextNode->position),NULL));
	timepassed += 1;
	//point animation
	auto nodePoint = Sprite::create();
	nodePoint->setPosition(nextNode->position);
	nodePoint->setOpacity(0);
	nodePoint->runAction(Sequence::create(DelayTime::create(timepassed),FadeIn::create(0.5),NULL));
	
	this->addChild(nodePoint);
	auto nodePointShader = Sprite::create();
	nodePointShader->setPosition(nextNode->position);
	nodePointShader->setOpacity(0);
	nodePointShader->runAction(Sequence::create(DelayTime::create(timepassed), FadeIn::create(0.5), NULL));
	nodePointShader->runAction(RepeatForever::create((ActionInterval*)Sequence::create(ScaleTo::create(1.2, 2), ScaleTo::create(0.01, 1), ScaleTo::create(1.2, 2), ScaleTo::create(0.01, 1)
		, NULL)));
	timepassed += 2.4;
	this->addChild(nodePointShader);
	switch (nextNode->type)
	{
	case node_boss:
		nodePoint->setTexture("SallyMain/image 876.png");
		break;
	case node_enemy:
		nodePoint->setTexture("SallyMain/image 861.png");
		nodePointShader->setTexture("RemodelMain/image 1.png");
		break;
	case node_item:
		nodePoint->setTexture("SallyMain/image 857.png");
		break;
	case node_empty:
		nodePoint->setTexture("SallyMain/image 855.png");
		break;
	case node_disaster:
		nodePoint->setTexture("SallyMain/image 859.png");
		break;
	default:
		break;
	}
	if (nextNode->type == node_boss || nextNode->type == node_enemy)
	{
		this->status = sally_formation;
		currentMissionNode = nextNode;
		nextStatus(timepassed+1);
	}
		
}
void SallyScene::sallyFormation()
{

}
void SallyScene::sallyBattle()
{
	
	
}
void SallyScene::hideBottomPanel()
{
	bottomBorder->runAction(MoveBy::create(1, ccp(0, -300)));
	bottomCompass->runAction(MoveBy::create(1, ccp(0, -300)));
	bottomLabel->runAction(MoveBy::create(1, ccp(0, -300)));
}
void SallyScene::showBottomPanel()
{
	
	bottomBorder->runAction(MoveBy::create(1, ccp(0, 300)));
	bottomCompass->runAction(MoveBy::create(1, ccp(0, 300)));
	bottomLabel->runAction(MoveBy::create(1, ccp(0, 300)));
}
void SallyScene::setFormationCallback(Ref* pSender, FormationType formation)
{
	Fleet* allies = GameModel::getInstance()->getFleet(0);
	Fleet* enemy = currentMissionNode->enemyFleet;
	auto scene = new GameScene(new BattleModel(allies, enemy, formation, DanZong));

	Director::getInstance()->pushScene(scene);
}