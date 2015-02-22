#ifndef _HELPER_
#define _HELPER_

#include "cocos2d.h"

class Helper{
public:
	static std::string int2str(int &i) {
		std::string s;
		std::stringstream ss(s);
		ss << i;

		return ss.str();
	}
};

#endif