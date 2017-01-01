#pragma once
#include "pluginUtils.h"

class parametherProvider
{
public:
	static Vector3 GetPlayerPosition();

	static Vector3 GetPlayerRotation();

	static Vector3 GetPosition(TESObjectREFR* object);
	static Vector3 GetRotation(TESObjectREFR* object);

};