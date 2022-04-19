
#ifndef DRAW_H
	#define DRAW_H
#include "./common.h"
SDL_Texture *  loadTexture(char * filename);
void blit(SDL_Texture * tex, int state, int x, int y, int flp);

extern App app;
#endif
