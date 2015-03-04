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
	DD,//����
	CL,//��Ѳ��
	CA,//��Ѳ��
	CLT,//����װѲ��
	CAV,//����Ѳ��
	BB,//ս�н�
	BBCV,//����ս�н�
	CV,//���溽ĸ
	CVA,//װ�׿�ĸ
	CVL,//�ẽĸ
	AV,//ˮ�ϻ�ĸ
	SS,//Ǳͧ
	SSV,//Ǳĸ
	SUP//������

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
	int inGameId; //����ʱ��GameModel���� ��ϷΨһ

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
	int maxHP;//�;�
	int currentHP;
	int star;
	int firePower;//����
	int armour;//װ��
	int torpedo;//��װ
	int agility;//�ر�
	int antiaircraft;//�Կ�
	int capacity;//����
	int antisubmarine;//��Ǳ
	Ship_Speed speed;//����
	int scout;//����
	Shooting_Range range;//���
	int luck;//��
	int bomb;//��װ
	int hitRate;//����

	int fuelConsume; //ȼ������
	int ammoConsume; //��ҩ����
	int steelConsume; //�ֲ�����

	std::string nextId;//��һ����id


	
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