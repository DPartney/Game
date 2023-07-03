#include <iostream>
#include "Core/Random.h"
#include "Core/FileIO.h"
#include "Core/Memory.h"
#include "Core/Time.h"
#include"Renderer/Renderer.h"

using namespace std;



int main() {
	shadow::g_memoryTracker.DisplayInfo();
	int* p = new int;
	shadow::g_memoryTracker.DisplayInfo();
	delete p;
	shadow::g_memoryTracker.DisplayInfo();

	shadow::Time timer;
	for (int i = 0; i < 1000000; i++) {}
	cout << timer.GetElapsedMicroseconds() << endl;

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
}