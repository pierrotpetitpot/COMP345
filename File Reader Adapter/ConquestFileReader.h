#pragma once
#include <string>
#include <vector>
#include "Continent.h"
#include "Territory.h"


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
