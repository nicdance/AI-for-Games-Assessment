#include "Transition.h"
#include "Condition.h"



//bool Transition::hasTriggered(std::shared_ptr<Agent> agent) const
bool Transition::hasTriggered(Agent* agent) {
	return condition->test(agent);
}
