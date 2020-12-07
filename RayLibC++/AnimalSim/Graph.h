#pragma once
#include <glm.hpp>
#include <vector>

struct Edge {
	struct Node* target;
	float cost = 1;
};

struct Node{
	char name;
	std::vector<Edge> outgoing_edges;
	glm::vec2 position;

	float gscore = 0; // Running cost to get to node.
	Node* parent = nullptr; 

};



