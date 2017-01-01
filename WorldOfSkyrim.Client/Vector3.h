#pragma once
#include "pluginUtils.h"

class Vector3 {

public :
	Vector3(float x=0, float y=0, float z=0) : x(x),y(y),z(z)
	{}

	float x;
	float y;
	float z;
	
	std::string ToJson() 
	{
		return"{\\\"x\\\":"+ std::to_string(x) +",\\\"y\\\":" + std::to_string(y) + ",\\\"z\\\":" + std::to_string(z) + "}";
	}
};