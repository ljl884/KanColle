#include "GameScene.h"
#include "AnimationMaker.h"
#include "PortScene.h"

#define DEBUG false

GameScene::GameScene(BattleModel *model)
{
	
	this->model = model;
	battleBar = new BattleBar(this);
	leftCornerLable = nullptr;
	nightFight = false;
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *bgImg;
	if (!nightFight)
		bgImg = Sprite::create("BattleMain/image 86.jpg");
	else
		bgImg = Sprite::create("BattleMain/image 87.jpg");

	bgImg->setPosition(400,240);
	this->addChild(bgImg);

	closeUpBorder = Sprite::create("BattleMain/image 303.png");
	this->addChild(closeUpBorder);
	closeUpBorder->setZOrder(1);
	closeUpBorder->setOpacity(0);

	temptimer = Sprite::create("BattleMain/image 478.png");
	this->addChild(temptimer);
	initLeftCornerBar();

	

	//debug
	if (DEBUG)
	{
		std::vector<CharacterInfo*> heros = model->getAllies();
		for (int i = 0; i < heros.size(); i++)
		{
			BattleHero *hero = BattleHero::create(heros[i], this, (i + 1));
			hero->setMaxHp(heros[i]->maxHP);
			battleHeros.push_back(hero);
		}
		std::vector<CharacterInfo*> enemies = model->getEnemies();
		for (int i = 0; i < enemies.size(); i++)
		{
			BattleEnemy *enemy = BattleEnemy::create(enemies[i], this, (i + 1));
			enemy->setMaxHp(enemies[i]->maxHP);
			battleEnemies.push_back(enemy);
		}
		fireBattle();

		
	}
	else
	{
		status = start;
		BattleStart();
	}
	
}
void GameScene::nextStatus(float DelayTime)
{
	auto callFunc = CallFunc::create(CC_CALLBACK_0(GameScene::onStatusOverCallBack, this));
	auto *seq = Sequence::create(DelayTime::create(DelayTime), callFunc, NULL);
	temptimer->runAction(seq);


}
void GameScene::onStatusOverCallBack(){
	if (status == BattleStatus::start)
	{
		status = BattleStatus::character;
		initCharacters();
	}
	else if (status == BattleStatus::character)
	{
		status = BattleStatus::scout;
		scoutStart();
	}
	else if (status == BattleStatus::scout)
	{
		status = BattleStatus::enemy;
		initEnemy();
	}
	else if (status == BattleStatus::enemy)
	{
		status = BattleStatus::airbattle;
		airBattle();
	}
	else if (status == BattleStatus::airbattle)
	{
		status = BattleStatus::firebattle;
		fireBattle();
	}
	else {
		PortScene *p = new PortScene();
		Director::getInstance()->replaceScene(p);
	}

}
void GameScene::BattleStart()
{	
	hideLeftCornerBar();
	auto *startBorderUp = Sprite::create("commonAssets/image 472.png");
	auto *startBorderDown = Sprite::create("commonAssets/image 470.png");
	startBorderDown->setPosition(400, 130);
	startBorderUp->setPosition(400, 330);
	this->addChild(startBorderDown);
	this->addChild(startBorderUp);
	auto *battleStart = Sprite::create("BattleMain/image 51.png");
	battleStart->setPosition(400, 240);
	this->addChild(battleStart);

	//animation
	
	auto *actionMoveUp = CCMoveTo::create(1, Point(400, 580));
	auto *actionMoveDown = CCMoveTo::create(1, Point(400, -100));
	auto *actionMoveLeft = CCMoveTo::create(0.6, Point(360, 240));
	auto *actionFadeout = CCFadeOut::create(0.6);
	auto action = Sequence::create(actionMoveUp,  NULL);
	startBorderDown->runAction(actionMoveDown);
	startBorderUp->runAction(action);
	battleStart->runAction(actionFadeout);
	battleStart->runAction(actionMoveLeft);
	
	nextStatus(1);
}
void GameScene::initFormation()
{
	myFormation= new Formation(model->getAllies().size(), model->getAlliesFormation());
	enemyFormation= new Formation(model->getEnemies().size(), model->getEnemyFormation(), true);
	myFormation->addBattleBorder();
	enemyFormation->addBattleBorder();
	this->addChild(myFormation);
	this->addChild(enemyFormation);
	myFormation->setPosition(75, 90);
	enemyFormation->setPosition(715, 400);
	myFormation->setVisible(false);
	enemyFormation->setVisible(false);
	
}
void GameScene::initCharacters()
{
	if (nullptr != this->model)
	{
		std::vector<CharacterInfo*> heros = model->getAllies();
		
		for (int i = 0; i < heros.size(); i++)
		{
			BattleHero *hero = BattleHero::create(heros[i], this, (i + 1));
			hero->setMaxHp(heros[i]->maxHP);
			battleHeros.push_back(hero);
			hero->setPosition(-160, 0);
			CCFiniteTimeAction *actionMoveOut = CCMoveTo::create(0.3, Point(0, 0));
			auto action = Sequence::create(CCDelayTime::create(0.1 * i), actionMoveOut, NULL);
			hero->runAction(action);
		}
		nextStatus(0.1 * heros.size() + 0.3 + 0.3);
		return;
	}
	//default

}
void GameScene::initEnemy()
{
	//enemy seen
	battleBar->openAndCloseAnimation(center, enemy_seen);
	enemyFormation->showPoints();
	if (nullptr != this->model)
	{
		std::vector<CharacterInfo*> enemies = model->getEnemies();

		for (int i = 0; i < enemies.size(); i++)
		{
			BattleEnemy *enemy = BattleEnemy::create(enemies[i], this, (i + 1));
			enemy->setMaxHp(enemies[i]->maxHP);
			battleEnemies.push_back(enemy);
			enemy->apearAnimation();
		}
		nextStatus(0.1 * enemies.size() + 0.3 + 0.3);
		return;
	}
	

	nextStatus(1.5);
	
}

