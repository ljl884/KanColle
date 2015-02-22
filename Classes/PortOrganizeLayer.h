#ifndef _PORT_ORGANIZE_LAYER_
#define _PORT_ORGANIZE_LAYER_

#include "cocos2d.h"
#include "OrganizeContainer.h"
#include "GameModel.h"
using namespace cocos2d;

class PortOrganizeLayer : public Layer
{
public:
	PortOrganizeLayer(Node *parent);
	void selectFleet(Ref* pSender, int fleetIndex);
	void clearFleet(Ref* pSender);
	

private:
	Node * parent;
	int currentFleetIndex;
	std::vector<Sprite *>fleeticons;
	std::vector<OrganizeContainer *> containers;
	void setCurrentFleet(int fleetIndex);
	

private:
	void initLayer();
	
	
};


#endif