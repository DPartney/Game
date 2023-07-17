#include "Core/Core.h"
#include"Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Player.h"
#include "Enemy.h"


#include <iostream>
#include <vector>
#include <thread>

using namespace std;

class Star
{
public:
	shadow::vec2 m_pos;
	shadow::vec2 m_vel;

	Star(const shadow::vec2& pos, const shadow::vec2& vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void Update(int width, int height) {
		m_pos += m_vel * shadow::g_time.GetDeltaTime();
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

	void Draw(shadow::Renderer& renderer) {
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}
};

int main(int argc, char* argv[]) {

	shadow::SeedRandom((unsigned int)time(nullptr));
	shadow::SetFilePath("assets");

	shadow::g_renderer.Initialize();
	shadow::g_renderer.CreateWindow("CSC196", 800, 600);

	shadow::g_inputSystem.Initialize();

	shadow::g_audioSystem.Initialize();

	vector<shadow::vec2> points2;
	vector<Star> stars;

	shadow::Model enemy_model;
	shadow::Model player_model;
	enemy_model.Load("Quartz.txt");
	player_model.Load("Cursor.txt");

	shadow::vec2 position {400, 300};
	float speed = 100;

	for (int i = 0; i < 1000; i++)
	{
		shadow::vec2 pos(shadow::vec2(shadow::random(shadow::g_renderer.GetWidth()), shadow::random(shadow::g_renderer.GetHeight())));
		shadow::vec2 vel(shadow::randomf(100, 200), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	shadow::Transform transform{ {400, 300}, 0, 3 };
	float turnRate = shadow::DegToRad(180);

	Player player{ 200, shadow::pi, { {400, 300}, 0, 6 }, player_model };

	std::vector<Enemy> enemies;
	for (int i = 0; i < 25; i++)
	{
		Enemy enemy{ 300, shadow::pi, { {shadow::randomf(800, 1), shadow::randomf(600, 1)}, shadow::randomf(shadow::twoPi), 3}, enemy_model };
		enemies.push_back(enemy);
	}

	// main gmae loop
	bool quit = false;
	while (!quit)
	{
		// Update Engine
		shadow::g_time.Tick();
		shadow::g_inputSystem.Update();
		if (shadow::g_inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) { quit = true; }

		// Update Game
		player.Update(shadow::g_time.GetDeltaTime());
		for (auto& enemy : enemies) enemy.Update(shadow::g_time.GetDeltaTime());

		// draw
		shadow::g_renderer.SetColor(0, 0, 0, 0);
		shadow::g_renderer.BeginFrame();
		for (auto& star : stars)
		{
			star.Update(shadow::g_renderer.GetWidth(), shadow::g_renderer.GetHeight());
			shadow::g_renderer.SetColor(shadow::random(256), shadow::random(256), shadow::random(256), 255);
			star.Draw(shadow::g_renderer);
		}

		player.Draw(shadow::g_renderer);
		for (auto& enemy : enemies) enemy.Draw(shadow::g_renderer);

		shadow::g_renderer.EndFrame();
	}
	return 0;
}