void GameScene::initLeftCornerBar()
{
	

	leftCornerBar = Sprite::create("BattleMain/image 164.png");
	leftCornerBar->setPosition(128, 427);
	//leftCornerBar->setVisible(false);
	this->addChild(leftCornerBar);
	if (nightFight)
		leftCornerCircle = Sprite::create("BattleMain/image 161.png");
	else
	leftCornerCircle = Sprite::create("BattleMain/image 159.png");
	leftCornerCircle->setPosition(18, 427);
	auto *circleAction = RotateBy::create(1, 90);
	auto *sequence = Sequence::create(circleAction, NULL);
	auto *repeat = RepeatForever::create((ActionInterval*)sequence);
	leftCornerCircle->runAction(repeat);
	this->addChild(leftCornerCircle);
}
void GameScene::hideLeftCornerBar()
{
	if (nullptr != leftCornerBar)
	{
		auto *fadeOut1 = FadeOut::create(0.3);
		leftCornerBar->runAction(fadeOut1);
	}
	if (nullptr != leftCornerCircle)
	{
		auto *fadeOut2 = FadeOut::create(0.3);
		leftCornerCircle->runAction(fadeOut2);
	}
	if (nullptr != leftCornerLable)
	{
		auto *fadeOut3 = FadeOut::create(0.3);
		leftCornerLable->runAction(fadeOut3);
	}
	
}
void GameScene::showLeftCornerBar(LeftCornerType type)
{
	if (nullptr != leftCornerBar)
	{
		auto *fadeIn1 = FadeIn::create(0.3);
		leftCornerBar->runAction(fadeIn1);
	}
	if (nullptr != leftCornerCircle)
	{
		auto *fadeIn2 = FadeIn::create(0.3);
		leftCornerCircle->runAction(fadeIn2);
	}
	if (nullptr != leftCornerLable)
	{
		delete leftCornerLable;
	}
		switch (type)
		{
		case GameScene::suodi:
			leftCornerLable = Sprite::create("BattleMain/image 166.png");
			break;
		case GameScene::paojizhan:
			leftCornerLable = Sprite::create("BattleMain/image 170.png");
			break;
		case GameScene::yezhan:
			leftCornerLable = Sprite::create("BattleMain/image 188.png");
			break;
		case GameScene::hangkongzhan:
			leftCornerLable = Sprite::create("BattleMain/image 168.png");
			break;
		default:
			break;
		}
		leftCornerLable->setPosition(65, 427);
		this->addChild(leftCornerLable);
		auto *fadeIn3 = FadeIn::create(0.3);
		leftCornerLable->runAction(fadeIn3);
		
	

}

void GameScene::showCloseUpBorder()
{
	closeUpBorder->setPosition(1200, -240);
	auto *fadeIn = FadeIn::create(0.1);
	auto *moveToCenter = MoveTo::create(0.2, Point(400, 190));
	auto *fadeOut = FadeOut::create(0.5);
	auto *seq = Sequence::create(DelayTime::create(1), fadeIn, moveToCenter, DelayTime::create(2), fadeOut, NULL);
	closeUpBorder->runAction(seq);
}
void GameScene::scoutStart()
{
	//show formation
	initFormation();
	myFormation->setScale(0.001);
	myFormation->setVisible(true);
	myFormation->showPoints();
	
	enemyFormation->setScale(0.001);
	enemyFormation->setVisible(true);

	auto *myscaleUp = ScaleBy::create(0.5, 1000);
	auto *enemyscaleUp = ScaleBy::create(0.5, 1000);
	myFormation->runAction(myscaleUp);
	enemyFormation->runAction(enemyscaleUp);

	//scout start
	showLeftCornerBar(suodi);

	battleBar->openAndCloseAnimation(center, scout_start);
	auto action = Sequence::create(CCDelayTime::create(1), CallFunc::create(CC_CALLBACK_0(GameScene::doScout, this)), NULL);
	battleBar->runAction(action, center);
}



