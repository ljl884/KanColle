#include "SallyScene.h"
#include "GameScene.h"
#include "PortScene.h"
SallyScene::SallyScene(Mission *mission)
{
	this->mission = mission;
	this->currentMissionNode = mission->nodes[0];

	showingBottomPanel = false;
	bgImg = Sprite::create("SallyMain/image 1.jpg");
	bgImg->setPosition(400, 240);
	bgImg->setOpacity(0);
	this->addChild(bgImg);
	sallyMap = Sprite::create("Map/" + mission->id + "/image 1.png");
	this->addChild(sallyMap);
	sallyMap->setPosition(400, 240);
	sallyMap->setOpacity(0);

	ship = Sprite::create("SallyMain/image 1023.png");
	this->addChild(ship);
	ship->setZOrder(1);
	ship->setVisible(false);
	initializeFormationPanel();

	std::string resource = GameModel::getInstance()->getFleet(0)->getShip(0)->resourceFolder;
	
	flagShip = Sprite::create("Character/" + resource + "/image 17.png");
	this->addChild(flagShip);
	flagShip->setPosition(-300, 150);
	flagShip->setZOrder(2);
	
	bottomBorder = Sprite::create("SallyMain/image 935.png");
	bottomBorder->setPosition(400, -250);
	bottomBorder->setZOrder(3);
	this->addChild(bottomBorder);
	bottomCompass = new Compass();
	this->addChild(bottomCompass);
	bottomCompass->setZOrder(3);
	bottomCompass->setPosition(40, -260);
	bottomCompass->setRotation(45);
	bottomLabel=Label::create();
	bottomLabel->setZOrder(3);
	this->addChild(bottomLabel);
	temptimer = Sprite::create("BattleMain/image 478.png");
	this->addChild(temptimer);

	

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
void SallyScene::initializeFormationPanel()
{
	Formation * danzong = new Formation(DanZong, this);
	danzong->setPosition(450, 370);
	danzong->setVisible(false);
	this->addChild(danzong);
	Formation * fuzong = new Formation(FuZong, this);
	fuzong->setPosition(580, 370);
	fuzong->setVisible(false);
	this->addChild(fuzong);
	Formation * lunxing = new Formation(LunXing, this);
	lunxing->setPosition(710, 370);
	lunxing->setVisible(false);
	this->addChild(lunxing);
	Formation * tixing = new Formation(TiXing, this);
	tixing->setPosition(510, 210);
	tixing->setVisible(false);
	this->addChild(tixing);
	Formation * danheng = new Formation(DanHeng, this);
	danheng->setPosition(640, 210);
	danheng->setVisible(false);
	this->addChild(danheng);

	formations.push_back(danzong);
	formations.push_back(fuzong);
	formations.push_back(lunxing);
	formations.push_back(tixing);
	formations.push_back(danheng);



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
		sallyFinish();
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
	nodePointShader = Sprite::create();
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
		nodePoint->setTexture("SallyMain/image 867.png");
		nodePointShader->setTexture("SallyMain/image 867.png");
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
		nextStatus(timepassed);
	}
		
}
void SallyScene::sallyFormation()
{
	flagShip->runAction(MoveTo::create(0.5, ccp(100, 150)));
	
	for (Formation* formation : formations)
	{
		formation->setVisible(true);
	}
}
void SallyScene::sallyBattle()
{
	
	
}
void SallyScene::sallyFinish()
{
	Director::getInstance()->replaceScene(PortScene::createScene());
}
void SallyScene::hideBottomPanel()
{
	if (!showingBottomPanel)
		return;
	bottomBorder->runAction(MoveBy::create(1, ccp(0, -300)));
	bottomCompass->runAction(MoveBy::create(1, ccp(0, -300)));
	bottomLabel->runAction(MoveBy::create(1, ccp(0, -300)));
	showingBottomPanel = false;
}
void SallyScene::showBottomPanel()
{
	if (showingBottomPanel)
		return;
	bottomBorder->runAction(MoveBy::create(1, ccp(0, 300)));
	bottomCompass->runAction(MoveBy::create(1, ccp(0, 300)));
	bottomLabel->runAction(MoveBy::create(1, ccp(0, 300)));
	showingBottomPanel = true;
}
void SallyScene::setFormationCallback(Ref* pSender, FormationType formation)
{
	
	flagShip->runAction(MoveBy::create(0.5, ccp(-400, 0)));
	this->status = sally_start;
	nodePointShader->removeFromParent();
	for (Formation* formation : formations)
	{
		formation->setVisible(false);
	}
	nextStatus(1);
	Fleet* allies = GameModel::getInstance()->getFleet(0);
	Fleet* enemy = currentMissionNode->enemyFleet;
	auto scene = new GameScene(new BattleModel(allies, enemy, formation, DanZong));

	Director::getInstance()->pushScene(scene);
}