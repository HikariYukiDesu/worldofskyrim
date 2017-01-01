#include "pluginUtils.h"

std::string updateRequest::buildRequest(Vector3 position, Vector3 rotation) {
	return "{\"messageType\":2,\"message\":\"{\\\"Transform\\\":{\\\"Location\\\":" + position.ToJson() + ",\\\"Rotation\\\":" + rotation.ToJson() + "}}\"}";
}