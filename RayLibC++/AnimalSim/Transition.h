#pragma once
#include <memory>
class State;
class Condition;
class Agent;

class Transition
{
public:
	Transition(State* t, Condition* c) : condition{ c }, target{ t }{};
	//bool hasTriggered(std::shared_ptr<Agent> agent) const;
	bool hasTriggered(Agent* agent);
	State* getTargetState() const { 
		return target; 
	};
private:
	State* target;
	Condition* condition;
protected:
};

