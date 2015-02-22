#ifndef _ORGANIZE_CONTAINER_
#define _ORGANIZE_CONTAINER_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "Stars.h"
#define NUMBER_OF_CONTAINERS 6

using namespace cocos2d;
class PortOrganizeLayer;

class OrganizeContainer:public Node{

public:
	OrganizeContainer(PortOrganizeLayer * parent,int index);
	void updateCharacterInfo(CharacterInfo* info);
	void detailCallback(Ref* pSender);
	void changeCallback(Ref* pSender);
private:
	PortOrganizeLayer *parent;
	Sprite* bg;
	Sprite *IndexIcon;
	
	int Index;
	MenuItemImage * detailButton;
	MenuItemImage * changeButton;

	Sprite * characterImage;
	Label * name;
	Label * level;
	Label * HP;
	Label* firePower;
	Label * antiaircraft;
	Label * torpedo;
	Label * armour;
	Stars * stars;
	
};

#endif