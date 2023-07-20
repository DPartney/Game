#pragma once
#include "Framework/Actor.h"

class Player : public shadow::Actor {
public:
	Player(float speed, float turnRate, const shadow::Transform& transform, std::shared_ptr<shadow::Model> model) :
		m_speed{ speed },
		m_turnRate{ turnRate },
		Actor{ transform, model }
	{}

	void Update(float dt) override;
	void OnCollision(Actor* other) override;

private:
	float m_speed = 0;
	float m_turnRate = 0;
	float m_health = 100;
};