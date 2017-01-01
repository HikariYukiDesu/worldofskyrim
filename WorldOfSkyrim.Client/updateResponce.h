#pragma once
#include "pluginUtils.h"

class updateResponce {
public:
	updateResponce(Vector3 position, Vector3 rotation, std::string nick);
	Vector3 position;
	Vector3 rotation;
	std::string nick;
};
