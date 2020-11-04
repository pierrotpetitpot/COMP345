// Author Ebraheem Al Shapi
// Solution Risk
// Project: GameEngine
// Created at 9:04 PM 20/10/2020
// Date: 01/11/2020   7:09 PM
// File Name: GameEngine.h

#pragma once
#include <iostream>
#include <vector>

using namespace std;

class GameStart
{
private:
	int number_of_players_;
	bool phase_switch;
	bool game_statistics_switch;
public:

	GameStart();
	int get_number_of_players() const;
	void set_number_of_players(int number_of_players);
	bool is_phase_switch() const;
	void set_phase_switch(bool phase_switch);
	bool is_game_statistics_switch() const;
	void set_game_statistics_switch(bool game_statistics_switch);
	void start_game();
};

string to_lower(string s);


class Game_play
{
private:

public:
};
