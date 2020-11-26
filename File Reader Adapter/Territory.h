#pragma once
#include <string>
#include <vector>

//Moved to here Header from LoadMap in Maploader
struct country { std::string countryName; int continentId; std::string continentName; int x; int y; std::vector<int> borders; std::vector<std::string> borders_name; };

