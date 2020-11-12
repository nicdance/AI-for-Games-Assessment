#include "Agent.h"
#include "Behaviour.h"
#include <raylib.h>
#include <glm.hpp>
Agent::Agent(Color c) : m_color{c}
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

	// Velocity
	DrawLine(m_position.x, m_position.y,
			 m_position.x+m_velocity.x, m_position.y+m_velocity.y,
			 GREEN);

	// Force
	DrawLine(m_position.x, m_position.y,
		m_position.x + m_force.x, m_position.y + m_force.y,
		BLUE);

	float magnitude = glm::length(m_velocity);
	if (magnitude > max_speed)
	{
		m_velocity = glm::normalize(m_velocity)*max_speed;

	}
	m_position += m_velocity * deltaTime;
}

// Draw the agent
void Agent::Draw()
{
	DrawRectangle(m_position.x, m_position.y, 10, 10, m_color);
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