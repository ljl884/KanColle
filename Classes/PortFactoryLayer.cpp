#include "PortFactoryLayer.h"

PortFactoryLayer::PortFactoryLayer(Node* parent)
{
	this->parent = parent;
	initLayer();
}

void PortFactoryLayer::initLayer()
{
	auto bgimg = Sprite::create("ArsenalMain/image 249.png");
	this->addChild(bgimg);
	bgimg->setOpacity(200);
	bgimg->setPosition(450, 200);

	auto mainBody = Sprite::create("ArsenalMain/image 3.png");
	this->addChild(mainBody);
	mainBody->setPosition(580, 200);

	auto buildButton = MenuItemImage::create("ArsenalMain/image 180.png", "ArsenalMain/image 178.png", CC_CALLBACK_1(PortFactoryLayer::callBack, this));
	buildButton->setPosition(230, 320);
	auto destroyButton = MenuItemImage::create("ArsenalMain/image 184.png", "ArsenalMain/image 186.png", CC_CALLBACK_1(PortFactoryLayer::callBack, this));
	destroyButton->setPosition(230, 245);
	auto developButton = MenuItemImage::create("ArsenalMain/image 190.png", "ArsenalMain/image 192.png", CC_CALLBACK_1(PortFactoryLayer::callBack, this));
	developButton->setPosition(230, 160);
	auto throwButton = MenuItemImage::create("ArsenalMain/image 196.png", "ArsenalMain/image 198.png", CC_CALLBACK_1(PortFactoryLayer::callBack, this));
	throwButton->setPosition(230, 80);

	auto menu = Menu::create(buildButton, destroyButton, developButton, throwButton, NULL);
	menu->setPosition(0, 0);
	this->addChild(menu);
}

void PortFactoryLayer::callBack(Ref* pSender)
{}

