#include <string>
#include <vector>
#include "Continent.h"
#include "Territory.h"


class MapLoader
	{
public:
	MapLoader();
	MapLoader(std::string fileName);
	virtual void LoadMap(std::string fileName);
	void print();

	[[nodiscard]] std::vector<continent> get_list_of_continents() const;
	void set_list_of_continents(const std::vector<continent>& list_of_continents);
	[[nodiscard]] std::vector<country> get_list_of_countries() const;
	void set_list_of_countries(const std::vector<country>& list_of_countries);
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

class ConquestFileReader
	{
	public:
		ConquestFileReader();
		ConquestFileReader(std::string fileName);
		void LoadMap(std::string fileName);


		[[nodiscard]] std::vector<continent> get_list_of_continents() const;
		void set_list_of_continents(const std::vector<continent>& list_of_continents);
		[[nodiscard]] std::vector<country> get_list_of_countries() const;
		void set_list_of_countries(const std::vector<country>& list_of_countries);
		void print();
	private:
		std::string fileName;

		std::vector<continent> listOfContinents;
		std::vector<country> listOfCountries;

	};


class ConquestFileReaderAdapter : public MapLoader
	{
	private:
		ConquestFileReader* cfr;

	public:

		ConquestFileReaderAdapter(ConquestFileReader* cfr);

		void LoadMap(std::string map);

	};