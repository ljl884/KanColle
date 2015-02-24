#ifndef _BATTLE_MODEL_
#define _BATTLE_MODEL_

#include "cocos2d.h"
#include "CharacterInfo.h"
#include "XMLParser.h"
#include "GameModel.h"	

using namespace cocos2d;
enum FormationType{
	DanZong = 1,
	FuZong = 2,
	LunXing = 3,
	TiXing = 4,
	DanHeng = 5
};
enum Attack_Type{
	dayBattle,
	nightBattle,
	antiSubmarine,

};
enum T_Word
{
	TongHang,
	FanHang,
	TYouLi,
	TBuLi
};
enum Air_Control{
	full, //�ƿ�Ȩȷ��
	advantage, //��������
	balanced, //����
	lost //�ƿ�Ȩɥʧ
};

class BattleModel{
public:
	BattleModel();
	BattleModel(Fleet* allies, Fleet* enemy, FormationType alliesFormation, FormationType enemyFormation);
	//����

	//����ս
	inline Air_Control getAirControl(){ return airControl; }

	//֧Ԯ����

	//��Ļ�׻�

	//�ڻ�ս
	void resetFireBattle();
	int getNextAlliesIndexToFire();
	int getNextEnemyIndexToFire();
	void getFireDamage(bool alliesAttack, int alliesIndex, int enemyIndex, bool &doubleHit, bool &specialAttack, bool &ci, int &damage, bool &critical,bool &miss);
	bool douldeHitTriggered(CharacterInfo *acttacker);  //�Ƿ񴥷�����
	bool specialAttackTriggered(CharacterInfo *acttacker);	//�Ƿ񴥷����⹥��
	bool cutinTriggered(CharacterInfo *acttacker); //�Ƿ񴥷�CI
	

	inline std::vector<CharacterInfo*> getAllies(){ return allies; }
	inline std::vector<CharacterInfo*> getEnemies(){ return enemy; }
	inline void setAlliesFormation(FormationType formation){ alliesFormation = formation; }
	inline void setEnemyFormation(FormationType formation){ enemyFormation = formation; }
	inline FormationType getAlliesFormation(){ return alliesFormation; }
	inline FormationType getEnemyFormation(){ return enemyFormation; }
	inline void setTWord(T_Word tword){ this->tword = tword; }
	inline T_Word getTWord(){ return tword; }
private:
	std::vector<CharacterInfo*> allies;
	std::vector<CharacterInfo*> enemy;
	FormationType alliesFormation;
	FormationType enemyFormation;
	Air_Control airControl;
	T_Word tword;

	//���˺���ʽ �˺�=[��������(����������*����ǰ����)*���޺���-��װ��*����]*��ҩ������
	int getDamage(Attack_Type attacktype,float basicAttack,int enemyArmour,float preCorrection, float postCorrection, float AmmoCorrection);
	
	//���������޲���
	float getDamageAfterMaxCorrection(float damage, Attack_Type type);
	//�˺����� ���س˷�ϵ��
	float formationCorrection(FormationType type,bool antiSubmarine); //���Ͳ��� 
	float TWordCorrection(T_Word t);//T�ֲ���
	float brokenCorrection(BrokenType type);//������
	float ammoCorrection();//�е�����  TODO

	float postCorrection();//

	int temp;
	int temp1;
};
#endif