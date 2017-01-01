#include "pluginUtils.h"

std::set<std::string> npcDataMiner::checkedNpcIds;
void npcDataMiner::LookupNewData()
{
	auto playerPosition = parametherProvider::GetPlayerPosition();
	auto actor = Game::FindRandomActor(playerPosition.x, playerPosition.y, playerPosition.z, 2000);
	uint npcId = Form::GetFormID((TESForm*)actor);
	auto npcIdStr = std::to_string(npcId);
	auto key = checkedNpcIds.find(npcIdStr);

	if (key == checkedNpcIds.end()) {
		checkedNpcIds.emplace(npcIdStr);
		core::net->send(authorizeRequest::buildRequest(npcIdStr, parametherProvider::GetPosition((TESObjectREFR *)actor), parametherProvider::GetRotation((TESObjectREFR *)actor)));
		ObjectReference::Delete((TESObjectREFR*)actor);
	}
}