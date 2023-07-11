#include "Core/Core.h"
#include"Renderer/Renderer.h"
#include "Renderer/Model.h"
#include "Input/InputSystem.h"
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

	shadow::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	shadow::InputSystem inputSystem;
	inputSystem.Initialize();

	vector<shadow::vec2> points2;
	vector<Star> stars;

	//vector<shadow::vec2> points({ {-10, 5}, { 10, 5 }, { 0, -5 }, { -10, 5 } });
	shadow::Model model;
	model.Load("Quartz.txt");

	shadow::vec2 position {400, 300};
	float speed = 100;

	for (int i = 0; i < 1000; i++)
	{
		shadow::vec2 pos(shadow::vec2(shadow::random(renderer.GetWidth()), shadow::random(renderer.GetHeight())));
		shadow::vec2 vel(shadow::randomf(100, 200), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	// main gmae loop
	bool quit = false;
	while (!quit)
	{
		shadow::g_time.Tick();

		inputSystem.Update();
		if (inputSystem.GetKeyDown(SDL_SCANCODE_ESCAPE)) { quit = true; }
		//if (inputSystem.GetMouseButtonDown(0)) { cout << "Left Clicked!"; }

		shadow::vec2 direction;
		if (inputSystem.GetKeyDown(SDL_SCANCODE_W)) { direction.y = -1; }
		if (inputSystem.GetKeyDown(SDL_SCANCODE_S)) { direction.y = 1; }
		if (inputSystem.GetKeyDown(SDL_SCANCODE_A)) { direction.x = -1; }
		if (inputSystem.GetKeyDown(SDL_SCANCODE_D)) { direction.x = 1; }
		position += direction * speed * shadow::g_time.GetDeltaTime();

		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();

		// draw
		for (auto& star : stars)
		{
			star.Update(renderer.GetWidth(), renderer.GetHeight());
			renderer.SetColor(shadow::random(256), shadow::random(256), shadow::random(256), 255);
			star.Draw(renderer);
		}

		model.Draw(renderer, position, 8.0f);

		renderer.EndFrame();

		//this_thread::sleep_for(chrono::milliseconds(10));
	}
	/*
	shadow::vec2 v{ 5, 5};
	v.Normalize();

	vector<shadow::vec2> points2;
	vector<Star> stars;

	for (int i = 0; i < 1000; i++)
	{
		shadow::vec2 pos(shadow::vec2(shadow::random(renderer.GetWidth()), shadow::random(renderer.GetHeight())));
		shadow::vec2 vel(shadow::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	while (true) {

		// draw
		for (auto& star : stars)
		{
			star.Update(renderer.GetWidth(), renderer.GetHeight());
			renderer.SetColor(shadow::random(256), shadow::random(256), shadow::random(256), 255);
			star.Draw(renderer);
		}
	}
	*/

	return 0;
	/*
	int main() {
		shadow::g_memoryTracker.DisplayInfo();
		int* p = new int;
		shadow::g_memoryTracker.DisplayInfo();
		delete p;
		shadow::g_memoryTracker.DisplayInfo();

		shadow::Time timer;
		for (int i = 0; i < 1000000; i++) {}
		cout << timer.GetElapsedMicroseconds() << endl;
		*/
		/*
		//cout << shadow::GetFilePath() << endl;
				//shadow::SetFilePath("Assets");
				//cout << shadow::GetFilePath() << endl;
				//size_t size;
				//shadow::GetFileSize("game.txt", size);
				//cout << size << endl;
				//std::string s;
				//shadow::ReadFile("game.txt", s);
				//cout << s << endl;
				//shadow::SeedRandom((unsigned int)time(nullptr));
				//for (int i = 0; i < 10; i++)
				//{
				//	cout << shadow::random(1, 2) << endl;
				//}
				//
				*/
}
