#include "BattleModel.h"
#define DEFAULT_HIT_RATE 0.95
BattleModel::BattleModel(Fleet* allies, Fleet* enemy, FormationType alliesFormation, FormationType enemyFormation)
{

	for (int i = 0; i < allies->size(); i++)
		this->allies.push_back(allies->getShip(i));
	for (int i = 0; i < enemy->size(); i++)
		this->enemy.push_back(enemy->getShip(i));

	//CharacterInfo *einfo = XMLParser::getInstance()->loadCharacterInfo("BeiFangQiJi");
	//this->enemy.push_back(einfo);
	//CharacterInfo *einfo2 = XMLParser::getInstance()->loadCharacterInfo("RU");
	//this->enemy.push_back(einfo2);
	//CharacterInfo *einfo3 = XMLParser::getInstance()->loadCharacterInfo("LI");
	//this->enemy.push_back(einfo3);
	//CharacterInfo *einfo4 = XMLParser::getInstance()->loadCharacterInfo("HO");
	//this->enemy.push_back(einfo4);
	//CharacterInfo *einfo5 = XMLParser::getInstance()->loadCharacterInfo("HO");
	//this->enemy.push_back(einfo5);
	//CharacterInfo *einfo6 = XMLParser::getInstance()->loadCharacterInfo("DO");
	//this->enemy.push_back(einfo6);

	this->alliesFormation = alliesFormation;
	this->enemyFormation = enemyFormation;
	tword = FanHang;
	resetFireBattle();

}
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
	
	alliesFormation = DanZong;
	enemyFormation = LunXing;
	tword = FanHang;
	resetFireBattle();
}
void BattleModel::insertToRangeVector(Shooting_Range range, int i)
{
	switch (range)
	{
	case Shooting_Range::range_exlong:
		if (i>10)
			exlongIndex.insert(exlongIndex.begin(), i);
		else
			exlongIndex.insert(exlongIndex.end(), i);
		break;
	case Shooting_Range::range_long:
		if (i>10)
			longIndex.insert(longIndex.begin(), i);
		else
			longIndex.insert(longIndex.end(), i);
		break;
	case Shooting_Range::range_mid:
		if (i>10)
			midIndex.insert(midIndex.begin(), i);
		else
			midIndex.insert(midIndex.end(), i);
		break;
	case Shooting_Range::range_short:
		if (i>10)
			shortIndex.insert(shortIndex.begin(), i);
		else
			shortIndex.insert(shortIndex.end(), i);
		break;
	default:
		break;
	}
}
void BattleModel::resetFireBattle(){
	exlongIndex.clear();
	longIndex.clear();
	midIndex.clear();
	shortIndex.clear();


	for (int i = 0; i < MAX_SHIPS_PER_FLEET; i++)
	{
		if (i < allies.size())
		{
			insertToRangeVector(allies[i]->range, i);
		}
		if (i < enemy.size())
		{
			insertToRangeVector(enemy[i]->range, 10 + i);
		}
	}

}
bool BattleModel::getNextIndexToFire(bool &allies, int &index)
{
	std::vector<int> * vec = &exlongIndex;
	for (int i = 0; i < 4; i++){
		if (!vec->empty())
		{
			if (allies)
			{
				index = vec->front();
				vec->erase(vec->begin());
			}

			else
			{
				index = vec->back();
				vec->pop_back();
			}

			if (index < 10)
				allies = true;
			else
			{
				allies = false;
				index = index - 10;
			}
				
			return true;
		}
		if (i == 0)
			vec = &longIndex;
		if (i == 1)
			vec = &midIndex;
		if (i == 2)
			vec = &shortIndex;
	}
	
	
	return false;
}
int BattleModel::getTargetIndex(bool alliesAttack)
{
	std::vector<int> aliveTargets;
	std::vector<CharacterInfo*> *targets;
	if (alliesAttack)
		targets = &enemy;
	else
		targets = &allies;
	
	for (int i = 0; i < targets->size(); i++)
	{
		if (targets->at(i)->currentHP != 0)
			aliveTargets.push_back(i);
	}
	if (aliveTargets.size() == 0)
		return -1;
	float random = CCRANDOM_0_1()*(float)(aliveTargets.size());
	if (random == aliveTargets.size())
		random -= 1;
	return aliveTargets[(int)random];

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
	if (hit - (float)attacker->hitRate/100 + (float)attacked->agility/100>DEFAULT_HIT_RATE)
	{
		miss = true;
		return;
	}


	float basicAttack=0;
	if (attacker->type == CV || attacker->type == CVL || attacker->type==CVA) //基本攻击力=火力*1.5+雷装*1.5+爆装*2+55
	{
		
		basicAttack = (attacker->firePower + attacker->torpedo)*1.5 + attacker->bomb * 2 + 55; //
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