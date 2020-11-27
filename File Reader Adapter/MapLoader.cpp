#include "MapLoader.h"
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

MapLoader::MapLoader() {

	};

MapLoader::MapLoader(std::string fileName) {
	this->fileName = fileName;
	};


void MapLoader::LoadMap(std::string path) {

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
		if (continents && countries == false) {

			continent continentInfos;
			string delimiter = " ";
			vector<string> infos;

			size_t pos = 0;
			string token;
			while ((pos = str.find(delimiter)) != std::string::npos) {
				token = str.substr(0, pos);
				infos.push_back(token);
				str.erase(0, pos + delimiter.length());
				}

			try {
				//cast value armyValue to int
				string armyValueString = infos.at(1);
				int armyValue = 0;
				stringstream cast(armyValueString);
				cast >> armyValue;
				continentInfos.continentName = infos.at(0);
				continentInfos.armyValue = armyValue;
				continentInfos.continentId = continentId;
				continentId++;

				listOfContinents.push_back(continentInfos);
				}
			catch (exception ex) {

				}
			continue;

			}

		//create list of countries
		if (countries && !borders) {

			country countryInfos;
			string delimiter = " ";
			vector<string> infos;
			int counterwhile = 0;

			size_t pos = 0;
			string token;
			while ((pos = str.find(delimiter)) != std::string::npos || counterwhile < 5) {
				token = str.substr(0, pos);
				infos.push_back(token);
				str.erase(0, pos + delimiter.length());
				counterwhile++;
				}

			try {

				//cast value continentId to int
				string continentIdString = infos.at(2);
				int continentId2 = 0;
				stringstream cast2(continentIdString);
				cast2 >> continentId2;

				countryInfos.continentId = continentId2;
				}
			catch (exception ex) {

				}
			try {


				//cast value x-value to int
				string xString = infos.at(3);
				int x = 0;
				stringstream cast3(xString);
				cast3 >> x;
				countryInfos.x = x;
				}
			catch (exception ex) {

				}
			try {

				//cast value y-value to int
				string yString = infos.at(4);
				int y = 0;
				stringstream cast4(yString);
				cast4 >> y;

				countryInfos.y = y;
				}
			catch (exception ex) {

				}

			countryInfos.countryName = infos.at(1);
			listOfCountries.push_back(countryInfos);
			continue;

			}

		if (borders) {

			string delimiter = " ";
			vector<int> borders;
			int border;

			size_t pos = 0;
			string token;
			while ((pos = str.find(delimiter)) && str.length() > 0) {
				token = str.substr(0, pos);
				int border = 0;
				stringstream cast5(token);
				cast5 >> border;
				borders.push_back(border);
				if (!(str.find(delimiter) != string::npos)) {
					break;
					}
				str.erase(0, pos + delimiter.length());
				}

			listOfCountries.at(counter).borders = borders;

			counter++;
			}


		}

	Map* map = new Map(listOfCountries.size());

	for (int i = 0; i < listOfCountries.size(); i++) {

		for (int j = 0; j < listOfCountries.at(i).borders.size(); j++) {

			map->addEdge(listOfCountries.at(i).borders.at(0), listOfCountries.at(i).borders.at(j));

			}

		}

	// bt Ebraheem Al shapi
	print();


	std::cout << "Exiting MapLoader::LoadMap(std::string path)\n" << std::endl;
	}

	void MapLoader::print()
		{

		cout << "***List of Continents***\n" << endl;
	
		for (auto& c : listOfContinents)
			{
			cout << "Continent ID:" << c.continentId << "\t\t" << "Continent Name:" << right << c.continentName << "\t\tArmy Value:" << c.armyValue << right << endl;
			}

		cout << "\n***List of Countries***\n" << endl;

		for (auto& c : listOfCountries)
			{
			cout << "Country Name:" << c.countryName << "\t\t\tContinent  ID:" << right << c.continentId << "\t\t\tList of borders";
			for (auto& b : c.borders)
				{
				cout << " " << b;
				}
			cout << endl;
			}
		}

