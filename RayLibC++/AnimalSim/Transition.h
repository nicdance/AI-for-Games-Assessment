#pragma once

class State;
class Condition;
class Agent;

class Transition
{
public:
	Transition(State* t, Condition* c) : condition{ c }, target{ t }{};
	bool hasTriggered(std::shared_ptr<Agent> agent) const;
	State* getTargetState() const { 
		return target; 
	};
private:
	State* target;
	Condition* condition;
protected:
};

