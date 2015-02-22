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

	auto bgimg2 = Sprite::create("RemodelMain/image 169.png");
	this->addChild(bgimg2);
	bgimg2->setOpacity(250);
	bgimg2->setPosition(600, 200);

	auto paramBoard = Sprite::create("commonAssets/image 269.png");
	this->addChild(paramBoard);
	paramBoard->setPosition(450, 90);



	auto upgradeButton = MenuItemImage::create("commonAssets/image 152.png", "commonAssets/image 154.png", CC_CALLBACK_1(PortRemodeLayer::callBack, this));
	upgradeButton->setPosition(730, 50);
	auto powerUpButton = MenuItemImage::create("commonAssets/image 161.png", "commonAssets/image 163.png", CC_CALLBACK_1(PortRemodeLayer::callBack, this));
	powerUpButton->setPosition(610, 50);

	auto menu = Menu::create(upgradeButton, powerUpButton, NULL);
	this->addChild(menu);
	menu->setPosition(0, 0);

}

void PortRemodeLayer::callBack(Ref* pSender)
{
}