#include "SeekBehaviour.h"
#include "Agent.h"
#include <glm.hpp>

SeekBehaviour::SeekBehaviour(const Agent* target, float speed) 
	:Behaviour(),
	m_speed{ speed },
	m_target{ target } {}

SeekBehaviour::~SeekBehaviour() {};

bool SeekBehaviour::Update(Agent* agent, float deltaTime) {
	glm::vec2 force(0, 0);

	if (m_target != nullptr)
	{
		glm::vec2 agentPos = agent->GetPosition(); //this agent's pos
		glm::vec2 targetPos = m_target->GetPosition(); // target agent's pos

		glm::vec2 direction = glm::normalize(m_target->GetPosition() - agent->GetPosition());
		//glm::vec2 direction = glm::normalize(targetPos - agentPos);

		auto force = direction * m_speed* deltaTime;
		agent->AddForce(force);
		return true;
	}
	return false;
}


void SeekBehaviour::SetTarget(Agent* agent) { 
	m_target = agent; 
}