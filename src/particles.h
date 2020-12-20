#ifndef PARTICLES_H
#define PARTICLES_H

#include <SDL.h>
typedef struct
{
	float x, y;
}vec2;

void vec2zero(vec2 *src);
void vec2set(vec2 *src, float x, float y);
void vec2add(vec2 *v1, vec2 v2);

typedef struct 
{
	SDL_Rect particle;
	vec2 location;
	vec2 velocity;
	vec2 acceleration;
	int lifespan;
}particles_t;

void start_srand();
void particle_start(particles_t *p, float x, float y, float size);

void particle_update(particles_t *p);

void particle_display(particles_t *p, SDL_Surface *display);

#endif