#ifndef _EQUIPMENT_CONTAINER_
#define _EQUIPMENT_CONTAINER_

#include "cocos2d.h"
#include "Equipment.h"
using namespace cocos2d;

class EquipmentContainer :public Node{
public:
	EquipmentContainer();
	EquipmentContainer(Equipment* equipment);
	void updateEquipment(Equipment* equipment);
private:
	
	void initContainer();
	Sprite* border;
	Sprite* icon;
	Sprite* cross;
	Label* label;
};
#endif