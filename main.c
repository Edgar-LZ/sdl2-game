#include "./main.h"
#include <stdlib.h>
int main()
// Compile with:
//  gcc main.c init.c draw.c input.c `sdl2-config --libs --cflags` -ggdb3 -O0 --std=c99 -Wall -lSDL2_image -lm
{

	memset(&app, 0, sizeof(App));
	memset(&player, 0, sizeof(Entity));
	if(initializeSDL()!= 0)
	{
		printf("Error initializing\n");
		return 1;
	}

	SDL_Texture * tiles = loadTexture("assets/grass.png");

	// Load the image into memory using SDL_image library function
	player.tex = loadTexture("assets/human.png");
	if(!player.tex) return 1;

	// Position for sprite in the center 
	player.x = (WINDOW_WIDTH - SHAPE_SIZE ) / 2;
	player.y = (WINDOW_HEIGHT - SHAPE_SIZE) / 2;
	player.speed_y = 2;
	player.speed_x = 2;

	// load an image into memory using SDL_image library function

	SDL_Event event;
	int ticks = 0;
	// Main game loop
	SDL_Rect src;
	SDL_Rect dest;
	src.x = 0;
	src.y = 0;
	src.w = SHAPE_SIZE*2;
	src.h = SHAPE_SIZE*2;
	dest.w = SHAPE_SIZE*2;
	dest.h = SHAPE_SIZE*2;
	SDL_Texture* map = SDL_CreateTexture(app.rend, SDL_PIXELFORMAT_RGBA8888,
									 SDL_TEXTUREACCESS_TARGET, WINDOW_WIDTH, 
											WINDOW_HEIGHT);
	SDL_SetRenderTarget(app.rend, map);
	for(int i=0; i<WINDOW_HEIGHT/2;++i ){
			for(int j=0; j<WINDOW_WIDTH/2; j++) {
				src.x = rand()%3 * SHAPE_SIZE;
				dest.x = SHAPE_SIZE*j*2;
				dest.y = SHAPE_SIZE*i*2;
				SDL_RenderCopy(app.rend, tiles, &src, &dest );
			}
		}
	SDL_SetRenderTarget(app.rend, NULL);
	dest.x = 0;
	dest.y = 0;
	dest.w = WINDOW_WIDTH;
	dest.h = WINDOW_HEIGHT;
	while (!app.close)
	{
		ticks = (ticks > 59) ? 0 : ticks+1;		
		eventLoop(&event, ticks);

		// Clear renderer
		SDL_RenderClear(app.rend);
		// Draw image

		SDL_RenderCopy(app.rend, map, NULL, &dest );
		blit(player.tex, player.state*player.frame, player.x, player.y,
			 player.flip);

		SDL_RenderPresent(app.rend);

		SDL_Delay(1000/60);
	}

	SDL_DestroyTexture(player.tex);
	SDL_DestroyTexture(tiles);
	SDL_DestroyRenderer(app.rend);
	SDL_DestroyWindow(app.win);
	SDL_Quit();

	return 0;
}

