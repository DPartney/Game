#pragma once
#include "Framework/Actor.h"

class Enemy : public shadow::Actor {
public:
	Enemy(float speed, float turnRate, const shadow::Transform& transform, std::shared_ptr<shadow::Model> model) :
		m_speed{ speed },
		m_turnrate{ turnRate },
		Actor{ transform, model }
	{
		m_fireRate = 4.0f;
		m_fireTimer = m_fireRate;
	}

	void Update(float dt) override;
	void OnCollision(Actor* other) override;

private:
	float m_speed = 0;
	float m_turnrate = 0;
	float m_fireRate = 0;
	float m_fireTimer = 0;
};