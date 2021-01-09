#pragma once
#include "Behaviour.h"
#include "Graph.h"

class PathFollowBehaviour : public Behaviour::Behaviour {
private:
	float m_speed;
	std::vector<Node*> current_path;
	public:
		PathFollowBehaviour(float speed) {
			m_speed = speed;
		}

		void SetPath(const Path& path) {
			current_path.clear();
			current_path.insert(current_path.begin(), path.begin(), path.end());
		}

		bool Update(Agent* agent, float deltaTime) {
			float speed = m_speed;
			if (pathPosition == current_path.size())
			{
				agent->SetVelocity(glm::vec2(0));
				return false;
			}

			glm::vec2 desiredVector = (current_path[pathPosition] - agent->GetPosition());

			if (glm::length(desiredVector) < m_speed* deltaTime)
			{
				pathPosition++;
				speed = glm::length(desiredVector) / deltaTime;
			}
			agent->SetVelocity(glm::normalize(desiredVector)*speed);
		}
};

