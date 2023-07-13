#include "Actor.h"

void Actor::Draw(shadow::Renderer& renderer) {
	m_model.Draw(renderer, m_transform);
}
