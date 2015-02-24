#ifndef _ORGANIZE_EXCHANGE_PAGE_
#define _ORGANIZE_EXCHANGE_PAGE_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "CharacterCard.h"
#include "Stars.h"
#include "HpBar.h"

using namespace cocos2d;
class CharacterListPage;
class OrganizeExchangePage : public Node{
public:
	OrganizeExchangePage(CharacterListPage* parent);
	OrganizeExchangePage();
	void setCharacter(CharacterInfo* info);
	void buttonCallback(Ref* pSender);
	void moveOut();
	void moveIn();
	inline bool isHidden(){ return Hidden; }
private:
	CharacterListPage* parent;
	bool Hidden;
	void initPage();
	CharacterCard * card;
	Label * name;
	Label * level;
	Label * HP;
	HpBar * hpBar;
	Label * maxHP;
	Label* firePower;
	Label * armour;
	Label * torpedo;
	Label * antiaircraft;



	Stars * stars;

};
#endif