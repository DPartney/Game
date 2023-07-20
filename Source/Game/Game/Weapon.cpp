#include "Weapon.h"

void Weapon::Update(float dt) {

	Actor::Update(dt);

	shadow::vec2 forward = shadow::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * shadow::g_time.GetDeltaTime();
	m_transform.position.x = shadow::Wrap(m_transform.position.x, (float)shadow::g_renderer.GetWidth());
	m_transform.position.y = shadow::Wrap(m_transform.position.y, (float)shadow::g_renderer.GetHeight());
}

void Weapon::OnCollision(Actor* other)
{
	if (other->m_tag != m_tag)
	{
		m_destroyed = true;
	}
}
