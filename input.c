#include "./input.h"

void eventLoop(SDL_Event * event, int ticks)
{
	// Event loop
		while(SDL_PollEvent(event))
		{
			
			switch(event->type)
			{
				case SDL_QUIT:
					app.close = 1;
					break;

				case SDL_KEYDOWN:
					switch(event->key.keysym.sym)
					{
						case SDLK_w:
							app.up = 1;
							break;
						case SDLK_a:
							app.left = 1;
							break;
						case SDLK_s:
							app.down = 1;
							break;
						case SDLK_d:
							app.right = 1;
							break;
					}
					break;
				case SDL_KEYUP:
					switch(event->key.keysym.sym)
					{
						case SDLK_w:
							app.up = 0;
							break;
						case SDLK_a:
							app.left = 0;
							break;
						case SDLK_s:
							app.down = 0;
							break;
						case SDLK_d:
							app.right = 0;
							break;
					}
					break;
			}
		}
		// Update player
		if(app.up) player.y -= player.speed_y;
		if(app.down) player.y += player.speed_y;
		if(app.left) player.x -= player.speed_x;
		if(app.right) player.x += player.speed_x;
		if(app.up|| app.left||app.down||app.right ) player.state =1;
		else player.state = 0;
		if(app.left) player.flip = 1;
		if(app.right) player.flip = 0;

		if(player.state == 1) {
			if(ticks < 15) player.frame = 1;
			else if (ticks < 30)player.frame = 2;
			else if(ticks<45) player.frame =1;
			else player.frame = 2;
		}



}
