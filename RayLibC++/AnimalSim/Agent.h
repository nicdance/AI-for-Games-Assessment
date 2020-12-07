#pragma once
#include <vector>
#include <memory>
#include <glm.hpp>
#include <raylib.h>


class Behaviour;

class Agent
{
public:
	Agent(Texture t);
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

	float max_speed = 100;
	float max_force;

	//Animation
	int initial_frame_x= 4;
	int initial_frame_y =0;
	float frames_per_second = 15;
	int steps = 8;

	// Screen

// FIX THIS
	int screenX = GetScreenWidth();
	int screenY = GetScreenHeight();

protected:
	std::vector<std::shared_ptr<Behaviour>> m_behaviourList;
	glm::vec2 m_position = { 0, 0 };
	glm::vec2  m_velocity = { 0, 0 };
	glm::vec2  m_force = { 0, 0 };

	Texture image;
};