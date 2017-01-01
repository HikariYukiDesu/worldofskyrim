#include "pluginUtils.h"

void playerController::HandleInput()
{
	if (GetKeyPressed(playerController::key))
	{
		core::net = new network();
		core::net->connectasync("ws://192.168.0.104:9000/ws").detach();
		auto str = authorizeRequest::buildRequest("Ahimas", parametherProvider::GetPlayerPosition(), parametherProvider::GetPlayerRotation());
		core::Nick = "Ahimas";
		Wait(500);
		core::net->send(str);
		
		PrintNote("Connected to 127.0.0.1:9000");
	}
	
	if ((GetKeyPressed(playerController::wKey) || GetKeyPressed(playerController::sKey) || GetKeyPressed(playerController::aKey)) || GetKeyPressed(playerController::dKey) && core::net != nullptr) //TODO! replace with actor movement status check
	{
		core::net->send(updateRequest::buildRequest(parametherProvider::GetPlayerPosition(), parametherProvider::GetPlayerRotation()));
		Wait(200);
	}
}