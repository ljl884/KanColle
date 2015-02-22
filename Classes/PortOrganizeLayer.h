#ifndef _PORT_ORGANIZE_LAYER_
#define _PORT_ORGANIZE_LAYER_

#include "cocos2d.h"
using namespace cocos2d;
class PortOrganizeLayer : public Layer
{
public:
	PortOrganizeLayer(Node *parent);
	
	

private:
	Node * parent;

private:
	void initLayer();
	
};


#endif