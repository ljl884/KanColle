#ifndef _EQUIPMENT_
#define _EQUIPMENT_

#include "cocos2d.h"

using namespace cocos2d;
enum Equipment_Type
{
	no_equipment,	//��װ��
	unavailable, //δ����
	small_cannon, //С�ھ�����
	mid_cannon, //�пھ�����
	large_cannon, //��ھ�����
	secondary_cannon,    //����
	air_defense_artillery, //������
	shell, //�ڵ�
	torpedo, //����
	fighter, //��ս
	attacker, //����
	bomber, //����
	scout, //����
	seaplane, //ˮ�Ϸɻ�
	radio_detector, //��̽
	water_detecter, //ˮ��̽����
	cast_machine, //����Ͷ���
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