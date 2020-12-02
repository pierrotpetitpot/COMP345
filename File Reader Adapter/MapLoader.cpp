// Author Ebraheem Al Shapi
// Solution Risk
// Project: File Reader Adapter
// Created at 4:04 AM 26/11/2020
// Date: 02/12/2020   3:51 AM
// File Name: MapLoader.cpp

#include "MapLoader.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


using namespace std;

MapLoader::MapLoader()
{
};

MapLoader::MapLoader(std::string fileName)
{
	this->fileName = fileName;
};


void MapLoader::LoadMap(std::string path)
{
	std::cout << "Entering MapLoader::LoadMap(std::string path)\n" << std::endl;

	std::ifstream File(path);

	if (!File)
	{
		std::cout << "Error: Cannot open the File" << std::endl;
	}

	// Moved to the the header file
	//struct continent { std::string continentName; int continentId; int armyValue; };
	//struct country { std::string countryName; int continentId; int x; int y; std::vector<int> borders;};


	std::string str;
	bool continents = false;
	bool countries = false;
	bool borders = false;
	int continentId = 1;
	int counter = 0;

	// Became the class MapLoader memebers
	//std::vector<continent> listOfContinents;
	//std::vector<country> listOfCountries;


	while (std::getline(File, str))
	{
		//if reached continents
		if (str == "[continents]")
		{
			continents = true;
			continue;
		}

		//if reached countries
		if (str == "[countries]")
		{
			continentId = 1;
			countries = true;
			continue;
		}

		//if reached borders
		if (str == "[borders]")
		{
			borders = true;
			continue;
		}

		//create list of continents
		if (continents)
		{
			if (str.empty())
			{
				continents = false;
				continue;
			}

			continent* continentInfos = new continent();
			string delimiter = " ";
			size_t pos = str.find(delimiter);

			continentInfos->continentName = str.substr(0, pos);
			continentInfos->continentId = continentId++;
			continentInfos->armyValue = stoi(str.substr(pos + 1, pos + 2));
			listOfContinents.push_back(continentInfos);
		}

		//create list of countries
		if (countries)
		{
			if (str.empty())
			{
				countries = false;
				continue;
			}
			country* countryInfos = new country();
			string delimiter = " ";
			countryInfos->countryID = stoi(str.substr(0, str.find(delimiter)));
			str = str.substr(str.find(delimiter) + 1, str.length());
			countryInfos->countryName = str.substr(0, str.find(delimiter));
			str = str.substr(str.find(delimiter) + 1, str.length());
			countryInfos->continentId = stoi(str.substr(0, str.find(delimiter)));

			listOfCountries.push_back(countryInfos);
		}

		if (borders)
		{
			if (str.empty())
			{
				borders = false;
				continue;
			}
			int pos;
			int border;
			stringstream strValue(str);
			strValue >> pos;


			while (strValue.good())
			{
				strValue >> border;
				listOfCountries.at(pos-1)->borders.push_back(border);
			}
		}
	}

	// by Ebraheem Al Shapi
	print();


	std::cout << "\nExiting MapLoader::LoadMap(std::string path)\n" << std::endl;
}

void MapLoader::print()
{
	cout << "***List of Continents***\n" << endl;

	for (auto& c : listOfContinents)
	{
		cout << "Continent ID:" << c->continentId << "\t\t" << "Continent Name:" << right << c->continentName <<
			"\t\tArmy Value:" << c->armyValue << right << endl;
	}

	cout << "\n***List of Countries***\n" << endl;

	for (auto& c : listOfCountries)
	{
		cout << "Country Name:" << c->countryName << "\t\t\tContinent  ID:" << right << c->continentId <<
			"\t\t\tList of borders";
		for (auto& b : c->borders)
		{
			cout << " " << b;
		}
		cout << endl;
	}
}


//default constructor
Map::Map()
{
	this->num_territories = 0;
	this->adjacent_Matrix = nullptr;
}

//one int parameter constructor
Map::Map(int num_territories)
{
	this->num_territories = num_territories;
	adjacent_Matrix = new bool*[num_territories];
	//initialize the 2D array with false values
	for (int i = 0; i < num_territories; i++)
	{
		adjacent_Matrix[i] = new bool[num_territories];
		for (int j = 0; j < num_territories; j++)
			adjacent_Matrix[i][j] = false;
	}
}

