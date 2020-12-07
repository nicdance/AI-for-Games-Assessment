#pragma once
#include "Behaviour.h"
#include "SteeringForce.h"

class SteeringBehaviour : public Behaviour
{
private:
	SteeringForce* force;
public:
	SteeringBehaviour(SteeringForce* f) : Behaviour {}, force{ f }{}

	// Inherited From Behaviour
	virtual bool Update(Agent* agent, float deltaTime) override {
		agent->AddForce(force->GetForce(agent));
		return true;
	}

};

