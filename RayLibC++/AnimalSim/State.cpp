#pragma once
#include "State.h"
#include "Transition.h"


//std::shared_ptr<Transition> State::GetTriggeredTransition(shared_ptr<Agent> agent) {
std::shared_ptr<Transition> State::GetTriggeredTransition(Agent * agent) {
//Transition* State::GetTriggeredTransition(Agent* agent) {
	for (auto& transition : transitions) {
		if (transition->hasTriggered(agent))
		{
			//return transition.get();
			return transition;
		}
	}
	return nullptr;
}
