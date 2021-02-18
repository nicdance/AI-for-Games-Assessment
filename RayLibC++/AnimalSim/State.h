#pragma once
#include <vector>
#include <memory>

class Agent;
class Transition;

class State {
public:
	/*virtual void init(std::shared_ptr<Agent> a) {};
	virtual void update(std::shared_ptr<Agent>a , float deltaTime) = 0;
	virtual void exit(std::shared_ptr<Agent>a ) {};*/


	virtual void init(Agent* a) {};
	virtual void update(Agent* a, float deltaTime) = 0;
	virtual void exit(Agent* a) {};

	void AddTransition(std::shared_ptr<Transition> t) { 
		transitions.push_back(t); 
	}

	//std::shared_ptr<Transition> GetTriggeredTransition(std::shared_ptr<Agent> agent);
	std::shared_ptr<Transition> GetTriggeredTransition(Agent* agent);
	//Transition* GetTriggeredTransition(Agent* agent);

protected:
	std::vector<std::shared_ptr<Transition>> transitions;
};