std::vector<continent> MapLoader::get_list_of_continents() const
{
	return listOfContinents;
}

void MapLoader::set_list_of_continents(const std::vector<continent>& list_of_continents)
{
	listOfContinents = list_of_continents;
}

std::vector<country> MapLoader::get_list_of_countries() const
{
	return listOfCountries;
}

void MapLoader::set_list_of_countries(const std::vector<country>& list_of_countries)
{
	listOfCountries = list_of_countries;
}


//default constructor
Map::Map() {
	this->num_territories = 0;
	this->adjacent_Matrix = nullptr;
	}
//one int parameter constructor
Map::Map(int num_territories) {
	this->num_territories = num_territories;
	adjacent_Matrix = new bool* [num_territories];
	//initialize the 2D array with false values
	for (int i = 0; i < num_territories; i++) {
		adjacent_Matrix[i] = new bool[num_territories];
		for (int j = 0; j < num_territories; j++)
			adjacent_Matrix[i][j] = false;
		}
	}
//add an edge between two vertices
void Map::addEdge(int i, int j) {
	adjacent_Matrix[i][j] = true;
	adjacent_Matrix[j][i] = true;
	}

ConquestFileReader::ConquestFileReader() {

	};

ConquestFileReader::ConquestFileReader(std::string fileName) {
	this->fileName = fileName;
	};


void ConquestFileReader::LoadMap(std::string path) {

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
		if (continents) {
			if (str == "")
				{
				continents = false;
				continue;
				}

			continent continentInfos;
			string delimiter = "=";
			size_t pos = str.find(delimiter);

			continentInfos.continentName = str.substr(0, pos);
			continentInfos.continentId = continentId++;
			continentInfos.armyValue = stoi(str.substr(pos + 1, str.length()));
			listOfContinents.push_back(continentInfos);
			}

		//create list of countries
		if (territory) {

			if (str == "")
				{
				territory = false;
				continue;
				}
			country countryInfos;
			string delimiter = ",";
			countryInfos.countryName = (str.substr(0, str.find(delimiter)));
			countryInfos.continentId = continentId++;
			for (int i = 0; i < 3; i++)
				{
				str = str.substr(str.find(delimiter) + 1, str.length());
				}
			countryInfos.continentName = str.substr(0, str.find(delimiter));
			str = str.substr(str.find(delimiter) + 1, str.length());

			string info = "";
			string::iterator it = str.begin();

			for (; it != str.end(); it++)
				{
				if ((*it) == ',' && info.length() != 0)
					{
					countryInfos.borders_name.emplace_back(info);
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
	std::cout << "Exiting ConquestFileReader::LoadMap(std::string path)" << std::endl;
	}

std::vector<continent> ConquestFileReader::get_list_of_continents() const
{
	return listOfContinents;
}

void ConquestFileReader::set_list_of_continents(const std::vector<continent>& list_of_continents)
{
	listOfContinents = list_of_continents;
}

std::vector<country> ConquestFileReader::get_list_of_countries() const
{
	return listOfCountries;
}

void ConquestFileReader::set_list_of_countries(const std::vector<country>& list_of_countries)
{
	listOfCountries = list_of_countries;
}


void ConquestFileReader::print()
	{

	cout << "***List of Continents***\n" << endl;
	
	for (auto& c : listOfContinents)
		{
		cout << "Continent ID:" << c.continentId << "\t\t" << "Continent Name:" << right << c.continentName << "\t\tArmy Value:" << c.armyValue << right << endl;
		}


	cout << "\n***List of Countries***\n" << endl;
	
	for (auto& c : listOfCountries)
		{
		cout << "Country Name:" << c.countryName << "\t\t\tContinent  ID:" << right << c.continentId << "\t\t\tList of borders";
		for (auto& b : c.borders_name)
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
	std::cout << "Exiting void ConquestFileReaderAdapter::LoadMapintoWarZoneFormat(std::string map)\n" << std::endl;
	}