//add an edge between two vertices
void Map::addEdge(int i, int j)
{
	adjacent_Matrix[i][j] = true;
	adjacent_Matrix[j][i] = true;
}

ConquestFileReader::ConquestFileReader()
{
};

ConquestFileReader::ConquestFileReader(std::string fileName)
{
	this->fileName = fileName;
};


void ConquestFileReader::LoadMap(std::string path)
{
	std::cout << "Entering ConquestFileReader::LoadMap(std::string path)\n" << std::endl;

	std::ifstream File(path);

	if (!File)
	{
		std::cout << "Error: Cannot open the File\n" << std::endl;
	}

	// Moved to the the header file
	//struct continent { std::string continentName; int continentId; int armyValue; };
	//struct country { std::string countryName; int continentId; int x; int y; std::vector<int> borders;};


	std::string str;
	bool continents = false;
	bool territory = false;
	bool borders = false;
	int continentId = 1;
	int counter = 0;

	// Became the class MapLoader memebers
	//std::vector<continent> listOfContinents;
	//std::vector<country> listOfCountries;


	while (std::getline(File, str))
	{
		//if reached continents
		if (str == "[Continents]")
		{
			continents = true;
			continue;
		}

		//if reached countries
		if (str == "[Territories]")
		{
			continentId = 1;
			territory = true;
			continue;
		}

		//if reached borders
		if (str == "[borders]")
		{
			borders = true;
			continue;
		}

		//create list of continents
		if (continents)
		{
			if (str.empty())
			{
				continents = false;
				continue;
			}

			continent* continentInfos = new continent();
			string delimiter = "=";
			size_t pos = str.find(delimiter);

			continentInfos->continentName = str.substr(0, pos);
			continentInfos->continentId = continentId++;
			continentInfos->armyValue = stoi(str.substr(pos + 1, str.length()));
			listOfContinents.push_back(continentInfos);
		}

		//create list of countries
		if (territory)
		{
			if (str.empty())
			{
				territory = false;
				continue;
			}
			country* countryInfos= new country();
			string delimiter = ",";
			countryInfos->countryName = (str.substr(0, str.find(delimiter)));
			countryInfos->continentId = continentId++;
			for (int i = 0; i < 3; i++)
			{
				str = str.substr(str.find(delimiter) + 1, str.length());
			}
			countryInfos->continentName = str.substr(0, str.find(delimiter));
			str = str.substr(str.find(delimiter) + 1, str.length());

			string info;
			string::iterator it = str.begin();

			for (; it != str.end(); ++it)
			{
				if ((*it) == ',' && info.length() != 0)
				{
					countryInfos->borders_name.emplace_back(info);
					info = "";
					continue;
				}
				if ((*it) != ',')
				{
					info += *it;
				}
			}

			listOfCountries.push_back(countryInfos);
		}
	}

	print();
	std::cout << "\nExiting ConquestFileReader::LoadMap(std::string path)" << std::endl;
}


void ConquestFileReader::print()
{
	cout << "***List of Continents***\n" << endl;

	for (auto& c : listOfContinents)
	{
		cout << "Continent ID:" << c->continentId << "\t\t" << "Continent Name:" << right << c->continentName <<
			"\t\tArmy Value:" << c->armyValue << right << endl;
	}


	cout << "\n***List of Countries***\n" << endl;

	for (auto& c : listOfCountries)
	{
		cout << "Country Name:" << c->countryName << "\t\t\tContinent  ID:" << right << c->continentId <<
			"\t\t\tList of borders";
		for (auto& b : c->borders_name)
		{
			cout << " " << b;
		}
		cout << endl;
	}
}


ConquestFileReaderAdapter::ConquestFileReaderAdapter(ConquestFileReader* cfr)
{
	this->cfr = cfr;
}

void ConquestFileReaderAdapter::LoadMap(std::string map)
{
	std::cout << "Entering void ConquestFileReaderAdapter::LoadMapintoWarZoneFormat(std::string map)\n" << std::endl;
	cfr->LoadMap(map);
	std::cout << "\nExiting void ConquestFileReaderAdapter::LoadMapintoWarZoneFormat(std::string map)\n" << std::endl;
}
