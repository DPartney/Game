#include "Core/Core.h"
#include"Renderer/Renderer.h"
#include "Renderer/ModelManager.h"
#include "Input/InputSystem.h"
#include "Audio/AudioSystem.h"
#include "Framework/Scene.h"
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

	std::unique_ptr<int> up = std::make_unique<int>(10);

	shadow::MemoryTracker::Initialize();
	shadow::SeedRandom((unsigned int)time(nullptr));
	shadow::SetFilePath("assets");

	shadow::g_renderer.Initialize();
	shadow::g_renderer.CreateWindow("CSC196", 800, 600);

	shadow::g_inputSystem.Initialize();

	shadow::g_audioSystem.Initialize();

	shadow::g_audioSystem.AddAudio("LaserShot", "Laser_Shoot.wav");

	vector<shadow::vec2> points2;
	vector<Star> stars;

	

	for (int i = 0; i < 1000; i++)
	{
		shadow::vec2 pos(shadow::vec2(shadow::random(shadow::g_renderer.GetWidth()), shadow::random(shadow::g_renderer.GetHeight())));
		shadow::vec2 vel(shadow::randomf(100, 200), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	shadow::Scene scene;
	unique_ptr<Player> player = make_unique<Player>(200.0f, shadow::pi, shadow::Transform{ {400, 300}, 0, 6 }, shadow::g_manager.Get("Cursor.txt"));
	player->m_tag = "Player";
	scene.Add(std::move(player));

	for (int i = 0; i < 25; i++)
	{
		unique_ptr<Enemy> enemy = make_unique<Enemy>(shadow::randomf(75.0f, 175.0f), shadow::pi, shadow::Transform{ {shadow::randomf(800, 1), shadow::randomf(600, 1)}, shadow::randomf(shadow::twoPi), 3 }, shadow::g_manager.Get("Quartz.txt"));
		enemy->m_tag = "Enemy";
		scene.Add(std::move(enemy));
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
		scene.Update(shadow::g_time.GetDeltaTime());

		// draw
		shadow::g_renderer.SetColor(0, 0, 0, 0);
		shadow::g_renderer.BeginFrame();
		for (auto& star : stars)
		{
			star.Update(shadow::g_renderer.GetWidth(), shadow::g_renderer.GetHeight());
			shadow::g_renderer.SetColor(shadow::random(256), shadow::random(256), shadow::random(256), 255);
			star.Draw(shadow::g_renderer);
		}

		scene.Draw(shadow::g_renderer);

		shadow::g_renderer.EndFrame();
	}
	stars.clear();
	scene.RemoveAll();

	return 0;
}
