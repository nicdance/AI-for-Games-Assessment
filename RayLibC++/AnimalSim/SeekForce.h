#pragma once
#include <glm.hpp>
#include "SteeringForce.h"
#include "Agent.h"


class SeekForce: public SteeringForce {
private:
	Agent* target;
public:
	SeekForce(Agent* t) :SteeringForce{}, target{ t }{}
	virtual glm::vec2 GetForce(class Agent* agent) {
		auto desiredVelocity = glm::normalize( target->GetPosition() - agent->GetPosition())* agent->max_speed;
		auto steeringForce = desiredVelocity - agent->GetVelocity();
		return steeringForce;
	};
};

class FleeForce : public SeekForce {
public:
	FleeForce(Agent* t) :SeekForce{ t } {}
	virtual glm::vec2 GetForce(class Agent* agent) {
		return -SeekForce::GetForce(agent);
	};
};
