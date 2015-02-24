#include "PortOrganizeLayer.h"


PortOrganizeLayer::PortOrganizeLayer(Node* parent)
{
	this->parent = parent;
	this->setZOrder(-1);
	initLayer();
}

void PortOrganizeLayer::initLayer()
{
	GameModel *gamemodel = GameModel::getInstance();

	auto menu = Menu::create(NULL);
	menu->setPosition(Point::ZERO);
	

	auto bgimg = Sprite::create("OrganizeMain/image 139.png");
	this->addChild(bgimg);
	bgimg->setOpacity(250);
	bgimg->setPosition(450, 200);

	auto top_bar = Sprite::create("OrganizeMain/image 177.png");
	this->addChild(top_bar);
	top_bar->setPosition(450, 397);

	auto top_label = Sprite::create("OrganizeMain/image 159.png");
	this->addChild(top_label);
	top_label->setPosition(160, 397);

	
	fleeticons.push_back(Sprite::create("commonAssets/image 68.png"));
	fleeticons.push_back(Sprite::create("commonAssets/image 77.png"));
	fleeticons.push_back(Sprite::create("commonAssets/image 89.png"));
	fleeticons.push_back(Sprite::create("commonAssets/image 96.png"));
	
	for (int i = 0; i < fleeticons.size(); i++)
	{
		auto fleetButton = MenuItemSprite::create(fleeticons[i], fleeticons[i], CC_CALLBACK_1(PortOrganizeLayer::selectFleet, this, i));
		fleetButton->setPosition(140 + 26 * i, 368);
		menu->addChild(fleetButton);
	}


	auto clearFleetButton = MenuItemImage::create("OrganizeMain/image 162.png", "OrganizeMain/image 164.png", CC_CALLBACK_1(PortOrganizeLayer::clearFleet, this));
	clearFleetButton->setPosition(415, 365);
	menu->addChild(clearFleetButton);

	auto fleet_name_text_box = Sprite::create("OrganizeMain/image 140.png");
	fleet_name_text_box->setPosition(600, 370);
	this->addChild(fleet_name_text_box);

	auto editFleetNameButton = Sprite::create("OrganizeMain/image 142.png");
	this->addChild(editFleetNameButton);
	editFleetNameButton->setPosition(767,370);

	auto closeItem = Sprite::create("commonAssets/image 451.jpg");
	closeItem->setZOrder(10);
	closeItem->setOpacity(0);
	hideDetailItem = MenuItemSprite::create(closeItem, closeItem, CC_CALLBACK_1(PortOrganizeLayer::hideDetail, this));
	hideDetailItem->setPosition(400, 240);
	hideDetailItem->setEnabled(false);
	menu->addChild(hideDetailItem);

	auto closeItem2 = Sprite::create("commonAssets/image 451.jpg");
	closeItem2->setZOrder(10);
	closeItem2->setOpacity(0);
	hideListItem = MenuItemSprite::create(closeItem2, closeItem2, CC_CALLBACK_1(PortOrganizeLayer::hideList, this));
	hideListItem->setPosition(-42, 240);
	hideListItem->setEnabled(false);
	menu->addChild(hideListItem);

	for (int i = 0; i < NUMBER_OF_CONTAINERS; i++)
		containers.push_back(new OrganizeContainer(this, i));
	updateContainers();
	
	this->addChild(menu);

	//Detail Page
	detailPage = new CharacterDetailPage();
	this->addChild(detailPage);
	detailPage->setPosition(800, 0);
	detailPage->setCharacter(gamemodel->getFleet(0)->getShip(2));

	//List Page 
	listPage = new CharacterListPage(this);
	listPage->setPosition(800, 0);
	this->addChild(listPage);

}
void PortOrganizeLayer::updateContainers()
{
	GameModel *gamemodel = GameModel::getInstance();
	for (int i = 0; i < NUMBER_OF_CONTAINERS; i++)
	{		
		containers[i]->updateCharacterInfo(gamemodel->getFleet(0)->getShip(i));

		if (i == 0)
			containers[i]->setPosition(290, 300);
		else if (i == 1)
			containers[i]->setPosition(628, 300);
		else if (i == 2)
			containers[i]->setPosition(290, 190);
		else if (i == 3)
			containers[i]->setPosition(628, 190);
		else if (i == 4)
			containers[i]->setPosition(290, 80);
		else if (i == 5)
			containers[i]->setPosition(628, 80);

	}

}
void PortOrganizeLayer::showDetail(int index)
{
	if (detailPage->isHidden())
	{
		detailPage->moveIn();
	}
	GameModel *gamemodel = GameModel::getInstance();
	detailPage->setCharacter(gamemodel->getFleet(0)->getShip(index));
	hideDetailItem->setEnabled(true);

}
void PortOrganizeLayer::hideDetail(Ref* pSender)
{
	detailPage->moveOut();
	hideDetailItem->setEnabled(false);
}
void PortOrganizeLayer::hideList(Ref* pSender)
{
	listPage->moveOut();
	hideListItem->setEnabled(false);
}
void PortOrganizeLayer::showList(int index)
{
	if (listPage->isHidden())
	{
		listPage->moveIn();
	}
	hideListItem->setEnabled(true);
}
void PortOrganizeLayer::selectFleet(Ref* pSender, int fleetIndex)
{
	setCurrentFleet(fleetIndex);
}

void PortOrganizeLayer::clearFleet(Ref* pSender)
{

}
void PortOrganizeLayer::setCurrentFleet(int fleetIndex)
{
	

}