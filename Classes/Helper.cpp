#include "Helper.h"
#include "CharacterInfo.h"

std::string Helper::int2str(int &i) {
	std::string s;
	std::stringstream ss(s);
	ss << i;

	return ss.str();
}
std::string Helper::getString(std::string name){
	return XMLParser::getInstance()->getStringByName(name);
}
std::string Helper::getShipType(Ship_Type type)
{
	switch (type)
	{
	case DD:
		return getString("DD");
		break;
	case CL:
		return getString("CL");
		break;
	case CA:
		return getString("CA");
		break;
	case CLT:
		return getString("CLT");
		break;
	case CAV:
		return getString("CAV");
		break;
	case BB:
		return getString("BB");
		break;
	case CV:
		return getString("CV");
		break;
	case CVA:
		return getString("CVA");
		break;
	case CVL:
		return getString("CVL");
		break;
	case AV:
		return getString("AV");
		break;
	case SS:
		return getString("SS");
		break;
	case SSV:
		return getString("SSV");
		break;
	case SUP:
		return getString("SUP");
		break;
	default:
		return "";
		break;
	}
}