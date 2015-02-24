#include "CharacterListPage.h"
#include "Helper.h"
#include "PortOrganizeLayer.h"
#define SHIPS_PER_PAGE 10
#define FONT_COLOR Color3B::BLACK

CharacterListPage::CharacterListPage(PortOrganizeLayer* parent)
{
	this->parent = parent;
	Hidden = true;
	menu = Menu::create(NULL);
	

	auto bgimg = Sprite::create("OrganizeMain/image 176.png");
	this->addChild(bgimg);
	bgimg->setPosition(654, 195);

	auto titleBar = Sprite::create("OrganizeMain/image 177.png");
	this->addChild(titleBar);
	titleBar->setPosition(753, 397);

	auto top_label = Sprite::create("OrganizeMain/image 178.png");
	this->addChild(top_label);
	top_label->setPosition(398, 399);

	auto category = Sprite::create("OrganizeMain/image 179.png");
	this->addChild(category);
	category->setPosition(595, 370);

	sortButton = Sprite::create("OrganizeMain/image 189.png");
	auto sortMenuItem = MenuItemSprite::create(sortButton, sortButton, CC_CALLBACK_1(CharacterListPage::sortButtonCallback, this));
	sortMenuItem->setPosition(773, 370);
	menu->addChild(sortMenuItem);


	//list
	list = Node::create();
	this->addChild(list);

	listMenu = Menu::create(NULL);
	listMenu->setPosition(Point::ZERO);
	this->addChild(listMenu);
	firstRow = makeRow(nullptr);
	firstRow->setPosition(540, 345);
	this->addChild(firstRow);
	for (int i = 0; i < SHIPS_PER_PAGE; i++)
	{
		auto node = Node::create();
		rows.push_back(node);
	
		auto item = Sprite::create("OrganizeMain/image 182.png");
		item->setOpacity(0);
		auto menuitem = MenuItemSprite::create(item, Sprite::create("OrganizeMain/image 182.png"), item, CC_CALLBACK_1(CharacterListPage::exchangeCallback, this, i));
		menuitem->setPosition(550, 347 - (i + 1) * 28);
		menuitem->setScaleY(0.85);
		listMenu->addChild(menuitem);
	}
	currentPage = 0;
	updateList(currentPage);

	//bottom button
	auto firstPage = MenuItemImage::create("commonAssets/image 196.png", "commonAssets/image 196.png");
	firstPage->setPosition(430,33);
	auto previousPage = MenuItemImage::create("commonAssets/image 190.png", "commonAssets/image 190.png");
	previousPage->setPosition(465, 33);
	auto nextPage = MenuItemImage::create("commonAssets/image 187.png", "commonAssets/image 187.png");
	nextPage->setPosition(685, 33);
	auto lastPage = MenuItemImage::create("commonAssets/image 193.png", "commonAssets/image 193.png");
	lastPage->setPosition(720, 33);
	auto Page1 = MenuItemLabel::create(Label::create("1", "fonts/DengXian.ttf", 16));
	Page1->setPosition(502, 33);
	Page1->setColor(Color3B(0,127,255));
	auto Page2 = MenuItemLabel::create(Label::create("2", "fonts/DengXian.ttf", 16));
	Page2->setPosition(539, 33);
	Page2->setColor(FONT_COLOR);
	auto Page3 = MenuItemLabel::create(Label::create("3", "fonts/DengXian.ttf", 16));
	Page3->setPosition(576, 33);
	Page3->setColor(FONT_COLOR);
	auto Page4 = MenuItemLabel::create(Label::create("4", "fonts/DengXian.ttf", 16));
	Page4->setPosition(613, 33);
	Page4->setColor(FONT_COLOR);
	auto Page5 = MenuItemLabel::create(Label::create("5", "fonts/DengXian.ttf", 16));
	Page5->setPosition(650, 33);
	Page5->setColor(FONT_COLOR);
	menu->addChild(firstPage);
	menu->addChild(previousPage);
	menu->addChild(nextPage);
	menu->addChild(lastPage);
	menu->addChild(Page1);
	menu->addChild(Page2);
	menu->addChild(Page3);
	menu->addChild(Page4);
	menu->addChild(Page5);

	this->addChild(menu);
	menu->setPosition(Point::ZERO);
}
void CharacterListPage::updateList(int page)
{
	auto gameModel = GameModel::getInstance();
	std::vector<CharacterInfo*> ships  = gameModel->getAllShips();
	//sortByCategory(ships);
	displayingCharacters.clear();
	list->removeAllChildren();
	for (int i = 0; i < SHIPS_PER_PAGE; i++)
	{
		auto row = makeRow(ships[SHIPS_PER_PAGE*page + i]);
		displayingCharacters.push_back(ships[SHIPS_PER_PAGE*page + i]);
		
		rows[i] = row;
		list->addChild(row);
		row->setPosition(540, 345 - (i + 1) * 28);
	}
}


