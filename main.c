#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error in intitialising SDL: %s\n", SDL_GetError());
	}
	SDL_Window* win = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			500, 500, 0);
	int close;
	 while(!close)
	 {
		 SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type){
			case SDL_QUIT:
				close = 1;
				break;
			}
		}
	 }

	return 0;

}
