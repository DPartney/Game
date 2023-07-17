#include "Actor.h"
namespace shadow {
	void Actor::Draw(shadow::Renderer& renderer) {
		m_model.Draw(renderer, m_transform);
	}
}
