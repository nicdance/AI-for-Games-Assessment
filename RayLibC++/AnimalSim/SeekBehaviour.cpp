#include "SeekBehaviour.h"
#include <glm.hpp>

SeekBehaviour::SeekBehaviour():Behaviour() {};
SeekBehaviour::~SeekBehaviour() {};

bool SeekBehaviour::Update(Agent* agent, float deltaTime) {
	glm::vec2 force(0, 0);

	if (m_target != nullptr)
	{
		glm::vec2 agentPos = agent->GetPosition(); //this agent's pos
		glm::vec2 targetPos = m_target->GetPosition(); // target agent's pos

		glm::vec2 direction(targetPos.x - agentPos.x, targetPos.y - agentPos.y);
		direction = direction * seekSpeed;

		force = direction - agent->GetVelocity();

		agent->AddForce(force * deltaTime);
		return true;
	}
	return false;
}


void SeekBehaviour::SetTarget(Agent* agent) { 
	m_target = agent; 
}