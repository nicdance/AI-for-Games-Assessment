#include "FSM.h"


//bool FSM::Update(std::shared_ptr<Agent> agent, float deltaTime) {
bool FSM::Update(Agent* agent, float deltaTime) {
	if (!current_state) {
		return false;
	}
	std::shared_ptr < Transition> transition = current_state->GetTriggeredTransition(agent);
	if (transition != nullptr)
	{
		current_state->exit(agent);
		current_state = transition->getTargetState();
		current_state->init(agent);
	}
	current_state->update(agent, deltaTime);
	return true;
}