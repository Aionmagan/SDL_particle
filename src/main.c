#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <math.h>
#include <Windows.h>
#include "particles.h"
#define SCRN_WIDTH 640
#define SCRN_HEIGHT 480

int main(int argc, char **argv)
{
	SDL_Surface *display = NULL;
	unsigned int isDown = 0;
	uint8_t *key = NULL;
	SDL_Rect rect;
	int i, p_limit = 255;
	float x, y, mvnt = 10, mv = 10;
	particles_t particles[255];
	
	rect.w = rect.h = 32;
	rect.x = rect.y = 300;
	
	if((SDL_Init(SDL_INIT_VIDEO)) != 0){return -1;}
	
	//srand(time(0));
	//IMG_Init(IMG_INIT_JPG);
	
	display = SDL_SetVideoMode(SCRN_WIDTH, SCRN_HEIGHT, 32, SDL_SWSURFACE);
	//texture = IMG_Load("texture.jpg");

	key = SDL_GetKeyState(NULL);
    start_srand();
	for(i = 0; i < 255; ++i)
	{
		particle_start(&particles[i], 300, 40, 12);
	}

	//texture_buff = (Uint32 *) display->pixels;
	while(1)
	{
		if(key[SDLK_ESCAPE]){break;}
		if(key[SDLK_UP] && !isDown){p_limit++;}
		if(key[SDLK_DOWN] && !isDown){p_limit--;}
		
		if(p_limit > 254){p_limit = 254;}
		if(p_limit < 5){p_limit = 5;}
		
		//SDL_GetMouseState(&x, &y);
		x = 229 * cosf(mvnt) + 300;
		y = 139 * sinf(mv) + 200;
		if(!(key[SDLK_UP] || key[SDLK_LEFT]) && isDown){isDown = 0;}
		
		for(i = p_limit; i >= 0; --i)
		{
			if(particles[i].lifespan > 1)
			{
				particle_update(&particles[i]);
				particle_display(&particles[i], display);
			}else{
				particle_start(&particles[i], x, y, 12);
			}
		}

		SDL_Flip(display);
		
		SDL_FillRect(display, NULL, SDL_MapRGB(display->format, 0, 0, 0));
		
		SDL_PumpEvents();//get keyboard input;
		
		Sleep(8);
		
		mvnt += 0.05f;
		mv += 0.1f;
	}
	
	SDL_Quit();
	return 0;
}

