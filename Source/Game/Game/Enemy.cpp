#include "Enemy.h"
#include "Player.h"
#include "Weapon.h"
#include "Framework/Scene.h"

void Enemy::Update(float dt) {

	Actor::Update(dt);

	Player* player = m_scene->GetActor<Player>();
	if (player)
	{
		shadow::Vector2 direction = player->m_transform.position - m_transform.position;
		m_transform.rotation = direction.Angle() + shadow::halfPi;
	}

	shadow::vec2 forward = shadow::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * shadow::g_time.GetDeltaTime();
	m_transform.position.x = shadow::Wrap(m_transform.position.x, (float)shadow::g_renderer.GetWidth());
	m_transform.position.y = shadow::Wrap(m_transform.position.y, (float)shadow::g_renderer.GetHeight());


	m_fireTimer -= dt;
	if (m_fireTimer <= 0)
	{
		shadow::Transform transform{m_transform.position, m_transform.rotation, 1};
		std::unique_ptr<Weapon> weapon = std::make_unique<Weapon>(400.0f, transform, m_model);
		m_scene->Add(std::move(weapon));
		m_fireTimer = m_fireRate;
	}



}