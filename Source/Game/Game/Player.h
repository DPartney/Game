#pragma once
#include "Framework/Actor.h"

class Player : public Actor {
public:
	Player(float speed, float turnRate, const shadow::Transform& transform, const shadow::Model& model) :
		m_speed{ speed },
		m_turnRate{ turnRate },
		Actor{ transform, model }
	{}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnRate = 0;

	
};