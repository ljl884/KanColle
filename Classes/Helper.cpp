#include "Helper.h"
#include "CharacterInfo.h"

std::string Helper::int2str(int i) {
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
std::string Helper::getMissionId(int areaId, int index)
{
	int realIndex = index + 1;
	std::string id = int2str(areaId) + "-" + int2str(realIndex);
	return id;
}
void Helper::split(const std::string& src, const std::string& separator, std::vector<std::string>& dest)
{
	std::string str = src;
	std::string substring;
	std::string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != std::string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == std::string::npos) return;
		}
	} while (index != std::string::npos);

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}