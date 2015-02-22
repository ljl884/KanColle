#ifndef _PORT_SUPPLY_LAYER_
#define _PORT_SUPPLY_LAYER_

#include "cocos2d.h"
using namespace cocos2d;
class PortSupplyLayer : public Layer
{
public:
	PortSupplyLayer(Node *parent);
	
	

private:
	Node * parent;

private:
	void initLayer();
	void callBack(Ref* pSender);
	
};


#endif