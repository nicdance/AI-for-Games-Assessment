 #include "Graph.h"
#include <list>
#include <stdexcept>
#include <unordered_set>
#include <algorithm>
#include <queue>
#include "DijkstrasSearch.h"


//Procedure dijkstrasSearch(startNode, endNode)
Path dijkstrasSearch(Node* startNode, Node* endNode)
{
	//// Validate the input

	//if startNode is null OR endNode is null
	if (!startNode || !endNode)
	{
		//Raise Error
		throw std::runtime_error("Null nodes Supplied");
	}
	//if startNode == endNode
	if (startNode == endNode)
	{
		//return empty Path
		return Path();
	}

	//// Initialise the starting node

	//Set startNode.gScore to 0
	startNode->gscore = 0;
	//Set startNode.parent to null
	startNode->parent = nullptr;

	//// Create our temporary lists for storing nodes we’re visiting/visited

	//Let openList be a List of Nodes
	std::vector<Node*> openList;
	//Let closedList be a List of Nodes
	std::unordered_set<Node*> closedList;
	//Add startNode to openList
	openList.push_back(startNode);

	//While openList is not empty
	while (!openList.empty())
	{
		//Sort openList by Node.gScore
		auto sortByGScore = [](const Node* l, const Node* r) {
			return  l->gscore < r->gscore;
		};
		std::sort(openList.begin(), openList.end(), sortByGScore);

		//Let currentNode = first item in openList
		auto currentNode = openList.front();
		//// If we visit the endNode, then we can exit early.
		if (currentNode == endNode) {
			break;
		}
		//// Sorting the openList above guarantees the shortest path is found,
		//// given no negative costs (a prerequisite of the algorithm).
		//// This is an optional optimisation that improves performance,
		//// but doesn’t always guarantee the shortest path.
		//If currentNode is endNode
		//Exit While Loop

		//Remove currentNode from openList
		openList.erase(openList.begin());

		//Add currentNode to closedList
		closedList.insert(currentNode);

		//For all connections c in currentNode
		for (auto& e : currentNode->outgoing_edges)
		{
			//If c.target not in closedList
			if (std::find(closedList.begin(), closedList.end(), e.target) == closedList.end())
			{
				//Let gScore = currentNode.gScore + c.cost
				float gScore = currentNode->gscore + e.cost;

				//// Have not yet visited the node.
				//If c.target not in openList
				if (std::find(openList.begin(), openList.end(), e.target) == openList.end())
				{
					// So calculate the Score and update its parent.
					e.target->gscore = gScore;
					e.target->parent = currentNode;

					// Also add it to the openList for processing.
					openList.push_back(e.target);
				}
				//Else if (gScore < c.target.gScore)
				else if (gScore < e.target->gscore)
				{
					//	Let c.target.gScore = gScore
					e.target->gscore = gScore;
					//	Let c.target.parent = currentNode
					e.target->parent = currentNode;
				}
			}
		}
	}

	//	// Create Path in reverse from endNode to startNode

	//	Let Path be a list of Nodes
	Path path;
	//	Let currentNode = endNode
	Node* currentNode = endNode;
	if (!endNode->parent)
	{
		return path;
	}

	//	While currentNode is not null
	while (currentNode)
	{
		//	Add currentNode to beginning of Path
		path.push_front(currentNode);
		//	Let currentNode = currentNode.parent
		currentNode = currentNode->parent;
	}
	//	// Return the path for navigation between startNode/endNode
	return path;
}

Path dijkstrasSearch(Node* startNode, std::function<bool(const Node* n)> foundNode) {

	//// Validate the input

	//if startNode is null OR endNode is null
	if (!startNode )
	{
		//Raise Error
		throw std::runtime_error("Null nodes Supplied");
	}


	if (!foundNode)
	{
		//Raise Error
		throw std::runtime_error("Invalid Function Object Supplies");

	}
	//if startNode == endNode
	if (foundNode(startNode))
	{
		//return empty Path
		return Path();
	}

	//// Initialise the starting node

	//Set startNode.gScore to 0
	startNode->gscore = 0;
	//Set startNode.parent to null
	startNode->parent = nullptr;

	//// Create our temporary lists for storing nodes we’re visiting/visited

	//Let openList be a List of Nodes
	std::vector<Node*> openList;
	//Let closedList be a List of Nodes
	std::unordered_set<Node*> closedList;
	//Add startNode to openList
	openList.push_back(startNode);

	// Create a endNode to store end
	Node* endNode = nullptr;

	//While openList is not empty
	while (!openList.empty())
	{
		//Sort openList by Node.gScore
		auto sortByGScore = [](const Node* l, const Node* r) {
			return  l->gscore < r->gscore;
		};
		std::sort(openList.begin(), openList.end(), sortByGScore);

		//Let currentNode = first item in openList
		auto currentNode = openList.front();
		//// If we visit the endNode, then we can exit early.
		if (foundNode(currentNode)) {
			endNode = currentNode;
			break;
		}
		//// Sorting the openList above guarantees the shortest path is found,
		//// given no negative costs (a prerequisite of the algorithm).
		//// This is an optional optimisation that improves performance,
		//// but doesn’t always guarantee the shortest path.
		//If currentNode is endNode
		//Exit While Loop

		//Remove currentNode from openList
		openList.erase(openList.begin());

		//Add currentNode to closedList
		closedList.insert(currentNode);

		//For all connections c in currentNode
		for (auto& e : currentNode->outgoing_edges)
		{
			//If c.target not in closedList
			if (std::find(closedList.begin(), closedList.end(), e.target) == closedList.end())
			{
				//Let gScore = currentNode.gScore + c.cost
				float gScore = currentNode->gscore + e.cost;

				//// Have not yet visited the node.
				//If c.target not in openList
				if (std::find(openList.begin(), openList.end(), e.target) == openList.end())
				{
					// So calculate the Score and update its parent.
					e.target->gscore = gScore;
					e.target->parent = currentNode;

					// Also add it to the openList for processing.
					openList.push_back(e.target);
				}
				//Else if (gScore < c.target.gScore)
				else if (gScore < e.target->gscore)
				{
					//	Let c.target.gScore = gScore
					e.target->gscore = gScore;
					//	Let c.target.parent = currentNode
					e.target->parent = currentNode;
				}
			}
		}
	}

	//	// Create Path in reverse from endNode to startNode

	//	Let Path be a list of Nodes
	Path path;
	//	Let currentNode = endNode
	Node* currentNode = endNode;
	if (!endNode->parent)
	{
		return path;
	}

	//	While currentNode is not null
	while (currentNode)
	{
		//	Add currentNode to beginning of Path
		path.push_front(currentNode);
		//	Let currentNode = currentNode.parent
		currentNode = currentNode->parent;
	}
	//	// Return the path for navigation between startNode/endNode
	return path;
}
