#pragma once
#include <cmath>

namespace shadow {
	const float pi = 3.14159265359f;
	const float twoPi = 6.28318530718f;
	const float halfPi = 1.57079632679f;

	constexpr float RadToDeg(float radians) { return radians * (180.0f / pi); }
	constexpr float DegToRad(float degrees) { return degrees * (pi / 180.0f); }

	constexpr int Wrap(int value, int max) {
		return (value % max) + ((value < 0) ? max : 0);
	}
}