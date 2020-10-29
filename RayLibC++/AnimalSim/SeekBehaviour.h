#pragma once
#include "Behaviour.h"

class SeekBehaviour :
	public Behaviour
{
	
	public:
		SeekBehaviour();
		~SeekBehaviour();
		virtual bool Update(Agent* agent, float deltaTime);
		void SetTarget(Agent* agent);
	private:
		float m_speedIncrement = 500.0f; 
		Agent* m_target;
		float seekSpeed = 20;

};

