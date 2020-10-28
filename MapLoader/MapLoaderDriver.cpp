#include <iostream>
#include "MapLoader.h"

int main(int argc, const char * argv[]) {


	MapLoader mapLoader;
	std::string path = "C:\\Users\\PierreAnthonyMoffet\\Desktop\\bigeurope.map";
	mapLoader.LoadMap(path);


	return 0;
}