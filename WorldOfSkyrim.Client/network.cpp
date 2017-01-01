#include "network.h"

std::queue<std::string> network::messagesToDispatch;
std::queue<std::vector<updateResponce>> network::messagesToUpdate;
bool network::IsConnected;
std::thread network::connectasync(const char* url)
{
	auto thread = std::thread([&, url]() {
		using easywsclient::WebSocket;
#ifdef _WIN32
		INT rc;
		WSADATA wsaData;

		rc = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (rc) {
			printf("WSAStartup Failed.\n");
		}
#endif
		ws = std::unique_ptr<WebSocket>(WebSocket::from_url(std::string(url)));
		assert(ws);
		
		network::IsConnected = true;
		while (ws->getReadyState() != WebSocket::CLOSED) {
			WebSocket::pointer wsp = &*ws; // <-- because a unique_ptr cannot be copied into a lambda
			ws->poll();
			ws->dispatch([wsp](std::string messages) {
				std::vector<updateResponce> responce;
				auto players = serverResponceParser::GetPlayers(messages);
				
				for each (auto playerJson in players)
				{
					auto nick = serverResponceParser::GetNick(playerJson);
					if (nick == core::Nick) {
						continue;
					}

					auto position = serverResponceParser::GetPosition(playerJson);
					auto rotation = serverResponceParser::GetRotation(playerJson);
					responce.emplace_back(updateResponce(position,rotation,nick));
				}

				network::messagesToUpdate.push(responce);
				if (messages == "world") { wsp->close(); }
			});
		}
#ifdef _WIN32
		WSACleanup();
#endif
	});

	return thread;
}

void network::send(std::string message)
{
	ws->send(message);
}

void network::disconnect()
{
	ws->close();
}
