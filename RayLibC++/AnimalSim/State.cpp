#pragma once
#include "State.h"
#include "Transition.h"


std::shared_ptr<Transition> State::GetTriggeredTransition(std::shared_ptr<Agent> agent) {
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
