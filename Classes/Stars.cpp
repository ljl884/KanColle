#include "Stars.h"

Stars::Stars()
{
	for (int i = 0; i < MAX_STARS_NUMBER; i++)
	{
		stars.push_back(Sprite::create("commonAssets/image 213.png"));
		stars[i]->setVisible(false);
		stars[i]->setPosition(i * 15, 0);
		this->addChild(stars[i]);
	}
}
void Stars::setNumber(int number)
{
	if (number>5 || number < 0)
		return;
	for (int i = 0; i < number; i++)
		stars[i]->setVisible(true);
} 