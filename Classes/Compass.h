#ifndef _COMPASS_
#define _COMPASS_

#include "cocos2d.h"
using namespace cocos2d;

enum Compass_Direction
{
	compass_N,
	compass_NE,
	compass_E,
	compass_SE,
	compass_S,
	compass_SW,
	compass_W,
	compass_NW
};
class Compass :public Node{
public:
	Compass();
	static Compass_Direction parseDirection(std::string direction);
	
private:
	Compass_Direction currentDirection;
	Sprite * pointer;
	Sprite * body;
};

#endif //_COMPASS_