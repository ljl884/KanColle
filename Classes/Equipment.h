#ifndef _EQUIPMENT_
#define _EQUIPMENT_

#include "cocos2d.h"

using namespace cocos2d;
enum Equipment_Type
{
	no_equipment,	//无装备
	unavailable, //未开启
	small_cannon, //小口径主炮
	mid_cannon, //中口径主炮
	large_cannon, //大口径主炮
	secondary_cannon,    //副炮
	air_defense_artillery, //防空炮
	shell, //炮弹
	torpedo, //鱼雷
	fighter, //舰战
	attacker, //舰攻
	bomber, //舰爆
	scout, //舰侦
	seaplane, //水上飞机
	radio_detector, //电探
	water_detecter, //水中探测仪
	cast_machine, //爆雷投射机
	other 

};
enum Shooting_Range{
	range_long,
	range_mid,
	range_short,
	range_exlong,
	range_non
};
class Equipment{
public:
	Equipment();
	Equipment_Type type;
	std::string id;
	int inGameId;
	std::string nameCH;
	
	//param
	int firePower;
	int torpedo;
	int bomb;
	int antiaircraft;
	int antisubmarine;
	int scout;
	int hitRate;
	int agility;
	Shooting_Range range;

	//get resource
	std::string getIcon();
	std::string getCard();
	std::string getLabel();
	std::string getItemUp();
	std::string getItemDown();
	std::string getStatusTop();


};

#endif