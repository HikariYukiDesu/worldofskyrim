#pragma once
#include "pluginUtils.h"

class npcDataMiner {
public:
	static std::set<std::string> npcDataMiner::checkedNpcIds;
	static void LookupNewData();
};