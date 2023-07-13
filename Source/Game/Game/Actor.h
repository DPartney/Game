#pragma once
#include "Core/Core.h"
#include "Renderer/Model.h"

class Actor {
public:
	Actor() = default;
	Actor(const shadow::Transform& transform, const shadow::Model& model) :
		m_transform{ transform },
		m_model{ model }
	{}

	virtual void Update(float dt) = 0; // Abstract Method
	virtual void Draw(shadow::Renderer& renderer);


protected:
	shadow::Transform m_transform;
	shadow::Model m_model;
};