#include "pluginUtils.h"

std::map<std::string, TESObjectREFR*> npcRepository::registered;
void npcRepository::SpawnOrUpdate(std::string nick, Vector3 position, Vector3 rotation){
	auto it = registered.find(nick);
	if (it != registered.end())
	{
		auto actor = it->second;
		ObjectReference::TranslateTo(actor, position.x, position.y, position.z, rotation.x, rotation.y, rotation.z, 250, 250);
	}
	else
	{
		CActor* actor = nullptr;
		if (nick.find("0x0") != std::string::npos)
		{
			uint locationId = std::stoul(nick, nullptr, 16);
			actor = ObjectReference::PlaceActorAtMe((TESObjectREFR*)Game::GetPlayer(), (TESNPC *)Game::GetFormById(locationId), 0, nullptr);

			uint npcId = Form::GetFormID((TESForm*)actor);
			auto npcIdStr = std::to_string(npcId);
			npcDataMiner::checkedNpcIds.emplace(npcIdStr);

			ObjectReference::SetPosition((TESObjectREFR *)actor, position.x, position.y, position.z);
			ObjectReference::SetAngle((TESObjectREFR *)actor, rotation.x, rotation.y, rotation.z);
			registered.emplace(nick, (TESObjectREFR*)actor);
		}
		else {
			actor = ObjectReference::PlaceActorAtMe((TESObjectREFR*)Game::GetPlayer(), (TESNPC *)Game::GetFormById(ID_TESNPC::ArgonianFemalePreset01), 0, nullptr);

			uint npcId = Form::GetFormID((TESForm*)actor);
			auto npcIdStr = std::to_string(npcId);
			npcDataMiner::checkedNpcIds.emplace(npcIdStr);

			ObjectReference::SetPosition((TESObjectREFR *)actor, position.x, position.y, position.z);
			ObjectReference::SetAngle((TESObjectREFR *)actor, rotation.x, rotation.y, rotation.z);
			registered.emplace(nick, (TESObjectREFR*)actor);
		}
	}
}