#ifndef _PORT_REMODE_LAYER_
#define _PORT_REMODE_LAYER_

#include "cocos2d.h"
#include "CharacterDetailPage.h"
#include "GameModel.h"
using namespace cocos2d;
class PortRemodeLayer : public Layer
{
public:
	PortRemodeLayer(Node *parent);
	void callBack(Ref* pSender);
	

private:
	Node * parent;
	CharacterDetailPage* detailPage;
	

private:
	void initLayer();
	
};


#endif