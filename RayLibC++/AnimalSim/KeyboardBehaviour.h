#pragma once
#include "Behaviour.h"

class KeyboardBehaviour :
	public Behaviour
{
public:
	KeyboardBehaviour(float s);
	~KeyboardBehaviour();
	//virtual bool Update(std::shared_ptr<Agent> agent, float deltaTime);
	virtual bool Update(Agent* agent, float deltaTime);
private:
	float m_speedIncrement = 500.0f;
};