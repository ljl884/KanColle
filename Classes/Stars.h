#ifndef _STARS_
#define _STARS_

#include "cocos2d.h"
#define MAX_STARS_NUMBER 5
using namespace cocos2d;

class Stars:public Node{
public:
	Stars();
	void setNumber(int number);
private:
	std::vector<Sprite*> stars;
};

#endif