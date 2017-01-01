#pragma once

#include "pluginUtils.h"

class skyscriptHelper {
public:
	static	CActor * FindClosestActor(Vector3 position, float afRadius);
	static CActor * FindRandomActor(Vector3 position, float afRadius);
};