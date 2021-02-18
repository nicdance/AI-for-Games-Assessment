#pragma once
#include "Behaviour.h"

class SeekBehaviour :
	public Behaviour
{
	
	public:
		SeekBehaviour(std::shared_ptr<Agent> target, float speed);
		~SeekBehaviour();
		//virtual bool Update(std::shared_ptr<Agent> agent, float deltaTime);
		virtual bool Update(Agent* agent, float deltaTime);
		void SetTarget(std::shared_ptr<Agent> agent);
	protected:
		float m_speedIncrement = 500.0f; 
		std::shared_ptr<Agent> m_target;
		float m_speed = 20;

};

