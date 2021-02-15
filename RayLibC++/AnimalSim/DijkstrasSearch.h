#pragma once
#include <functional>
#include "Graph.h"

using Path = std::list<Node*>;

Path dijkstrasSearch(Node* startNode, Node* endNode);

Path dijkstrasSearch(Node* startNode, std::function<bool(const Node* n)> foundNode);