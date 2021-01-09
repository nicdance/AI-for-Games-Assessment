#pragma once
#include <vector>
#include "graph.h"
#include "MapReader.h"

const float impassable = -1;

std::vector<Node> BuildNodeGraph(const MapObject& mo, int tilesize, float* terrain);
