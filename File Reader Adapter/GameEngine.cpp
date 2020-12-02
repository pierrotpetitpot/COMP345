// Author Ebraheem Al Shapi
// Solution Risk
// Project: GameEngine
// Created at 9:04 PM 20/10/2020
// Date: 01/11/2020   7:09 PM
// File Name: GameEngine.cpp

#include "GameEngine.h"
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>
#include "MapLoader.h"
using namespace std;
namespace fs = std::filesystem;

// in order to enable filesystem go to project properties
// in C\C++ section then in language
// 1.Change C++ language standard to  to ISO C++17  Standard
// 2.Enable C++ Modules for STL(experimental) by switching to yes



GameStart::GameStart()
{
}

void GameStart::start_game()
{
	std::cout << "Entering GameStart::start_game()\n" << std::endl;
	
	MapLoader* l;
	const std::string path = "Map files\\";
	int index = 0;
	std::vector<std::string> choices;


	std::cout << "Select a map by typing its number:" << std::endl;
	for (const auto& entry : fs::directory_iterator(path))
	{
		auto map_name = entry.path().u8string();
		if (map_name.find(".map") != std::string::npos)
			{
			std::cout << ++index << "." << map_name << std::endl;
			choices.push_back(map_name);
			}	
	}
	cin >> index;
	if (choices[index - 1].find("(Conquest Map)")!=string::npos)
	{
		ConquestFileReader cfr;
		l = new ConquestFileReaderAdapter(&cfr);
		l->LoadMap(choices[index - 1]);
	}else
	{
		l = new MapLoader();
		l->LoadMap(choices[index - 1]);
	}
	

	std::cout << "Exiting GameStart::start_game()\n" << std::endl;
}

string to_lower(string s)
	{
	for (int i = 0; i < s.length(); i++)
		{
		if (s[i] <= 90)
			s[i] += 32;
		}
	return s;
	}


