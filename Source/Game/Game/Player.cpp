#include "Player.h"
#include "Weapon.h"
#include "Framework/Scene.h"
#include "Input/InputSystem.h"

void Player::Update(float dt) {
	float rotate = 0;
	if (shadow::g_inputSystem.GetKeyDown(SDL_SCANCODE_A)) { rotate = -1; }
	if (shadow::g_inputSystem.GetKeyDown(SDL_SCANCODE_D)) { rotate = 1; }
	m_transform.rotation += rotate * m_turnRate * shadow::g_time.GetDeltaTime();

	float thrust = 0;
	if (shadow::g_inputSystem.GetKeyDown(SDL_SCANCODE_W)) { thrust = 1; }

	shadow::vec2 forward = shadow::vec2{ 0, -1 }.Rotate(m_transform.rotation);
	m_transform.position += forward * m_speed * thrust * shadow::g_time.GetDeltaTime();
	m_transform.position.x = shadow::Wrap(m_transform.position.x, (float)shadow::g_renderer.GetWidth());
	m_transform.position.y = shadow::Wrap(m_transform.position.y, (float)shadow::g_renderer.GetHeight());

	// fire weapon
	if (shadow::g_inputSystem.GetKeyDown(SDL_SCANCODE_SPACE) && !shadow::g_inputSystem.GetMousePreviousButtonDown(SDL_SCANCODE_SPACE)) {
		
		//create weapon
		shadow::Transform transform{m_transform.position, m_transform.rotation, 1};
		Weapon* weapon = new Weapon{ 400, transform, m_model };
		m_scene->Add(weapon);
	}

}
