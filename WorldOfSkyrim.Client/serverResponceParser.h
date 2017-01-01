#pragma once
#include "pluginUtils.h"

class serverResponceParser {
public :
	static std::string GetNick(std::string json);
	static Vector3 GetPosition(std::string json);
	static Vector3 GetRotation(std::string json);
	static std::vector<std::string> GetPlayers(std::string json);
};