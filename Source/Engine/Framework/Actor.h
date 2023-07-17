#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"

namespace shadow {
	class Actor {
	public:
		Actor() = default;
		Actor(const shadow::Transform& transform, const shadow::Model& model) :
			m_transform{ transform },
			m_model{ model }
		{};

		virtual void Update(float dt) = 0; // Abstract Method
		virtual void Draw(shadow::Renderer& renderer);

		class Scene* m_scene = nullptr;

	protected:
		shadow::Transform m_transform;
		shadow::Model m_model;
	};

}