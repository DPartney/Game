#pragma once
#include "Framework/Actor.h"

class Weapon : public shadow::Actor {
public:
	Weapon(float speed, const shadow::Transform& transform, const shadow::Model& model) :
		m_speed{ speed },
		Actor{ transform, model }
	{
		m_lifespan = 2.0f;
	}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnrate = 0;
};