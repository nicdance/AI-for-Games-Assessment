#include "Agent.h"
#include "Behaviour.h"
#include <raylib.h>
#include <glm.hpp>


Agent::Agent(Texture t) : image{t}
{}

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

#ifndef NDEBUG
	// Velocity
	//DrawLine(m_position.x, m_position.y,
	//		 m_position.x+m_velocity.x, m_position.y+m_velocity.y,
	//		 GREEN);

	// Force
	//DrawLine(m_position.x, m_position.y,
	//	m_position.x + m_force.x, m_position.y + m_force.y,
	//	BLUE);
#endif // !NDEBUG

	float magnitude = glm::length(m_velocity);
	if (magnitude > max_speed)
	{
		m_velocity = glm::normalize(m_velocity)*max_speed;

	}
	m_position += m_velocity * deltaTime;

	if (m_position.x < 0)	{
		m_position.x += screenX;
	}
	if (m_position.x > screenX) {
		m_position.x -= screenX;
	}
	if (m_position.y < 0) {
		m_position.y += screenY;
	}
	if (m_position.y > screenY) {
		m_position.y -= screenY;
	}
}

// Draw the agent
void Agent::Draw()
{
	constexpr int size = 10;
	//DrawRectangle(  m_position.x-size/2, m_position.y - size / 2, size, size, RED);
	constexpr int recSize = 32;
	int currentframex = initial_frame_x + int(GetTime()*frames_per_second)%steps;
	int currentframey = initial_frame_y;
	Rectangle source{ currentframex*32,currentframey *32, recSize, recSize };

	const int width = recSize;
	const int height = recSize;

	Rectangle destination { m_position.x, m_position.y,
							width, height };

	float angle = atan2(m_velocity.y, m_velocity.x)*180/3.141459f+90;
	DrawTexturePro(image, source, destination, { width/2, height/3 }, angle, WHITE);
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