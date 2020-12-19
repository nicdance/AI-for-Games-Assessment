#include "MakeNodeGrid.h"

std::vector<Node> BuildNodeGraph(const MapObject& mo, float* terrain) {
	std::vector<Node> graph;
	graph.resize(mo.info.size());

	for (int id=0; id < mo.info.size(); ++id)
	{
		const int x = id % mo.x;
		const int y = id / mo.x;

		bool addLeft  = x > 0;
		bool addRight = x < mo.x - 1;
		bool addUp    = y < mo.y - 1; 
		bool addDown  = y > 0;

		int goLeft  = -1;
		int goRight =  1;
		int goUp    = mo.x;
		int goDown  = -mo.x;

		graph[id].id = id;

		auto AddConnection = [&](bool canDirection, int offset, float distance= 1.0f) {
			if (canDirection)
			{
				float weight = terrain[mo.info[id + offset]];
				if (weight != impassable) {
					graph[id].outgoing_edges.push_back(Edge{ &graph[id + offset], distance * weight });
				}
			}
		};

		AddConnection(addLeft, goLeft);
		AddConnection(addRight, goRight);
		AddConnection(addUp, goUp);
		AddConnection(addDown, goDown);


		/*if (addLeft)
		{
			float weight = terrain[mo.info[id + goLeft]];
			if (weight !=impassable) {
				graph[id].outgoing_edges.push_back(Edge{ &graph[id + goLeft], weight });
			}
		}
		if (addright)
		{
			float weight = terrain[mo.info[id + goRight]];
			if (weight != impassable) {
				graph[id].outgoing_edges.push_back(Edge{ &graph[id + goRight], weight });
			}
		}
		if (addUp)
		{
			float weight = terrain[mo.info[id + goUp]];
			if (weight != impassable){ 
				graph[id].outgoing_edges.push_back(Edge{ &graph[id + goUp], weight });
			}
		}
		if (addDown)
		{
			float weight = terrain[mo.info[id + goDown]];
			if (weight != impassable) {
				graph[id].outgoing_edges.push_back(Edge{ &graph[id + goDown], weight });
			}
		}*/


	}
	return graph;
}
