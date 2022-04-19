#include "./init.h"

int initializeSDL(void) 
{
	// Initialize Graphics and timer
	if ((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) != 0)) 
	{
		printf("Error initializing SDL: %s\n", SDL_GetError());
		return 1;
	}
	app.win  = SDL_CreateWindow("game1",
									 SDL_WINDOWPOS_CENTERED,
									 SDL_WINDOWPOS_CENTERED,
									 WINDOW_WIDTH, WINDOW_HEIGHT,0);
	if (!app.win)
	{
		printf("Error creating window: %s\n",SDL_GetError());
		SDL_Quit();
		return 1;
	}
	// Create renderer, which sets up graphics hardware
	Uint32 render_flags = SDL_RENDERER_ACCELERATED;
	app.rend = SDL_CreateRenderer(app.win, -1, render_flags);
	if (!app.rend)
	{
		printf("Error creating renderer: %s\n", SDL_GetError());
		SDL_DestroyWindow(app.win);
		SDL_Quit();
		return 1;
	}
	return 0;
}
