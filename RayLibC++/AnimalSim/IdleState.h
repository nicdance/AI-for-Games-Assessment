#pragma once
#include "State.h"

class IdleState : public State {
public:
	virtual ~IdleState();

	// Inherited via State
	virtual void update(Agent* agent, float deltaTime) override {
	}

};
