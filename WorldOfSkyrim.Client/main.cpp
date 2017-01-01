#include "pluginUtils.h"

int main()
{
	core::Init();
	while (true)
	{
		playerController::HandleInput();
		if (core::net != nullptr) {
			npcDataMiner::LookupNewData();
		}

		serverMessageDispatcher::handleMessages();
		Wait(0);
	}

	return 0;
}