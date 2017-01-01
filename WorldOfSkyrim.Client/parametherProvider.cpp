#include "pluginUtils.h"

Vector3 parametherProvider::GetPlayerPosition()
{
	auto player = reinterpret_cast<TESObjectREFR*>(Game::GetPlayer());

	return Vector3(ObjectReference::GetPositionX(player), ObjectReference::GetPositionY(player), ObjectReference::GetPositionZ(player));
}

Vector3 parametherProvider::GetPlayerRotation()
{
	auto player = reinterpret_cast<TESObjectREFR*>(Game::GetPlayer());

	return Vector3(ObjectReference::GetAngleX(player), ObjectReference::GetAngleY(player), ObjectReference::GetAngleZ(player));
}

Vector3 parametherProvider::GetPosition(TESObjectREFR * object)
{
	return Vector3(ObjectReference::GetPositionX(object), ObjectReference::GetPositionY(object), ObjectReference::GetPositionZ(object));
}

Vector3 parametherProvider::GetRotation(TESObjectREFR * object)
{
	return Vector3(ObjectReference::GetAngleX(object), ObjectReference::GetAngleY(object), ObjectReference::GetAngleZ(object));
}