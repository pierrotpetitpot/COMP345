#include <string>

class MapLoader
{

public:

	MapLoader();
	MapLoader(std::string fileName);
	void LoadMap(std::string fileName);

private:
	std::string fileName;

};


class Map {
public:
	Map();                      //default
	Map(int);
	void addEdge(int, int);     //add an edge between two territories

	int num_territories;
	bool** adjacent_Matrix;

	
};



