#ifndef _CHARACTER_LIST_PAGE_
#define _CHARACTER_LIST_PAGE_
#include "cocos2d.h"
#include "CharacterInfo.h"
#include "GameModel.h"
using namespace cocos2d;
class PortOrganizeLayer;
class CharacterListPage:public Node{

public:
	CharacterListPage(PortOrganizeLayer *parent);
	void sortButtonCallback	(Ref* pSender);
	void exchangeCallback(Ref* pSender,int indexInList);
	void setPageCallback(Ref* PSendr, int page);
	void moveOut();
	void moveIn();
	inline bool isHidden(){ return Hidden; }
private:
	int currentPage;
	PortOrganizeLayer* parent;
	bool Hidden;
	Sprite* sortButton;
	Menu *menu;

	//list
	Menu *listMenu;
	Node *firstRow;
	std::vector<Node*> rows;
	Node *list;

	void updateList(int page);
	Node * makeRow(CharacterInfo* info);
	std::vector<CharacterInfo*> displayingCharacters;
};

#endif