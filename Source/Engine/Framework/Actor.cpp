#include "Actor.h"
namespace shadow {
	void Actor::Update(float dt)
	{
		if (m_lifespan != -1) {
			m_lifespan -= dt;
			m_destroyed = (m_lifespan <= 0);
		}
	}

	void Actor::Draw(shadow::Renderer& renderer) {
		m_model.Draw(renderer, m_transform);
	}
}
