#pragma once
#include "Behaviour.h"

class KeyboardBehaviour :
	public Behaviour
{
public:
	KeyboardBehaviour();
	~KeyboardBehaviour();
	virtual bool Update(Agent* agent, float deltaTime);
private:
	float m_speedIncrement = 500.0f;
};