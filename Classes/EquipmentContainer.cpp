#include "EquipmentContainer.h"

EquipmentContainer::EquipmentContainer()
{
	initContainer();
}
EquipmentContainer::EquipmentContainer(Equipment* equipment)
{
	initContainer();
	updateEquipment(equipment);
}
void EquipmentContainer::updateEquipment(Equipment* equipment)
{
	if (equipment == nullptr )
	{
		border->setVisible(false);
		label->setVisible(false);
		icon->setVisible(false);
	}
	else if (equipment->type == Equipment_Type::unavailable)
	{
		border->setVisible(false);
		label->setVisible(false);
		icon->setVisible(false);
	}
	else if (equipment->type == Equipment_Type::no_equipment)
	{
		border->setVisible(true);
		label->setVisible(false);
		icon->setVisible(false);
	}
	else
	{
		border->setVisible(true);
		label->setVisible(true);
		icon->setVisible(true);

		label->setString(equipment->nameCH);
		icon->setTexture(equipment->getIcon());
	}
}
void EquipmentContainer::initContainer()
{
	auto empty = Sprite::create("commonAssets/image 249.png");
	this->addChild(empty);
	border = Sprite::create("commonAssets/image 262.png");
	this->addChild(border);
	label = Label::create("", "fonts/DengXian.ttf", 15);
	this->addChild(label);
	label->setAnchorPoint(Point::ANCHOR_MIDDLE_LEFT);
	label->setColor(Color3B(54, 36, 11));
	label->setPosition(-65, 0);
	icon = Sprite::create();
	icon->setPosition(-83, 0);
	this->addChild(icon);
	border->setVisible(false);
	label->setVisible(false);
	icon->setVisible(false);
}