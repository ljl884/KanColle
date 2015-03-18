#include "MissionContainer.h"

//TODO Can be done by XML
MissionContainer::MissionContainer(int areaId, int index)
{
	image = Sprite::create();
	this->addChild(image);
	updateContainer(areaId, index);
		
}
void MissionContainer::updateContainer(int areaId, int index)
{
	if (areaId == 1)
	{
		if (index == 0)
			image->setTexture("SallyMain/image 414.png");
		else if (index == 1)
			image->setTexture("SallyMain/image 416.png");
		else if (index == 2)
			image->setTexture("SallyMain/image 418.png");
		else if (index == 3)
			image->setTexture("SallyMain/image 420.png");
	}
	else if (areaId == 2)
	{
		if (index == 0)
			image->setTexture("SallyMain/image 427.png");
		else if (index == 1)
			image->setTexture("SallyMain/image 429.png");
		else if (index == 2)
			image->setTexture("SallyMain/image 431.png");
		else if (index == 3)
			image->setTexture("SallyMain/image 433.png");
	}
	else if (areaId == 3)
	{
		if (index == 0)
			image->setTexture("SallyMain/image 437.png");
		else if (index == 1)
			image->setTexture("SallyMain/image 439.png");
		else if (index == 2)
			image->setTexture("SallyMain/image 441.png");
		else if (index == 3)
			image->setTexture("SallyMain/image 443.png");
	}
	else if (areaId == 4)
	{
		if (index == 0)
			image->setTexture("SallyMain/image 447.png");
		else if (index == 1)
			image->setTexture("SallyMain/image 449.png");
		else if (index == 2)
			image->setTexture("SallyMain/image 451.png");
		else if (index == 3)
			image->setTexture("SallyMain/image 453.png");
	}
	else if (areaId == 5)
	{
		if (index == 0)
			image->setTexture("SallyMain/image 455.png");
		else if (index == 1)
			image->setTexture("SallyMain/image 457.png");
		else if (index == 2)
			image->setTexture("SallyMain/image 459.png");
		else if (index == 3)
			image->setTexture("SallyMain/image 461.png");
	}
	else if (areaId == 6)
	{
		if (index == 0)
			image->setTexture("SallyMain/image 465.png");
		else if (index == 1)
			image->setTexture("SallyMain/image 467.png");
		else if (index == 2)
			image->setTexture("SallyMain/image 412.png");
		else if (index == 3)
			image->setTexture("SallyMain/image 412.png");
	}
}