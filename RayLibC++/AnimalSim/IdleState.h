#pragma once
#include "State.h"

class IdleState : public State {
public:
	virtual ~IdleState() {}

	// Inherited via State
	//virtual void update(std::shared_ptr<Agent> agent, float deltaTime) override {
	virtual void update(Agent* agent, float deltaTime) override {
	}

};
