#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class RenderWindow
{
	public:
		RenderWindow(const char* p_title, int p_w, int p_h);
		SDL_Texture* loadTex(const char* p_filePath);
		void cleanUp();
	private:
		SDL_Window* win;
		SDL_Renderer* rend;
};
