#include "PortRemodeLayer.h"

PortRemodeLayer::PortRemodeLayer(Node* parent)
{
	this->parent = parent;
	initLayer();
}

void PortRemodeLayer::initLayer()
{
	auto bgimg = Sprite::create("RemodelMain/image 169.png");
	this->addChild(bgimg);
	bgimg->setOpacity(200);
	bgimg->setPosition(400, 200);

	detailPage = new CharacterDetailPage(this);
	detailPage->setCharacter(GameModel::getInstance()->getFleet(0)->getShip(0));

}

void PortRemodeLayer::callBack(Ref* pSender)
{
}