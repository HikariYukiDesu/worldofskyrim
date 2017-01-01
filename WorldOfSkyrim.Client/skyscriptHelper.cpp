#include "pluginUtils.h"

CActor * skyscriptHelper::FindClosestActor(Vector3 position, float afRadius) {
	return NativeInvoke::Invoke<CActor *>("Game", "FindClosestActor", BSScript_StaticFunctionTag, position.x, position.y, position.z, afRadius);
}

CActor * skyscriptHelper::FindRandomActor(Vector3 position, float afRadius) {
	return NativeInvoke::Invoke<CActor *>("Game", "FindRandomActor", BSScript_StaticFunctionTag, position.x, position.y, position.z, afRadius);
}