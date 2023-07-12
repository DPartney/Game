#pragma once
#include "Vector2.h"

namespace shadow {

	class Transform {
	public:
		vec2 position;
		float rotation = 0;
		float scale = 1;

		Transform() = default;
		Transform(const vec2& position, float rotation, float scale = 1) :
			position{ position },
			rotation{ rotation },
			scale{ scale }
		{}
	};
}