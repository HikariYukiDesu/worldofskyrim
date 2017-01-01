#pragma once
#include "pluginUtils.h"

class stringHelper {
	static void split(const std::string & s, std::string delim, std::vector<std::string>& elems);
	static void easysplit(const std::string & s, char delim, std::vector<std::string>& elems);
public:
	static std::vector<std::string> split(const std::string &s, char delim[]);
	static std::vector<std::string> easysplit(const std::string &s, char delim);
};