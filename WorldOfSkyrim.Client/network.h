#pragma once
#ifdef _WIN32
#pragma comment( lib, "ws2_32" )
#include <WinSock2.h>
#endif
#include <assert.h>
#include <stdio.h>
#include <memory>
#include "networking/easywsclient.hpp"
#include "pluginUtils.h"

using easywsclient::WebSocket;

class network {
public: 
	static std::queue<std::string> messagesToDispatch;
	static std::queue<std::vector<updateResponce>> messagesToUpdate;
	std::unique_ptr<WebSocket> ws;
	std::thread connectasync(const char* url);
	void send(std::string message);
	void disconnect();

	static bool IsConnected;
};