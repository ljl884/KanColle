#include"formation.h"

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
		break;
	case LunXing:
		lunxing();
		break;
	case TiXing:
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
void Formation::danheng(){
	danzong();
	for (int i = 0; i < points.size(); i++){
		int x = points[i]->getPosition().x;
		int y = points[i]->getPosition().y;
		points[i]->setPosition(y, x);
	}
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