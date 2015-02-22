#ifndef _BATTLE_ENEMY_
#define _BATTLE_ENEMY_

#include "cocos2d.h"
#include "BattleCharacter.h"
using namespace cocos2d;

class BattleEnemy :public BattleCharacter{
public:
	static BattleEnemy* create(std::string name, Node *parent, int row);
	static BattleEnemy* create(CharacterInfo *info, Node *parent, int row);
	bool init(std::string name, Node *parent, int row);
	virtual void setCurrentHp(int hp);
	virtual void setMaxHp(int hp);
	virtual void showCloseUp();
	virtual void stepOut(float delay);
	virtual void stepBack(float delay);
	void apearAnimation();
	virtual float showAttackingAnime(float delay);
private:
	virtual void ThreeDigitMode();
	virtual void updateInformationBoard();
	
};

#endif // _BATTLE_ENEMY_
