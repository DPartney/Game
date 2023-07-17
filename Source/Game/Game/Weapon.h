#pragma once
#include "Framework/Actor.h"

class Weapon : public shadow::Actor {
public:
	Weapon(float speed, float turnRate, const shadow::Transform& transform, const shadow::Model& model) :
		m_speed{ speed },
		m_turnrate{ turnRate },
		Actor{ transform, model }
	{}

	void Update(float dt) override;

private:
	float m_speed = 0;
	float m_turnrate = 0;
};