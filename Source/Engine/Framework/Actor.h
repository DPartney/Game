#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"
#include <memory>

namespace shadow {
	class Actor {
	public:
		Actor() = default;
		Actor(const shadow::Transform& transform, std::shared_ptr<Model> model) :
			m_transform{ transform },
			m_model{ model }
		{};

		virtual void Update(float dt); // Abstract Method
		virtual void Draw(shadow::Renderer& renderer);

		float GetRadius() { return m_model->GetRadius() * m_transform.scale; }
		virtual void OnCollision(Actor* other) {};

		class Scene* m_scene = nullptr;
		friend class Scene;

		shadow::Transform m_transform;
		std::string m_tag;

	protected:
		bool m_destroyed = false;
		float m_lifespan = -1.0f;
		std::shared_ptr<Model> m_model;
	};

}