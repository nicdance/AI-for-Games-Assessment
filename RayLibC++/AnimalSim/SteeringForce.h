#pragma once
#include <glm.hpp>

class SteeringForce {
public:
	virtual glm::vec2 GetForce(class Agent*) = 0;
};