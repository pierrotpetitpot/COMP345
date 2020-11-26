#include "ConquestFileReader.h"
#include <vector>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>


using namespace std;

ConquestFileReader::ConquestFileReader() {

	};

ConquestFileReader::ConquestFileReader(std::string fileName) {
	this->fileName = fileName;
	};


void ConquestFileReader::LoadMap(std::string path) {

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
				listOfContinents.emplace_back(continentInfos);
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
			for (int i=0;i<3;i++)
			{
				str = str.substr(str.find(delimiter) + 1, str.length());
			}
			countryInfos.continentName = str.substr(0, str.find(delimiter));
			str = str.substr(str.find(delimiter) + 1, str.length());
			
			string info = "";
			string::iterator it = str.begin();
			
			for (;it!=str.end();it++)
			{
				if ((*it)==',' && info.length()!=0)
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
	for (auto& c : listOfContinents)
		{
		cout << "Continent ID:" << c.continentId << "\t\t" << "Continent Name:" << right << c.continentName << "\t\tArmy Value:" << c.armyValue << right << endl;
		}

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
