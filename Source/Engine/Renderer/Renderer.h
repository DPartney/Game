#pragma once
#include <SDL2-2.28.1/include/SDL.h>
#include <string>

namespace shadow {


	class Renderer {
	public:
		Renderer() = default;
		~Renderer() = default;

		bool Initialize();
		void Shutdown();

		void CreateWindow(const std::string& title, int width, int height);
		void BeginFrame();
		void EndFrame();

		void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
		void DrawLine(int x1, int y1, int x2, int y2);
		void DrawLine(float x1, float y1, float x2, float y2);
		void DrawPoint(int x1, int y1);
		void DrawPoint(float x1, float y1);

		int GetWidth() const { return m_width; }
		int GetHeight() const { return m_height; }

	private:
		int m_width = 0, m_height = 0;
		SDL_Renderer* m_renderer = nullptr;
		SDL_Window* m_window = nullptr;
	};

	extern Renderer g_renderer;
}
