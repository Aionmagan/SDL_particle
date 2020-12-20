#include <particles.h>
#include <stdlib.h>
#include <time.h>

void vec2set(vec2 *src, float x, float y)
{
	src->x = x; 
	src->y = y;
}

void vec2zero(vec2 *src)
{
	src->x = 0;
	src->y = 0;
}

void vec2add(vec2 *v1, vec2 v2)
{
	v1->x += v2.x;
	v1->y += v2.y;
}

void start_srand()
{
	srand(time(0));
}

void particle_start(particles_t *p, float x, float y, float size)
{
	//srand(time(0));
	x = x + (rand()% 40) - 20;
	//y = y + (rand()% 10) - 5;
	p->particle.w = p->particle.h = size;
	vec2set(&p->location, x, y);
	vec2set(&p->acceleration, 0, (float)rand()/4500 / 75.5f);//vec2set(&p->acceleration, 0, (float)rand()/4500 / 105.5f);
	vec2set(&p->velocity, (rand() % 3) - 1  , (rand() % 2) - 1 );
	p->lifespan = rand() % 255 + 50;
	//printf("%f, %d\n", (float)rand()/4500 / 6.5f  , (rand() % 2) - 1 );
}

void particle_update(particles_t *p)
{
	vec2add(&p->velocity, p->acceleration);
	vec2add(&p->location, p->velocity);
	p->particle.x = p->location.x;
	p->particle.y = p->location.y;
	p->lifespan -= 2;
}

void particle_display(particles_t *p, SDL_Surface *display)
{
	SDL_FillRect(display, &p->particle, SDL_MapRGB(display->format, 100, p->lifespan, p->lifespan));
}