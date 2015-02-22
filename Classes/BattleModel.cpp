#include "BattleModel.h"

BattleModel::BattleModel()
{
	
  CharacterInfo *info = XMLParser::getInstance()->loadCharacterInfo("JiaHeGai");
	this->allies.push_back(info);
	CharacterInfo *info2 = XMLParser::getInstance()->loadCharacterInfo("NaKe");
	this->allies.push_back(info2);
	CharacterInfo *info3 = XMLParser::getInstance()->loadCharacterInfo("Yi19");
	this->allies.push_back(info3);
	CharacterInfo *info4 = XMLParser::getInstance()->loadCharacterInfo("XiLiGai2");
	this->allies.push_back(info4);
	CharacterInfo *info5 = XMLParser::getInstance()->loadCharacterInfo("AiDang");
	this->allies.push_back(info5);
	CharacterInfo *info6 = XMLParser::getInstance()->loadCharacterInfo("ChuiXue");
	this->allies.push_back(info6);  
	
	CharacterInfo *einfo = XMLParser::getInstance()->loadCharacterInfo("BeiFangQiJi");
	this->enemy.push_back(einfo);
	CharacterInfo *einfo2 = XMLParser::getInstance()->loadCharacterInfo("RU");
	this->enemy.push_back(einfo2);
	CharacterInfo *einfo3 = XMLParser::getInstance()->loadCharacterInfo("RU");
	this->enemy.push_back(einfo3);
	CharacterInfo *einfo4 = XMLParser::getInstance()->loadCharacterInfo("RU");
	this->enemy.push_back(einfo4);
	CharacterInfo *einfo5 = XMLParser::getInstance()->loadCharacterInfo("RU");
	this->enemy.push_back(einfo5);
	CharacterInfo *einfo6 = XMLParser::getInstance()->loadCharacterInfo("RU");
	this->enemy.push_back(einfo6);
	
	/*
	CharacterInfo *info = CharacterInfo::makeDefaultInfo("278JIAHEGAI");
	this->allies.push_back(info);
	CharacterInfo *info2 = CharacterInfo::makeDefaultInfo("003NAKE");
	this->allies.push_back(info2);
	CharacterInfo *info3 = CharacterInfo::makeDefaultInfo("191YI19");
	this->allies.push_back(info3);
	CharacterInfo *info4 = CharacterInfo::makeDefaultInfo("144XILIGAIER");
	this->allies.push_back(info4);
	CharacterInfo *info5 = CharacterInfo::makeDefaultInfo("067AIDANG");
	this->allies.push_back(info5);
	CharacterInfo *info6 = CharacterInfo::makeDefaultInfo("009CHUIXUE");
	this->allies.push_back(info6);
	
	CharacterInfo *einfo = CharacterInfo::makeDefaultEnemyInfo();
	this->enemy.push_back(einfo);
	CharacterInfo *einfo2 = CharacterInfo::makeDefaultEnemyInfo();
	this->enemy.push_back(einfo2);
	CharacterInfo *einfo3 = CharacterInfo::makeDefaultEnemyInfo();
	this->enemy.push_back(einfo3);
	CharacterInfo *einfo4 = CharacterInfo::makeDefaultEnemyInfo();
	this->enemy.push_back(einfo4);
	CharacterInfo *einfo5 = CharacterInfo::makeDefaultEnemyInfo();
	this->enemy.push_back(einfo5);
	CharacterInfo *einfo6 = CharacterInfo::makeDefaultEnemyInfo();
	this->enemy.push_back(einfo6);
	*/
	alliesFormation = DanZong;
	enemyFormation = LunXing;
	tword = FanHang;
	resetFireBattle();
}
void BattleModel::resetFireBattle(){
	temp = 0;
	temp1 = 0;
}
int BattleModel::getNextAlliesIndexToFire()
{
	if (temp == 0)
	{
		temp = 1;
		return 3;
	}
	if (temp == 1)
	{
		temp = 2;
		return 5;
	}
	if (temp == 2)
	{
		temp = 3;
		return 2;
	}
	if (temp == 3)
	{
		temp = 4;
		return 1;
	}
	if (temp == 4)
	{
		temp = 5;
		return 0;
	}
	if (temp == 5)
	{
		temp = -1;
		return 4;
	}
	return temp;
}
int BattleModel::getNextEnemyIndexToFire()
{
	if (temp1 == 0)
	{
		temp1 = 1;
		return 5;
	}
	if (temp1 == 1)
	{
		temp1 = 2;
		return 1;
	}
	if (temp1 == 2)
	{
		temp1 = 3;
		return 0;
	}
	if (temp1 == 3)
	{
		temp1 = 4;
		return 3;
	}
	if (temp1 == 4)
	{
		temp1 = 5;
		return 4;
	}
	if (temp1 == 5)
	{
		temp1 = -1;
		return 2;
	}
	return temp1;
}
void BattleModel::getFireDamage(bool alliesAttack, int alliesIndex, int enemyIndex, bool &doubleHit, bool &specialAttack, bool &ci,int &damage, bool &critical,bool &miss)
{
	Attack_Type attackType = dayBattle;
	CharacterInfo *attacker;
	CharacterInfo *attacked;
	FormationType formation;
	if (alliesAttack){
		attacker = allies[alliesIndex];
		attacked = enemy[enemyIndex];
		formation = alliesFormation;
	}
	else
	{
		attacked = allies[alliesIndex];
		attacker = enemy[enemyIndex];
		formation = enemyFormation;
	}
	
	bool antiSubmarine = false;
	if (attacked->type == SS || attacked->type == SSV)
	{
		antiSubmarine = true;
		attackType = Attack_Type::antiSubmarine;
	}
		
	//命中
	float hit = CCRANDOM_0_1();
	miss = false;
	if (hit < 0.2)
	{
		miss = true;
		return;
	}


	float basicAttack=0;
	if (attacker->type == CV || attacker->type == CVL) //基本攻击力=火力*1.5+雷装*1.5+爆装*2+55
	{
		int bomb = 0;//TODO
		basicAttack = (attacker->firePower + attacker->torpedo)*1.5 + bomb * 2 + 55; //
	}
	else //基本攻击力=火力+5
	{
		basicAttack = attacker->firePower + 5;
	}
	float preCorrection = 1;
	preCorrection = preCorrection*formationCorrection(formation, antiSubmarine);
	preCorrection = preCorrection*TWordCorrection(tword);
	preCorrection = preCorrection*brokenCorrection(attacker->brokenType);

	float postCorrection = 1;
	//暴击
	float randomCritical = CCRANDOM_0_1();
	critical = false;
	if (randomCritical < 0.15)
	{
		critical = true;
		postCorrection = 1.5;
	}
	doubleHit = douldeHitTriggered(attacker);
	specialAttack = specialAttackTriggered(attacker);
	ci = cutinTriggered(attacker);
	if (doubleHit)
	{ }
	if (specialAttack)
	{ }
	if (ci)
	{	}
	


	damage = getDamage(attackType, basicAttack, attacked->armour, preCorrection, postCorrection, ammoCorrection());
	
	//击沉保护
	if (!alliesAttack && damage >= attacked->currentHP)
	{
		float random = CCRANDOM_0_1()*(0.3) + 0.5; //0.5~0.8
		damage = attacked->currentHP*random;
	}

	//擦伤
	if (!miss && damage < 0)
	{
		float random = CCRANDOM_0_1()*(0.08) + 0.06; //   0.06~0.14
		damage = random*attacked->currentHP;
	}

	//纠正显示
	if (0 < damage < 1)
		miss = true;
	if (damage >= 40)
		critical = true;
	if (damage < 13)
		critical = false;

	attacked->currentHP -= damage;

	
		
}
bool BattleModel::douldeHitTriggered(CharacterInfo *acttacker)
{
	return false;
}
bool BattleModel::specialAttackTriggered(CharacterInfo *acttacker)
{
	return false;
}
bool BattleModel::cutinTriggered(CharacterInfo *acttacker)
{
	return false;
}
int BattleModel::getDamage(Attack_Type attacktype,float basicAttack, int enemyArmour, float preCorrection, float postCorrection, float AmmoCorrection)
{
	float damage = basicAttack* preCorrection;
	damage = getDamageAfterMaxCorrection(damage,attacktype);
	damage = damage*postCorrection;
	float random = CCRANDOM_0_1()*(2 / 3) + 2 / 3; //   2/3~4/3
	damage = damage - random*enemyArmour;
	damage = damage*AmmoCorrection;

	return damage;
}
float BattleModel::getDamageAfterMaxCorrection(float damage, Attack_Type type)
{
	float maxDamage=150;
	switch (type)
	{
	case nightBattle:
		maxDamage = 300;
		break;
	case antiSubmarine:
		maxDamage = 100;
		break;
	default:
		break;
	}
	if (damage > maxDamage)
	{
		damage = sqrtf(damage - maxDamage) + maxDamage;
	}
	return damage;
}
float BattleModel::formationCorrection(FormationType type, bool antiSubmarine)
{
	switch (type)
	{
	case DanZong:
		if (antiSubmarine)
			return 0.45;
		return 1;
		break;
	case FuZong:
		if (antiSubmarine)
			return 0.6;
		return 0.8;
		break;
	case LunXing:
		if (antiSubmarine)
			return 0.9;
		return 0.7;
		break;
	case TiXing:
		if (antiSubmarine)
			return 0.75;
		return 0.6;
		break;
	case DanHeng:
		if (antiSubmarine)
			return 1;
		return 0.6;
		break;
	default:
		break;
	}
}
float BattleModel::TWordCorrection(T_Word t)
{
	switch (t)
	{
	case T_Word::TongHang:
		return 1;
		break;
	case T_Word::FanHang:
		return 0.8;
		break;
	case T_Word::TYouLi:
		return 1.2;
		break;
	case T_Word::TBuLi:
		return 0.6;
		break;
	default:
		break;
	}
}
float BattleModel::brokenCorrection(BrokenType type)
{
	switch (type)
	{
	case BrokenType::normal:
		return 1;
		break;
	case BrokenType::tiny:
		return 1;
		break;
	case BrokenType::mid:
		return 0.7;
		break;
	case BrokenType::large:
		return 0.4;
		break;
	case BrokenType::drown:
		return 0;
		break;
	default:
		break;
	}
}
float BattleModel::ammoCorrection()
{
	return 1;
}