#include"formation.h"
#include "SallyScene.h"
Formation::Formation( FormationType type,SallyScene* parent)
{
	this->type = type;
	
	shipCount = MAX_SHIPS_PER_FLEET;
	for (int i = 0; i < shipCount; i++){
		Sprite *temp = Sprite::create("BattleMain/image 686.png");
		temp->setVisible(false);
		points.push_back(temp);
		this->addChild(temp);
	}
	organizePoints();
	showPoints();
	initializePanel(parent);
	rotatePoints();
}
Formation::Formation(int shipCount, FormationType type)
{
	this->type = type;
	this->shipCount = shipCount;

	for (int i = 0; i < shipCount; i++){
		Sprite *temp = Sprite::create("BattleMain/image 686.png");
		temp->setVisible(false);
		points.push_back(temp);
		this->addChild(temp);
	}
	organizePoints();
}
Formation::Formation(int shipCount, FormationType type, bool isEnemy)
{
	this->type = type;
	this->shipCount = shipCount;
	pointUrl = "BattleMain/image 686.png";
	if (isEnemy)
		pointUrl = "BattleMain/image 688.png";
	for (int i = 0; i < shipCount; i++){
		Sprite *temp = Sprite::create(pointUrl);
		temp->setVisible(false);
		points.push_back(temp);
		this->addChild(temp);
	}
	organizePoints();
}
void Formation::addBattleBorder()
{
	border = Sprite::create("BattleMain/image 372.png");
	this->addChild(border);
}
void Formation::showPoints()
{
	for (int i = 0; i < points.size(); i++)
		points[i]->setVisible(true);
}
void Formation::hidePoints()
{
	for (int i = 0; i < points.size(); i++)
		points[i]->setVisible(false);
}
void Formation::organizePoints(){
	if (shipCount == 1)
		return;
	
	switch (type)
	{
	case DanZong:
		danzong();		
		break;
	case FuZong:
		fuzong();
		break;
	case LunXing:
		lunxing();
		break;
	case TiXing:
		tixing();
		break;
	case DanHeng:
		danheng();
		break;
	default:
		break;
	}
}

void Formation::danzong()
{
	if (0 == (shipCount & 1)) //Å¼Êý
	{
		for (int i = 0, j = 0; i < points.size(); i++)
		{
			int x;

			if ((i & 1) == 0)
				x = -8 - 16 * j;
			else
			{
				x = 8 + 16 * j;
				j++;
			}

			points[i]->setPosition(x, 0);
		}
	}
	else //ÆæÊý
	{
		for (int i = 1, j = 1; i < points.size(); i++)
		{
			int x;

			if ((i & 1) != 0)
				x = -18 * j;
			else
			{
				x = 18 * j;
				j++;
			}

			points[i]->setPosition(x, 0);
		}
	}
}
void Formation::fuzong(){
	if (shipCount < 4)
		return;
	float x = 0;
	if (shipCount > 4)
	{
		x = -10;
		points[4]->setPosition(x + 30, 10);
	}
	if (shipCount == 6)
		points[5]->setPosition(x + 30, -10);
		
	points[0]->setPosition(x+10, 10);
	points[1]->setPosition(x+10, -10);
	points[2]->setPosition(x - 10, 10);
	points[3]->setPosition(x - 10, -10);

}
void Formation::tixing()
{
	if (shipCount < 4)
		return;
	int x = 0, y = 0;
	if (shipCount == 5)
	{
		x = 5; 
		points[4]->setPosition(x - 25, y - 25);
	}
	if (shipCount == 6)
	{
		points[4]->setPosition(x + 25, y + 25);
		points[5]->setPosition(x - 25, y - 25);
	}
	
	points[0]->setPosition(x - 5, y - 5);
	points[1]->setPosition(x + 5, y + 5);
	points[2]->setPosition(x - 15, y - 15);
	points[3]->setPosition(x + 15, y + 15);
}
void Formation::danheng(){
	danzong();
	rotatePoints();
}
void Formation::lunxing(){
	if (shipCount == 6){
		points[0]->setPosition(8, 0);
		points[1]->setPosition(-8, 0);
		points[2]->setPosition(24, 0);
		points[3]->setPosition(-24, 0);
		points[4]->setPosition(0, 20);
		points[5]->setPosition(0, -20);
	}
	else if (shipCount == 5){
		points[0]->setPosition(0, 0);
		points[1]->setPosition(-15, 0);
		points[2]->setPosition(15, 0);
		points[3]->setPosition(0, 15);
		points[4]->setPosition(0, -15);
	}
}
void Formation::rotatePoints()
{
	for (int i = 0; i < points.size(); i++){
		int x = points[i]->getPosition().x;
		int y = points[i]->getPosition().y;
		points[i]->setPosition(y, x);
	}
}
void Formation::initializePanel(SallyScene *parentSallyScene)
{
	this->parentSallyScene = parentSallyScene;
	panelBg = Sprite::create("SallyMain/image 684.png");
	panelBg->setZOrder(-1);
	this->addChild(panelBg);
	panelBg->setPosition(0, -18);
	switch (type)
	{
	case DanZong:
		button = MenuItemImage::create("SallyMain/image 692.png",
			"SallyMain/image 694.png", CC_CALLBACK_1(SallyScene::setFormationCallback, parentSallyScene,DanZong));
		break;
	case FuZong:
		button = MenuItemImage::create("SallyMain/image 697.png",
			"SallyMain/image 699.png", CC_CALLBACK_1(SallyScene::setFormationCallback, parentSallyScene,FuZong));
		break;
	case LunXing:
		button = MenuItemImage::create("SallyMain/image 702.png",
			"SallyMain/image 704.png", CC_CALLBACK_1(SallyScene::setFormationCallback, parentSallyScene,LunXing));
		break;
	case TiXing:
		button = MenuItemImage::create("SallyMain/image 707.png",
			"SallyMain/image 709.png", CC_CALLBACK_1(SallyScene::setFormationCallback, parentSallyScene,TiXing));
		break;
	case DanHeng:
		button = MenuItemImage::create("SallyMain/image 712.png",
			"SallyMain/image 714.png", CC_CALLBACK_1(SallyScene::setFormationCallback, parentSallyScene,DanHeng));
		break;
	default:
		break;
	}
	button->setPosition(0, -67);
	
	auto menu = Menu::create(button, NULL);
	this->addChild(menu);
	menu->setZOrder(1);
	menu->setPosition(Point::ZERO);
}
