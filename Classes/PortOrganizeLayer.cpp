#include "PortOrganizeLayer.h"

PortOrganizeLayer::PortOrganizeLayer(Node* parent)
{
	this->parent = parent;
	this->setZOrder(-1);
	initLayer();
}

void PortOrganizeLayer::initLayer()
{
	auto bgimg = Sprite::create("OrganizeMain/image 139.png");
	this->addChild(bgimg);
	bgimg->setOpacity(250);
	bgimg->setPosition(450, 200);

	auto container1 = Sprite::create("OrganizeMain/image 221.png");
	auto container2 = Sprite::create("OrganizeMain/image 221.png");
	auto container3 = Sprite::create("OrganizeMain/image 221.png");
	auto container4 = Sprite::create("OrganizeMain/image 221.png");
	auto container5 = Sprite::create("OrganizeMain/image 221.png");
	auto container6 = Sprite::create("OrganizeMain/image 221.png");

	container1->setPosition(290, 300);
	container2->setPosition(290, 190);
	container3->setPosition(290, 80);
	container4->setPosition(628, 300);
	container5->setPosition(628, 190);
	container6->setPosition(628, 80);

	this->addChild(container1);
	this->addChild(container2);
	this->addChild(container3);
	this->addChild(container4);
	this->addChild(container5);
	this->addChild(container6);


}