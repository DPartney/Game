#pragma once
#include "Actor.h"

class Enemy : public Actor {
public:
	Enemy(float speed, float turnRate, const shadow::Transform& transform, const shadow::Model& model) :
		m_speed{ speed },
		m_turnrate{ turnRate },
		Actor{ transform, model }
	{}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnrate = 0;
};