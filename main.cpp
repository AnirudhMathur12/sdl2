#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

int main(int argv, char* args[])
{
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL_INIT FAILED: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "yeh" << std::endl;
	}

	if(!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "IMG_Init has failed. Error: " << SDL_GetError() << std::endl;
	}
	else
	{
		std::cout << "oh yeh" << std::endl;
	}

	RenderWindow window("Game", 960, 540);

	bool gameRunning = true;
	SDL_Event event;

	SDL_Texture* sedLinus = window.loadTex("res/monke.png");

	while(gameRunning)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				gameRunning = false;
				std::cout << "o keh\n";
			}
		}

		window.clear();
		window.render(sedLinus);
		window.display();
	}

	window.cleanUp();
	SDL_Quit();
	return 0;
}
