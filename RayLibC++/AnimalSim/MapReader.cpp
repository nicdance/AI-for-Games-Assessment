#include <fstream>
#include <sstream>
#include "MapReader.h"

MapObject ReadMapInfo(std::string filename) {
	std::ifstream filein(filename);
	if (!filein.is_open())
	{
		return MapObject{};
	}

	std::string line;

	// get header fro the size values
	std::getline(filein, line);

	std::istringstream is{ line };

	// get  dimension for map and set up array
	int x = 0;
	int y = 0;
	is >> x;
	is >> y;

	MapObject mapinfo{x,y};
	mapinfo.info.reserve(x * y);

	while (!filein.eof())
	{
		std::getline(filein, line);
		std::istringstream is{ line };
		while (!is.eof())
		{
			std::string tv;
			is >> tv;

			mapinfo.info.push_back(atoi(tv.c_str()));

			
			if(is.eof()) {
				break;
			}
		}
	}
	return mapinfo;
}