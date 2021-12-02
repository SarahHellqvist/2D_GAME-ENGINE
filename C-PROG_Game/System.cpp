#include "System.h"
#include <SDL.h>
#include <SDL_image.h>


System::System() {
	SDL_Init(SDL_INIT_EVERYTHING);
	//Fönster
	win = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
	ren = SDL_CreateRenderer(win, -1, 0);
	//Ljud
	Mix_OpenAudio(20050, AUDIO_S16SYS, 2, 4096);
	music = Mix_LoadWAV("C:/Users/46760/Music/bgMusicBra.mp3");
	Mix_PlayChannel(1, music, -1);
	Mix_Volume(1, 12);
	playerDeath = Mix_LoadWAV("C:/Users/46760/Music/santaDead.wav");
	enemyDeath = Mix_LoadWAV("C:/Users/46760/Music/grinchDead.wav");
	bulletHit = Mix_LoadWAV("C:/Users/46760/Music/snowballHit.wav");
	//Font
	TTF_Init();
	font = TTF_OpenFont("D:/Files/Fonts/Century_Gothic.ttf", 36);
	
}

System::~System() {
	TTF_CloseFont(font);
	TTF_Quit();
	Mix_FreeChunk(music);
	Mix_FreeChunk(playerDeath);
	Mix_FreeChunk(enemyDeath);
	Mix_FreeChunk(bulletHit);
	Mix_CloseAudio();
	SDL_DestroyWindow(win);
	SDL_DestroyRenderer(ren);
	SDL_Quit();
}

System sys;
