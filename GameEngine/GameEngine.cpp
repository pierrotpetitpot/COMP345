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


GameStart::GameStart(): number_of_players_(2), phase_switch(false), game_statistics_switch(false)
{
}

int GameStart::get_number_of_players() const
{
	return number_of_players_;
}

void GameStart::set_number_of_players(int number_of_players)
{
	number_of_players_ = number_of_players;
}

bool GameStart::is_phase_switch() const
{
	return phase_switch;
}

void GameStart::set_phase_switch(bool phase_switch)
{
	this->phase_switch = phase_switch;
}

bool GameStart::is_game_statistics_switch() const
{
	return game_statistics_switch;
}

void GameStart::set_game_statistics_switch(bool game_statistics_switch)
{
	this->game_statistics_switch = game_statistics_switch;
}

void GameStart::start_game()
{
	//selecting the number of player
	std::cout << "Enter the number of players (2-5)" << std::endl;
	int index;
	cin >> index;
	while (index>5 || index<2)
	{
		std::cout << "Please, a number between 2 and 5 " << std::endl;
		cin >> index;
	}
	number_of_players_ = index;

	//Enabling or disabling phase switch
	std::cout << "Do want information about game phases? (Yes\\No)" << std::endl;
	string answer;
	cin >> answer;
	if (to_lower(answer) == "yes")
		{
		phase_switch =true ;
		}

	//Enabling or disabling game statistics switch
	std::cout << "Do want information about game statistics? (Yes\\No)" << std::endl;
	cin >> answer;
	if (to_lower(answer) == "yes")
		{
		game_statistics_switch = true;
		}

	
	MapLoader l;
	const std::string path = "Map files\\";
	index = 0;
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
	l.LoadMap(choices[index-1]);
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


