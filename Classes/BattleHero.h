#ifndef _BATTLE_HERO_
#define _BATTLE_HERO_

#include "cocos2d.h"
#include "BattleCharacter.h"
using namespace cocos2d;

class BattleHero :public BattleCharacter{
public:
	static BattleHero* create(std::string name, Node *parent, int row);
	static BattleHero* create(CharacterInfo *info, Node *parent, int row);
	bool init(std::string name, Node *parent, int row);
	virtual float showCloseUp(float delay);
	virtual void stepOut(float delay);
	virtual void stepBack(float delay);
	virtual float showAttackingAnime(float delay);
protected:
	virtual void setBroken(BrokenType type);
	virtual void updateInformationBoard();
	

	

};

#endif // _BATTLE_HERO_
