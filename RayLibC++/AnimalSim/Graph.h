#pragma once
#include <glm.hpp>
#include <vector>
#include <list>
struct Edge {
	struct Node* target;
	float cost = 1;
};

struct Node{
	unsigned int id;
	std::vector<Edge> outgoing_edges;
	glm::vec2 position;

	float gscore =  0; // Running cost to get to node.
	Node* parent = nullptr; 

};



using Path = std::list<Node*>;


