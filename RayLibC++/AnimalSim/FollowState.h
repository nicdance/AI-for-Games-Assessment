#pragma once
#include "State.h"
#include "Agent.h"
#include "Graph.h"

class FollowState : public State {
public:
	virtual ~FollowState() {}
	FollowState(std::shared_ptr<Agent> t, float s);
	void SetPath(const Path& path);
	void update(Agent* chaser, float deltaTime) override;
protected:
	// Agent* target;

	std::shared_ptr<Agent> target;
	float m_speed;
	std::vector<Node*> current_path;
	int next_Node;

};
