#ifndef _CHARACTER_INFO_
#define _CHARACTER_INFO_
#include "cocos2d.h"
enum Ship_Speed{
	high,
	low
};
enum Shooting_Range{
	range_long,
	range_mid,
	range_short,
	range_exlong
};
enum Ship_Type{
	DD,//驱逐
	CL,//轻巡洋舰
	CA,//重巡洋舰
	CLT,//重雷装巡洋舰
	CAV,//航空巡洋舰
	BB,//战列舰
	CV,//正规航母
	CVL,//轻航母
	AV,//水上机母
	SS,//潜艇
	SSV,//潜母
	SUP//补给舰

};
class Equipment;
enum BrokenType
{
	normal,
	tiny,
	mid,
	large,
	drown
};
class CharacterInfo{
public:

	static CharacterInfo* makeDefaultInfo();
	static CharacterInfo* makeDefaultInfo(std::string resource);
	static CharacterInfo* makeDefaultEnemyInfo();
	std::string id;
	std::string name;
	std::string nameCH; //chinese character name
	std::string resourceFolder;
	Ship_Type type;
	BrokenType brokenType;
	int level; 
	int maxHP;//耐久
	int currentHP;
	int HP;
	int firePower;//火力
	int armour;//装甲
	int torpedo;//雷装
	int agility;//回避
	int antiaircraft;//对空
	int capacity;//搭载
	int antisubmarine;//对潜
	Ship_Speed speed;//速力
	int scout;//索敌
	Shooting_Range range;//射程
	int luck;//运

	int fuelConsume; //燃料消耗
	int ammoConsume; //弹药消耗
	int steelConsume; //钢材消耗

	std::string nextId;//下一改造id


	Equipment *equipment1;
	Equipment *equipment2;
	Equipment *equipment3;
	Equipment *equipment4;
	
};
#endif