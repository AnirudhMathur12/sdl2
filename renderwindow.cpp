#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h) : win(NULL), rend(NULL)
{
	win = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h, SDL_WINDOW_SHOWN);
	if(win == NULL)
	{
		std::cout <<"Window failed to init. Error: " << SDL_GetError() << std::endl;
	}

	rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED); 
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(win);
}

