#pragma once
#include "Behaviour.h"

class SeekBehaviour :
	public Behaviour
{
	
	public:
		SeekBehaviour(const Agent* target, float speed);
		~SeekBehaviour();
		virtual bool Update(Agent* agent, float deltaTime);
		void SetTarget(Agent* agent);
	private:
		float m_speedIncrement = 500.0f; 
		const Agent* m_target;
		float m_speed = 20;

};

