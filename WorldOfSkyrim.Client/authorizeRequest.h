#pragma once
#include "pluginUtils.h"

class authorizeRequest {
public:
	static std::string buildRequest(std::string nick, Vector3 position, Vector3 rotation);
};