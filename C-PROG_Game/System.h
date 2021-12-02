#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL_mixer.h>
#include <SDL.h>
#include <SDL_ttf.h>

struct System{
	System();
	~System();

	//Fönster och renderare
	SDL_Window* win;
	SDL_Renderer* ren;

	//Ljud
	Mix_Chunk* music;
	Mix_Chunk* playerDeath;
	Mix_Chunk* enemyDeath;
	Mix_Chunk* bulletHit;

	//Egen font
	TTF_Font* font;
};
extern System sys;

#endif // !SYSTEM_H

