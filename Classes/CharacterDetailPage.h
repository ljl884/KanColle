#ifndef _CHARACTER_DETAIL_PAGE_
#define _CHARACTER_DETAIL_PAGE_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "Stars.h"
#include "HpBar.h"
#include "EquipmentContainer.h"

using namespace cocos2d;
class PortRemodeLayer;
class CharacterDetailPage : public Node{
public:
	CharacterDetailPage(PortRemodeLayer* parent);
	CharacterDetailPage();
	void setCharacter(CharacterInfo* info);
	void upgradeButtonCallback(Ref* pSender);
	void powerUpButtonCallback(Ref* pSender);
	void moveOut();
	void moveIn();
	inline bool isHidden(){ return Hidden; }
private:
	bool Hidden;
	void initPage();
	Sprite* characterImage;
	Label * name;
	Label * level;
	Label * HP;
	HpBar * hpBar;
	Label * maxHP;
	Label* firePower;
	Label * armour;
	Label * torpedo;
	Label * agility;
	Label * antiaircraft;
	Label * capacity;
	Label * antisubmarine;
	Label * scout;
	Label * luck;
	Sprite * speed;
	Sprite * range;
	
	EquipmentContainer *equipmentContainer1;
	EquipmentContainer *equipmentContainer2;
	EquipmentContainer *equipmentContainer3;
	EquipmentContainer *equipmentContainer4;
	
	Stars * stars;

};
#endif