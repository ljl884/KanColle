#ifndef _CHARACTER_CARD_
#define _CHARACTER_CARD_

#include "cocos2d.h"
#include "CharacterInfo.h"
using namespace cocos2d;

class CharacterCard :public Node{
public:
	CharacterCard();
	CharacterCard(CharacterInfo* info);
	CharacterCard(std::string resourcefolder);
	CharacterCard(bool isEnemy,std::string resourcefolder);
	void setBrokenMark(BrokenType brokenType);
	void updateCharacter(std::string resourcefolder, BrokenType type);
	
private:
	void initCard();
	bool isEnemy;
	Sprite* mainImage;
	Sprite* shader;
	Sprite* brokenMark;
};

#endif