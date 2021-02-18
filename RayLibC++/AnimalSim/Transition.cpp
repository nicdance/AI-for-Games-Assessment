#include "Transition.h"
#include "Condition.h"



bool Transition::hasTriggered(std::shared_ptr<Agent> agent) const{
	return condition->test(agent);
}
