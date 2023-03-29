#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>

#define WIN_LEN 1280
#define WIN_WID 720

int main(int argc, char *argv[])
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error in intitialising SDL: %s\n", SDL_GetError());
	}

	IMG_Init(IMG_INIT_JPG);
	SDL_Window* win = SDL_CreateWindow("Game",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			500, 500, 0);

	Uint32 render_flags = SDL_RENDERER_ACCELERATED;

	SDL_Renderer* rend = SDL_CreateRenderer(win, -1, 0);

	SDL_Surface* surface = IMG_Load("/User/anuragmathur/Downloads/sadlinus.jpeg");
	//SDL_RWops *rwop;
	//rwop = SDL_RWFromFile("/Users/anuragmathur/Downloads/tworky.gif", "rb");
	//surface = IMG_LoadGIF_RW(rwop);
	
	//surface = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_ANYFORMAT);

	SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
	SDL_FreeSurface(surface);

	SDL_Rect boi;

	SDL_QueryTexture(tex, NULL, NULL, &boi.w, &boi.h);

	boi.w /= 6;
	boi.h /= 6;

	boi.x = (WIN_WID - boi.w)/2;
	boi.y = (WIN_LEN - boi.y)/2;

	int close = 0;
	while(!close)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_QUIT:
					close = 1;
					break;
			}
		}
		
		SDL_RenderClear(rend);
		SDL_RenderCopy(rend, tex, NULL, NULL);
        	
		SDL_RenderPresent(rend);
	}

	SDL_DestroyTexture(tex);
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);
	IMG_Quit();

	return 0;

}
