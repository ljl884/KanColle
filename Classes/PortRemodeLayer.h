#ifndef _PORT_REMODE_LAYER_
#define _PORT_REMODE_LAYER_

#include "cocos2d.h"
using namespace cocos2d;
class PortRemodeLayer : public Layer
{
public:
	PortRemodeLayer(Node *parent);
	
	

private:
	Node * parent;
	void callBack(Ref* pSender);

private:
	void initLayer();
	
};


#endif