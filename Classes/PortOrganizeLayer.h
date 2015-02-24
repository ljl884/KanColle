#ifndef _PORT_ORGANIZE_LAYER_
#define _PORT_ORGANIZE_LAYER_

#include "cocos2d.h"
#include "OrganizeContainer.h"
#include "CharacterDetailPage.h"
#include "CharacterListPage.h"
#include "GameModel.h"
using namespace cocos2d;

class PortOrganizeLayer : public Layer
{
public:
	PortOrganizeLayer(Node *parent);
	void selectFleet(Ref* pSender, int fleetIndex);
	void clearFleet(Ref* pSender);
	void hideDetail(Ref* pSender);
	void showDetail(int index);
	void hideList(Ref* pSender);
	void showList(int index);
	void updateContainers();
	inline int getSelectedShipIndex(){ return selectedShipIndex; }
	inline void setSelectedShipIndex(int index){ this->selectedShipIndex = index; }
private:
	Node * parent;
	CharacterDetailPage * detailPage;
	CharacterListPage * listPage;
	MenuItemSprite * hideDetailItem;
	MenuItemSprite * hideListItem;
	int currentFleetIndex;
	int selectedShipIndex;
	std::vector<Sprite *>fleeticons;
	std::vector<OrganizeContainer *> containers;
	void setCurrentFleet(int fleetIndex);
	

private:
	void initLayer();
	
	
};


#endif