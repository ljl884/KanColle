#ifndef _PORT_REPAIR_LAYER_
#define _PORT_REPAIR_LAYER_

#include "cocos2d.h"
using namespace cocos2d;
class PortRepairLayer : public Layer
{
public:
	PortRepairLayer(Node *parent);
	

private:
	Node * parent;


private:
	void initLayer();
	
};


#endif