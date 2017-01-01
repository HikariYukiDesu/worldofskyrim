#include "pluginUtils.h"

std::string authorizeRequest::buildRequest(std::string nick, Vector3 position, Vector3 rotation) {
	return  "{\"messageType\":1,\"message\":\"{\\\"Nick\\\":\\\"" + nick + "\\\",\\\"Transform\\\":{\\\"Location\\\":" + position.ToJson() + ",\\\"Rotation\\\":" + rotation.ToJson() + "}}\"}";
}
