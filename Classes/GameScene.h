#ifndef _GAME_SCENE_
#define _GAME_SCENE_

#include "cocos2d.h"
#include "BattleModel.h"
#include "BattleBar.h"
#include "BattleHero.h"
#include "BattleEnemy.h"
#include "formation.h"
using namespace cocos2d;

enum BattleStatus{
	start,
	character,
	scout,
	formation,
	enemy,
	airbattle,
	firebattle
};

class GameScene : public Scene{
public: 
	GameScene(BattleModel *model);
	
private:
	BattleModel* model;
	
private:
	void onStatusOverCallBack();
	void initCharacters();
	void initEnemy();
	void BattleStart();
	void initFormation();
	void scoutStart();
	void doScout();
	void scoutResult();
	void airBattle();
	void fireBattle();

	void nextStatus(float DelayTime);

private:	//Left Corner Bar
	enum LeftCornerType
	{
		suodi,
		paojizhan,
		yezhan,
		hangkongzhan
	};
	void initLeftCornerBar();
	void hideLeftCornerBar();
	void showLeftCornerBar(LeftCornerType type);
	Sprite *leftCornerBar;
	Sprite *leftCornerCircle;
	Sprite *leftCornerLable;


private:
	BattleBar* battleBar;
	BattleStatus status;
	Formation *myFormation;
	Formation *enemyFormation;
	Sprite * temptimer;
	Sprite * closeUpBorder;
	void showCloseUpBorder();
	bool nightFight;

private:
	std::vector<BattleHero*> battleHeros;
	std::vector<BattleEnemy*> battleEnemies;
	
};

#endif // _GAME_SCENE_
