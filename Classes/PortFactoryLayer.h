#ifndef _PORT_FACTORY_LAYER_
#define _PORT_FACTORY_LAYER_

#include "cocos2d.h"
using namespace cocos2d;
class PortFactoryLayer : public Layer
{
public:
	PortFactoryLayer(Node *parent);
	
	

private:
	Node * parent;

private:
	void initLayer();
	void callBack(Ref* pSender);
	
};


#endif