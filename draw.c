#include "./draw.h"

SDL_Texture *  loadTexture(char * filename)
{
	SDL_Surface * surface = IMG_Load(filename);

	if(!surface)
	{
		printf("Error creating surface\n");
		SDL_DestroyRenderer(app.rend);
		SDL_DestroyWindow(app.win);
		SDL_Quit();
		return NULL;
	}


	SDL_SetColorKey(surface, SDL_TRUE,	
		SDL_MapRGB(surface -> format, 0, 255, 255)); // Color key
	
	

	// Load image data into the graphic's hardware memory
	SDL_Texture * tex = SDL_CreateTextureFromSurface(app.rend, surface);
	SDL_FreeSurface(surface);
	if(!tex)
	{
		printf("Error creating texture: %s\n", SDL_GetError());
		SDL_DestroyRenderer(app.rend);
		SDL_DestroyWindow(app.win);
		SDL_Quit();
		return NULL;
	}

	return tex;
}

void blit(SDL_Texture * tex, int state, int x, int y, int flp)
{
	// Struct to hold the position and size of the sprite
	SDL_Rect dest;
	SDL_Rect src;

	src.x = state*SHAPE_SIZE;
	src.y = 0;
	src.w = SHAPE_SIZE;
	src.h= SHAPE_SIZE;
	dest.x =x;
	dest.y =y;
	dest.w = SHAPE_SIZE*2;
	dest.h = SHAPE_SIZE*2;
	SDL_RendererFlip flip = SDL_FLIP_NONE;
	if(flp) flip = SDL_FLIP_HORIZONTAL;
	SDL_RenderCopyEx(app.rend, tex, &src, &dest, 0,NULL, flip);

}
