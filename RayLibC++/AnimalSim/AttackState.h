#pragma once
#include "State.h"
#include "Agent.h"
#include <glm.hpp>

class AttackState : public State {
public:
	virtual ~AttackState();
	AttackState(std::shared_ptr<Agent> t, float s) : target{ t }, speed{ s }{};

	// Inherited via State
	virtual void update(Agent* chaser, float deltaTime) override {
		chaser->SetVelocity(glm::normalize(target->GetPosition() - chaser->GetPosition()) * speed);

	}
protected:
	// Agent* target;

	 std::shared_ptr<Agent> target;
	float speed;
};
