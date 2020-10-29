#include "Agent.h"
#include "Behaviour.h"
#include <raylib.h>
#include <glm.hpp>
Agent::Agent()
{}

Agent::Agent(glm::vec2 pos)
{
	SetPosition(pos);
}

Agent::~Agent()
{}

// Update the agent and its behaviours
void Agent::Update(float deltaTime)
{
	// Force is equal to zero
	// For each Behaviour in Behaviour list
	// Call the Behaviour’s Update function which will add a value to Force
	// Add Force multiplied by delta time to Velocity
	// Add Velocity multiplied by delta time to Position
	m_force = { 0, 0 };

	for (auto& b : m_behaviourList) {
		// The force calculated by the behaviour’s update will be added to m_force
		b->Update(this, deltaTime);
	}

	m_velocity += m_force * deltaTime;
	m_position += m_velocity * deltaTime;
}

// Draw the agent
void Agent::Draw()
{
	DrawRectangle(m_position.x, m_position.y, 10, 10, RED);
}
// Add a behaviour to the agent
void Agent::AddBehaviour(Behaviour* behaviour)
{
	m_behaviourList.emplace_back(behaviour);
}

void Agent::SetPosition(glm::vec2  position) { 
	m_position = position; 
}

const glm::vec2&  Agent::GetPosition() const { 
	return m_position; 
}

void Agent::SetVelocity(glm::vec2  velocity) { 
	m_velocity = velocity;
}

const glm::vec2&  Agent::GetVelocity() const{ 
	return m_velocity; 
}
void Agent::AddForce(glm::vec2  force) { 
	m_force += force;
}