Node* CharacterListPage::makeRow(CharacterInfo* info)
{
	auto node = Node::create();
	Color3B fcolor = FONT_COLOR;
	auto line = Sprite::create("commonAssets/Line.png");
	node->addChild(line);
	line->setPosition(35, -12);
	if (info == nullptr)
	{
		auto firstRow = Label::create(Helper::getString("remove"), "fonts/DengXian.ttf", 13);
		firstRow->setPosition(-135,0);
		firstRow->setColor(fcolor);
		firstRow->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
		node->addChild(firstRow);
		return node;
	}
	auto fleet = Sprite::create();
	node->addChild(fleet);
	fleet->setPosition(-160,0);
	if (info->currentFleet == 0)
		fleet->setTexture("commonAssets/image 70.png");
	else if (info->currentFleet == 1)
		fleet->setTexture("commonAssets/image 79.png");
	else if (info->currentFleet == 2)
		fleet->setTexture("commonAssets/image 91.png");
	else if (info->currentFleet == 3)
		fleet->setTexture("commonAssets/image 98.png");

	std::string type = Helper::getShipType(info->type);

	
	auto name = Label::create(type+"  "+info->nameCH, "fonts/DengXian.ttf", 13);
	name->setAlignment(TextHAlignment::LEFT);
	name->setPosition(-135, 0);
	name->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	name->setColor(fcolor);
	auto level = Label::create(Helper::int2str(info->level), "fonts/DengXian.ttf", 13);
	level->setPosition(32, 0);
	level->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
	level->setColor(fcolor);
	auto maxHP = Label::create(Helper::int2str(info->maxHP), "fonts/DengXian.ttf", 13);
	maxHP->setPosition(70, 0);
	maxHP->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
	maxHP->setColor(fcolor);
	auto firePower = Label::create(Helper::int2str(info->firePower), "fonts/DengXian.ttf", 13);
	firePower->setPosition(105, 0);
	firePower->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
	firePower->setColor(fcolor);
	auto torpedo = Label::create(Helper::int2str(info->torpedo), "fonts/DengXian.ttf", 13);
	torpedo->setPosition(135, 0);
	torpedo->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
	torpedo->setColor(fcolor);
	auto antiaircraft = Label::create(Helper::int2str(info->antiaircraft), "fonts/DengXian.ttf", 13);
	antiaircraft->setPosition(165, 0);
	antiaircraft->setAnchorPoint(Point::ANCHOR_MIDDLE_RIGHT);
	antiaircraft->setColor(fcolor);

	auto speed = Sprite::create();
	speed->setPosition(189, 2);

	if (info->speed == high)
		speed->setTexture("commonAssets/image 283.png");
	else
		speed->setTexture("commonAssets/image 281.png");

	node->addChild(name);
	node->addChild(level);
	node->addChild(maxHP);
	node->addChild(firePower);
	node->addChild(torpedo);
	node->addChild(antiaircraft);
	node->addChild(speed);

	return node;
	
}
void CharacterListPage::moveOut()
{
	if (!Hidden)
	{
		this->runAction(MoveBy::create(0.2, ccp(800, 0)));
		Hidden = true;
	}

}
void CharacterListPage::moveIn()
{
	if (Hidden)
	{
		this->runAction(MoveBy::create(0.2, ccp(-800, 0)));
		Hidden = false;
	}
}
void CharacterListPage::sortButtonCallback(Ref* pSender)
{

}
void CharacterListPage::exchangeCallback(Ref* pSender, int indexInList)
{
	GameModel::getInstance()->getFleet(0)->switchShip(displayingCharacters[indexInList], parent->getSelectedShipIndex());
	this->updateList(currentPage);
	this->moveOut();
	parent->updateContainers();
}