void GameScene::doScout()
{
	//slide
	auto *slide = Sprite::create("BattleMain/image 66.png");
	slide->setPosition(400, 240);
	slide->setRotation(120);
	slide->setScaleY(0.5);
	FiniteTimeAction *scale = ScaleBy::create(0.8, 40, 1);
	FiniteTimeAction *fadeOut = FadeOut::create(0.5);
	auto actionSlide = Sequence::create(scale, CCDelayTime::create(2.5), fadeOut, NULL);
	this->addChild(slide);
	slide->runAction(actionSlide);

	//plane
	auto *plane = Sprite::create("BattleMain/image 114.png");
	plane->setPosition(20, -20);
	this->addChild(plane);
	FiniteTimeAction *move = MoveTo::create(1.5, Point(880, 520));
	Sequence *planeAction = Sequence::create(CCDelayTime::create(0.75), move, CallFunc::create(CC_CALLBACK_0(GameScene::scoutResult, this)),NULL);
	plane->runAction(planeAction);

}
void GameScene::scoutResult()
{
	bool enemyFound = true;

	hideLeftCornerBar();
	
	if (enemyFound)
	{		
		
		battleBar->openAndCloseAnimation(topleft, enemy_scouted);
		nextStatus(1.5);

		auto *statusUp = Sprite::create("BattleMain/image 515.png");
		statusUp->setPosition(400, 330);
		statusUp->setZOrder(1);
		auto *moveLeft = MoveTo::create(0.2, Point(-400, 330));
		auto actionStatusUp = Sequence::create(CCDelayTime::create(1), moveLeft, NULL);
		
		this->addChild(statusUp);
		statusUp->runAction(actionStatusUp);
	}


}
void GameScene::airBattle()
{
	showLeftCornerBar(hangkongzhan);
	battleHeros[0]->showCloseUp(1.2);
	showCloseUpBorder();
	//plane anime
	AnimationMaker::playPlaneAnimation(this,1.7);
	AnimationMaker::playAirBattleAnimation(this, 3.5);

	//TODO damage
	bool doubleHit = false, ci = false, special = false, miss = false, critical = false;
	int damage;
	model->getFireDamage(true, 1, 2, doubleHit, special, ci, damage, critical, miss);
	battleEnemies[2]->receiveDamage(6.2, miss, critical, damage*3, 2);
	model->getFireDamage(true, 1, 3, doubleHit, special, ci, damage, critical, miss);
	battleEnemies[3]->receiveDamage(6.2, miss, critical, damage*2, 1);
	model->getFireDamage(true, 1, 5, doubleHit, special, ci, damage, critical, miss);
	battleEnemies[5]->receiveDamage(6.2, miss, critical, damage*3, 2);

	nextStatus(3.5 + 3);

}

void GameScene::fireBattle()
{
	showLeftCornerBar(paojizhan);

	//First Round
	float timePassed = 1;
	

	float delay1 = 0.5, delay2 = 1, delay3 = 2;

	bool doubleHit = false, ci = false, special = false, miss = false, critical = false;
	int damage = 10;
	int nextAllies = model->getNextAlliesIndexToFire();
	int nextEnemy = model->getNextEnemyIndexToFire();
	while (nextAllies != -1 || nextEnemy != -1)
	{
		if (nextAllies!=-1)
		{
			if (battleHeros[nextAllies]->canAttack())
			{
				battleHeros[nextAllies]->stepOut(timePassed);
				battleHeros[nextAllies]->showAttackingAnime(timePassed);
				battleEnemies[nextEnemy]->stepOut(timePassed);
				model->getFireDamage(true, nextAllies, nextEnemy, doubleHit, special, ci, damage, critical, miss);

				battleEnemies[nextEnemy]->receiveDamage(timePassed + delay1, miss, critical, damage, 1);
				battleEnemies[nextEnemy]->stepBack(timePassed + delay1);
				battleHeros[nextAllies]->stepBack(timePassed + delay2);
				timePassed += delay3; 
			}
		}
		if (nextEnemy!=-1  )
		{
			if (battleEnemies[nextEnemy]->canAttack())
			{
				battleEnemies[nextEnemy]->stepOut(timePassed);
				battleEnemies[nextEnemy]->showAttackingAnime(timePassed);
				battleHeros[nextAllies]->stepOut(timePassed);
				model->getFireDamage(false, nextAllies, nextEnemy, doubleHit, special, ci, damage, critical, miss);
				battleHeros[nextAllies]->receiveDamage(timePassed + delay1, miss, critical, damage, 1);
				battleHeros[nextAllies]->stepBack(timePassed + delay1);
				battleEnemies[nextEnemy]->stepBack(timePassed + delay2);
				timePassed += delay3; 
			}
			
		}
		nextEnemy = model->getNextEnemyIndexToFire();
		nextAllies = model->getNextAlliesIndexToFire();
	}
	
	timePassed += 3;
	//Second Round

	nextStatus(timePassed);
	
}
