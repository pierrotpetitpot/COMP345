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
public:
	int get_number_of_players() const;
	void set_number_of_players(int number_of_players);
	void start_game();
};


class Game_play
{
private:

public:
};
