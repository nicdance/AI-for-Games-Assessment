#pragma once
#include "Agent.h"


class Condition
{
public:
	Condition() {}
	virtual ~Condition() {}
	// virtual bool test(std::shared_ptr<Agent> agent) const = 0;
	virtual bool test(Agent* agent) const = 0;

	//bool Update(std::shared_ptr<Agent> agent, float deltaTime) {
	bool Update(Agent* agent, float deltaTime) {
		if (test(agent))
		{
			return true;
		}
		return false;
	}
private:
protected:
};


class WithinRangeCondition : public Condition {
public:
	WithinRangeCondition(std::shared_ptr<Agent> t, float r) : target{ t }, range{ r }{};

	//virtual bool test(std::shared_ptr<Agent> agent) const override
	virtual bool test(Agent* agent) const override {
		return glm::distance(agent->GetPosition(), target->GetPosition()) < range;
	}
protected:
	const std::shared_ptr<Agent> target;
	float range;
};


class OutOfRangeCondition : public Condition {
public:
	OutOfRangeCondition(std::shared_ptr<Agent> t, float r) : target{ t }, range{ r }{};

	//virtual bool test(std::shared_ptr<Agent> agent) const override
	virtual bool test(Agent* agent) const override {
		return glm::distance(agent->GetPosition(), target->GetPosition()) > range;
	}
protected:
	const std::shared_ptr<Agent> target;
	float range;
};
