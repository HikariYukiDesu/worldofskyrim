#include "pluginUtils.h";

void serverMessageDispatcher::handleMessages()
{
	if (network::messagesToUpdate.size() > 0)
	{
		auto characters = network::messagesToUpdate.back();
		
		for each (auto character in characters)
		{
			npcRepository::SpawnOrUpdate(character.nick, character.position, character.rotation);
		}

		network::messagesToUpdate.pop();
	}
}


//PrintNote(const_cast<char*>(network::messagesToDispatch.back().data()));