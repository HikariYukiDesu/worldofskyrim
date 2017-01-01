#pragma once
class network;
class core
{
public:
	static network* net;
	static void Init();
	static std::string Nick;
	static TESObjectREFR* Player;
};