#pragma once
#include <vector>
#include <memory>
#include <glm.hpp>

class Behaviour;

class Agent
{
public:
	Agent();
	virtual ~Agent();
	// Update the agent and its behaviours
	virtual void Update(float deltaTime);
	// Draw the agent
	virtual void Draw();
	// Add a behaviour to the agent
	void AddBehaviour(Behaviour* behaviour);
	// Movement functions
	void SetPosition(glm::vec2  position);
	const glm::vec2&  GetPosition() const;
	void SetVelocity(glm::vec2  velocity);
	const glm::vec2&  GetVelocity() const;
	void AddForce(glm::vec2  force);

protected:
	std::vector<std::shared_ptr<Behaviour>> m_behaviourList;
	glm::vec2 m_position = { 0, 0 };
	glm::vec2  m_velocity = { 0, 0 };
	glm::vec2  m_force = { 0, 0 };
};