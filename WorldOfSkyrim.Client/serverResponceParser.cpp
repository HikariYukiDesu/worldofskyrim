#include "serverResponceParser.h"

std::string serverResponceParser::GetNick(std::string json)
{
	//std::string word; //the value 0x001 becomes x001 =C, not working
	//for (auto i = 10; i < 100; i++) {
	//	if (json[i] != '"') {
	//		word.push_back(json[i]);
	//	}
	//	else break;
	//}

	//std::stringstream ss; //the value 0x001 becomes x001 =C, not working
	//ss.str(json);
	//std::string item;
	//std::string elems;
	//while (std::getline(ss, item, '"')) {
	//	elems = item;
	//}
	return stringHelper::split(json, "\"Name\":\"")[3]; //somehow works
}

Vector3 serverResponceParser::GetPosition(std::string json)
{
	float x, y, z;

	int offset = 20;
	for (size_t j = 0; j < 3; j++)
	{
		int counter = 0;
		if (j > 0) {
			counter = counter + 2 + j;
		}
		while (json[offset] != ':' || counter < j + 2)
		{
			if (json[offset] == ':')
			{
				counter++;
			}
			offset++;
		}
		offset++;
		std::string word;
		for (auto i = offset; i < 200; i++)
		{
			if (json[i] != ',' && json[i] != '}') {
				word.push_back(json[i]);
			}
			else {
				switch (j)
				{
				case 0:
					x = std::stof(word);
					break;
				case 1:
					y = std::stof(word);
					break;
				case 2:
					z = std::stof(word);
					break;
				}

				break;
			}
		}
	}

	return Vector3(x, y, z);
}

Vector3 serverResponceParser::GetRotation(std::string json)
{
	float x, y, z;
	int offset = 30;
	for (size_t j = 0; j < 3; j++)
	{
		int counter = 0;
		if (j > 0) {
			counter = counter + 6 + j;
		}
		while ((json[offset] != ':' || counter < j + 6))
		{
			if (json[offset] == ':')
			{
				counter++;
			}
			offset++;
		}
		offset++;
		std::string word;
		for (auto i = offset; i < 300; i++)
		{
			if (json[i] != ',' && json[i] != '}') {
				word.push_back(json[i]);
			}
			else {
				switch (j)
				{
				case 0:
					x = std::stof(word);
					break;
				case 1:
					y = std::stof(word);
					break;
				case 2:
					z = std::stof(word);
					break;
				}

				break;
			}
		}
	}

	return Vector3(x, y, z);
}

std::vector<std::string> serverResponceParser::GetPlayers(std::string json)
{
	auto rerer = stringHelper::split(json, ",");
	std::vector<std::string> players;
	for (size_t j = 0; j < rerer.size() / 7; j++)
	{
		std::string player;
		for (size_t i = 0; i <7; i++)
		{
			player = player + rerer[i+(7*j)];
		}

		players.push_back(player);
	}

	return players;
}
