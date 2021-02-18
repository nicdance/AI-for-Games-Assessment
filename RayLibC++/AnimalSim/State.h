#pragma once
#include <vector>
#include <memory>

class Agent;
class Transition;

class State {
public:
	virtual void init(Agent*) {};
	virtual void update(Agent*, float deltaTime) = 0;
	virtual void exit(Agent*) {};

	void AddTransition(std::shared_ptr<Transition> t) { 
		transitions.push_back(t); 
	}

	std::shared_ptr<Transition> GetTriggeredTransition(std::shared_ptr<Agent> agent);
	//Transition* GetTriggeredTransition(Agent* agent);

protected:
	std::vector<std::shared_ptr<Transition>> transitions;
};