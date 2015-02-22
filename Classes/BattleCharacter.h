#ifndef _BATTLE_CHARACTER_
#define _BATTLE_CHARACTER_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "BattleBar.h"
#include "AnimationMaker.h"
using namespace cocos2d;


class BattleCharacter :public Node{
public:
	BattleCharacter();
	Point getRealPosition();
	virtual void setCurrentHp(int hp);	
	virtual void setMaxHp(int hp);
	virtual float showCloseUp(float delay){ return 0; };
	virtual float showAttackingAnime(float delay){ return 0; };

	virtual bool canAttack();
	
	float receiveDamage(float delay, bool miss, bool critical, int damage,int explodeTimes);
	
	virtual void stepOut(float delay){};
	virtual void stepBack(float delay){};
protected:

	CharacterInfo *info;
	inline void setInfo(CharacterInfo *info){ this->info = info; }
	inline CharacterInfo* getInfo(CharacterInfo *info){ return this->info; }

	Sprite * mainSprite;
	Sprite * border;
	Sprite * hpBar;
	Sprite * flagIcon;
	Sprite * closeUp;
	Sprite * brokenMark;

	BattleBar * battleBar;
	Sprite* equipmentLabel;

	Sprite * informationBoard;
	Label *firePowerLabel;
	Label *torpedoLabel;
	Label *antiaircraftLabel;
	Label *nameLabel;
	Label *levelLabel;
	Label *armourLabel;
	
	virtual void ThreeDigitMode(){};
	virtual void setBroken(BrokenType type);
	void getDamage(int damage);
	void showAttackedAnime(float delay);
	void showDamageAnime(float delay, bool miss, bool critical, int damage);
	virtual void updateInformationBoard(){};
	
	Label *maxHpLabel;
	Label *currentHpLabel;
	int maxHp;
	int currentHp;
	std::string name;
	Node * parent;
	bool useJpg;
	Sprite *shader;


public:
	std::string int2str(int &i);
};

#endif // _BATTLE_CHARACTER_
