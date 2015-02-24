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
	full, //制空权确保
	advantage, //航空优势
	balanced, //均势
	lost //制空权丧失
};

class BattleModel{
public:
	BattleModel();
	BattleModel(Fleet* allies, Fleet* enemy, FormationType alliesFormation, FormationType enemyFormation);
	//索敌

	//航空战
	inline Air_Control getAirControl(){ return airControl; }

	//支援舰队

	//开幕雷击

	//炮击战
	void resetFireBattle();
	int getNextAlliesIndexToFire();
	int getNextEnemyIndexToFire();
	void getFireDamage(bool alliesAttack, int alliesIndex, int enemyIndex, bool &doubleHit, bool &specialAttack, bool &ci, int &damage, bool &critical,bool &miss);
	bool douldeHitTriggered(CharacterInfo *acttacker);  //是否触发二连
	bool specialAttackTriggered(CharacterInfo *acttacker);	//是否触发特殊攻击
	bool cutinTriggered(CharacterInfo *acttacker); //是否触发CI
	

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

	//总伤害公式 伤害=[上限修正(基本攻击力*上限前补正)*上限后补正-敌装甲*乱数]*弹药量补正
	int getDamage(Attack_Type attacktype,float basicAttack,int enemyArmour,float preCorrection, float postCorrection, float AmmoCorrection);
	
	//攻击力上限补正
	float getDamageAfterMaxCorrection(float damage, Attack_Type type);
	//伤害补正 返回乘法系数
	float formationCorrection(FormationType type,bool antiSubmarine); //阵型补正 
	float TWordCorrection(T_Word t);//T字补正
	float brokenCorrection(BrokenType type);//伤损补正
	float ammoCorrection();//残弹补正  TODO

	float postCorrection();//

	int temp;
	int temp1;
};
#endif