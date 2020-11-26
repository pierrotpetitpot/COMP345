#include <string>
#include <vector>
#include "Continent.h"
#include "Territory.h"


class MapLoader
	{
public:
	MapLoader();
	MapLoader(std::string fileName);
	void LoadMap(std::string fileName);
	void print();

private:
	std::string fileName;
	// New Members
	std::vector<continent> listOfContinents;
	std::vector<country> listOfCountries;

	};


class Map {
public:
	Map();                      //default
	Map(int);
	void addEdge(int, int);     //add an edge between two territories

	int num_territories;
	bool** adjacent_Matrix;


	};


