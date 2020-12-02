// Author Ebraheem Al Shapi
// Solution Risk
// Project: File Reader Adapter
// Created at 4:04 AM 26/11/2020
// Date: 29/11/2020   8:25 PM
// File Name: MapLoader.h

#include <string>
#include <vector>


struct continent
{
	std::string continentName;
	int continentId;
	int armyValue;
};

struct country
{
	std::string countryName;
	int countryID;
	int continentId;
	std::string continentName;
	std::vector<int> borders;
	std::vector<std::string> borders_name;
};

class MapLoader
{
public:
	//Constructors
	MapLoader();
	MapLoader(std::string fileName);
	//Main function of Maploader
	virtual void LoadMap(std::string fileName);
	//Display function for the input
	void print();

private:
	std::string fileName;
	// New Members
	std::vector<continent*> listOfContinents;
	std::vector<country*> listOfCountries;
};


class Map
{
public:
	Map(); //default
	Map(int);
	void addEdge(int, int); //add an edge between two territories

	int num_territories;
	bool** adjacent_Matrix;
};

class ConquestFileReader
{
public:
	ConquestFileReader();
	ConquestFileReader(std::string fileName);
	void LoadMap(std::string fileName);

	void print();
private:
	std::string fileName;

	std::vector<continent*> listOfContinents;
	std::vector<country*> listOfCountries;
};


class ConquestFileReaderAdapter : public MapLoader
{
private:
	ConquestFileReader* cfr;

public:

	ConquestFileReaderAdapter(ConquestFileReader* cfr);

	virtual void LoadMap(std::string map) override;
};
