#pragma once
#include <glm.hpp>

class SteeringForce {
public:
	//virtual glm::vec2 GetForce(std::shared_ptr<Agent>) = 0;
	virtual glm::vec2 GetForce(Agent* a) = 0;
};