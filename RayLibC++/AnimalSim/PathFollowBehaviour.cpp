#include"PathFollowBehaviour.h"

PathFollowBehaviour::PathFollowBehaviour(float s) : m_speed{ s }, next_Node{1}{}

void PathFollowBehaviour::SetPath(const Path& path) {
	next_Node = 1;
	current_path.clear();
	current_path.insert(current_path.begin(), path.begin(), path.end());
}

//bool PathFollowBehaviour::Update(std::shared_ptr<Agent> agent, float deltaTime)
bool PathFollowBehaviour::Update(Agent* agent, float deltaTime)
{
	// If at end then stop.
	if (next_Node >= current_path.size())
	{
		agent->SetVelocity(glm::vec2{0,0});
		return 0;
	}
	// Work out Next goal node vector
	auto full_Vec = current_path[next_Node]->position - agent->GetPosition();
	float length = glm::length(full_Vec);
	auto vector_To_Next_Node = glm::normalize(full_Vec);

	float speed = m_speed;

	// Check if close to next node
	if (length<m_speed*deltaTime)
	{
		next_Node++;
		speed = length / deltaTime;
	}

	// Move towards Next Node	
	agent->SetVelocity(vector_To_Next_Node * speed);

	// If reach goal
		// advance to next node
	//if reach end
		// stop
	return false;
}

