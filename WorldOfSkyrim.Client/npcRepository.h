#pragma once
#include "pluginUtils.h"

class npcRepository
{
public:
	static std::map<std::string, TESObjectREFR*> registered;
	static void SpawnOrUpdate(std::string nick, Vector3 position, Vector3 rotation);
	//static void RemoveUnregistered();
};	