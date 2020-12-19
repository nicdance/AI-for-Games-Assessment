#pragma once
#include <string>
#include <vector>
#include <raylib.h>

struct MapObject {
	const int x;
	const int y;
	std::vector<char> info;

	Texture tile_atlas;
	Rectangle* rectanglemap;
	int tilesize;

	void Draw() {
		for (int ii = 0; ii < x; ++ii)
		{
			for (int jj	 = 0; jj < y; ++jj)
			{

			}
		}
	}

};
MapObject ReadMapInfo(std::string filename);
