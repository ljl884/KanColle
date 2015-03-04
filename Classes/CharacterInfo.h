#ifndef _CHARACTER_INFO_
#define _CHARACTER_INFO_
#include "cocos2d.h"
#include "Equipment.h"

#define MAX_EQUIPMENT_NUMBER 4
enum Ship_Speed{
	high,
	low
};

enum Ship_Type{
	DD,//驱逐
	CL,//轻巡洋舰
	CA,//重巡洋舰
	CLT,//重雷装巡洋舰
	CAV,//航空巡洋舰
	BB,//战列舰
	BBCV,//航空战列舰
	CV,//正规航母
	CVA,//装甲空母
	CVL,//轻航母
	AV,//水上机母
	SS,//潜艇
	SSV,//潜母
	SUP//补给舰

};

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
	CharacterInfo();
	int inGameId; //创建时由GameModel分配 游戏唯一

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
	int star;
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
	int bomb;//爆装
	int hitRate;//命中

	int fuelConsume; //燃料消耗
	int ammoConsume; //弹药消耗
	int steelConsume; //钢材消耗

	std::string nextId;//下一改造id


	
	std::vector<Equipment*> equipments;
	int currentFleet;

public:
	void addEquipment(Equipment* equipment,int index);
	bool canAttack();
	void getDamage(int damage);
	Equipment* getMainCannon();   
	bool canAirBattle();
	bool getAirCraftId(std::string &plane1, std::string &plane2, std::string plane3);
	
};
#endif