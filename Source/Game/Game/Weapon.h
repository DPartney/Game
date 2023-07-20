#pragma once
#include "Framework/Actor.h"

class Weapon : public shadow::Actor {
public:
	Weapon(float speed, const shadow::Transform& transform, std::shared_ptr<shadow::Model> model) :
		m_speed{ speed },
		Actor{ transform, model }
	{
		m_lifespan = 2.0f;
	}

	void Update(float dt) override;
	void OnCollision(Actor* other) override;

private:
	float m_speed = 0;
	float m_turnrate = 0;
};