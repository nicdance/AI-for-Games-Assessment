#pragma once
#include <vector>
#include "Behaviour.h"
#include "State.h"
#include "Transition.h"
#include "Condition.h"

class FSM : public Behaviour{
public:
	FSM() : current_state{ nullptr } {}

	std::shared_ptr < Transition> AddTransition(std::shared_ptr <Transition> t) { transitions.push_back(t); return t; };
	std::shared_ptr < Condition> AddCondition(std::shared_ptr < Condition> c) { conditions.push_back(c); return c; };
	std::shared_ptr < State> AddState(std::shared_ptr < State> s) { states.push_back(s); return s; };

	void SetCurrentState(State* state) { current_state = state; }

	// inherited
	//virtual bool Update(std::shared_ptr<Agent> agent, float deltaTime) override;
	virtual bool Update(Agent*  agent, float deltaTime) override;

protected:
	State* current_state;

	std::vector< std::shared_ptr <State>> states;
	std::vector< std::shared_ptr <Transition>> transitions;
	std::vector< std::shared_ptr <Condition>> conditions;


//public:
//	FSM() : current_state{ nullptr } {}
//
//	Transition* AddTransition(Transition* t) { transitions.push_back(t); return t; };
//	Condition* AddTransition(Condition* c) { conditions.push_back(c); return c; };
//	State* AddTransition(State* s) { states.push_back(s); return s; };
//
//	void SetCurrentState(State* state) { current_state = state; }
//
//	// inherited
//	virtual bool Update(Agent* agent, float deltaTime) override;
//
//protected:
//	State* current_state;
//
//	std::vector<State*> states;
//	std::vector<Transition*> transitions;
//	std::vector<Condition*> conditions;


};

