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

	unsigned int GetPositionID(float x_, float y_) const {
		const int tileX = x_ / tilesize;
		const int tileY = y_ / tilesize;
		return tileX + tileY * x;
	}

	void Draw() {
		for (int ii = 0; ii < x; ++ii)
		{
			for (int jj	 = 0; jj < y; ++jj)
			{
				int id = ii + jj * x;
				int mapinfo = info[id];
				Rectangle src = rectanglemap[mapinfo];
				Rectangle dest {ii*tilesize, jj*tilesize, tilesize,tilesize};
				Color color{ 255,255,255,255 };
				DrawTexturePro(tile_atlas, src, dest, Vector2{ 0,0 }, 0, color);
			}
		}
	}

};
MapObject ReadMapInfo(std::string filename);
