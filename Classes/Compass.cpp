#include "Compass.h"

Compass::Compass()
{
	body = Sprite::create("SallyMain/image 964.png");
	pointer = Sprite::create("SallyMain/image 967.png");
	this->addChild(body);
	this->addChild(pointer);

	pointer->runAction(RepeatForever::create((ActionInterval*)Sequence::create(
		RotateBy::create(0.15,5),
		RotateBy::create(0.12,-8),
		RotateBy::create(0.08,6),
		RotateBy::create(0.18,-9),
		RotateBy::create(0.21, 6),
		NULL)));
}
Compass_Direction Compass::parseDirection(std::string direction)
{
	if (direction == "N")
		return compass_N;
	else if (direction == "S")
		return compass_S;
	else if (direction == "W")
		return compass_W;
	else if (direction == "E")
		return compass_E;
	else if (direction == "NE")
		return compass_NE;
	else if (direction == "SE")
		return compass_SE;
	else if (direction == "NW")
		return compass_NW;
	else if (direction == "SW")
		return compass_SW;
}