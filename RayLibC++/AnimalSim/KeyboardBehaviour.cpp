#include "KeyboardBehaviour.h"
#include <raylib.h>
#include <glm.hpp>


KeyboardBehaviour::KeyboardBehaviour(float s) : Behaviour(), m_speedIncrement{ s } {};
KeyboardBehaviour::~KeyboardBehaviour() {};

bool KeyboardBehaviour::Update(Agent* agent, float deltaTime)
{
	glm::vec2 offset = { 0, 0 };
	if (IsKeyDown(KEY_UP)) {
		offset.y = -m_speedIncrement;
	}
	if (IsKeyDown(KEY_DOWN)){
		offset.y = m_speedIncrement;
	}
	if (IsKeyDown(KEY_LEFT)){
		offset.x = -m_speedIncrement;
	}
	if (IsKeyDown(KEY_RIGHT)){
		offset.x = m_speedIncrement;
	}
	agent->SetVelocity(offset * deltaTime);

	/*glm::vec2 force = { 0, 0 };
	if (IsKeyDown(KEY_UP)) {
		//	force.y = -m_speedIncrement;
	}
	if (IsKeyDown(KEY_DOWN)) {
		//	force.y = m_speedIncrement;
	}
	if (IsKeyDown(KEY_LEFT)) {
		//	force.x = -m_speedIncrement;
	}
	if (IsKeyDown(KEY_RIGHT)) {
		//	force.x = m_speedIncrement;
	}
	agent->AddForce(force*deltaTime);*/
	return true;
}