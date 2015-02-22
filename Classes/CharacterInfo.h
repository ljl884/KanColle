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
	DD,//����
	CL,//��Ѳ��
	CA,//��Ѳ��
	CLT,//����װѲ��
	CAV,//����Ѳ��
	BB,//ս�н�
	CV,//���溽ĸ
	CVL,//�ẽĸ
	AV,//ˮ�ϻ�ĸ
	SS,//Ǳͧ
	SSV,//Ǳĸ
	SUP//������

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
	int maxHP;//�;�
	int currentHP;
	int HP;
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

	int fuelConsume; //ȼ������
	int ammoConsume; //��ҩ����
	int steelConsume; //�ֲ�����

	std::string nextId;//��һ����id


	Equipment *equipment1;
	Equipment *equipment2;
	Equipment *equipment3;
	Equipment *equipment4;
	
};
#endif