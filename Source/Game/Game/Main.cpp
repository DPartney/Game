#include "Core/Core.h"
#include"Renderer/Renderer.h"
#include <iostream>
#include <vector>

using namespace std;

class Star
{
public:
	shadow::Vector2 m_pos;
	shadow::Vector2 m_vel;

	Star(const shadow::Vector2& pos, const shadow::Vector2& vel) :
		m_pos{ pos },
		m_vel{ vel }
	{}

	void Update(int width, int height) {
		m_pos += m_vel;
		if (m_pos.x >= width) m_pos.x = 0;
		if (m_pos.y >= height) m_pos.y = 0;
	}

	void Draw(shadow::Renderer& renderer) {
		renderer.DrawPoint(m_pos.x, m_pos.y);
	}
};

int main(int argc, char* argv[])
{


	shadow::Renderer renderer;
	renderer.Initialize();
	renderer.CreateWindow("CSC196", 800, 600);

	vector<shadow::Vector2> points;
	vector<Star> stars;

	for (int i = 0; i < 1000; i++)
	{
		shadow::Vector2 pos(shadow::Vector2(shadow::random(renderer.GetWidth()), shadow::random(renderer.GetHeight())));
		shadow::Vector2 vel(shadow::randomf(1, 4), 0.0f);
		stars.push_back(Star(pos, vel));
	}

	while (true) {
		renderer.SetColor(0, 0, 0, 0);
		renderer.BeginFrame();
		// draw
		for (auto& star : stars)
		{
			star.Update(renderer.GetWidth(), renderer.GetHeight());
			renderer.SetColor(shadow::random(256), shadow::random(256), shadow::random(256), 255);
			star.Draw(renderer);
		}

		/*for (int i = 0; i < 1000; i++)
		{
			shadow::Vector2 pos(shadow::random(renderer.GetWidth(), shadow::random(renderer.GetHeight())));

			renderer.SetColor(shadow::random(256), shadow::random(256), shadow::random(256), 255);
			renderer.DrawPoint(pos.x, pos.y);
		}*/
		//renderer.DrawLine(shadow::random(renderer.GetHeight()), shadow::random(renderer.GetHeight()), shadow::random(renderer.GetHeight()), shadow::random(renderer.GetHeight()));

		renderer.EndFrame();
	}

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