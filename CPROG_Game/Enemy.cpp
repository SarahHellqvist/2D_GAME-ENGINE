#include "Enemy.h"
#include "System.h"
#include "Session.h"
#include <SDL_image.h>

//Konstruktor
//Laddar in en bild, maskar bort bakgrunden
Enemy::Enemy(int x, int y) : Sprite(x, y, 35, 105) {
	SDL_Surface* enemySurface = IMG_Load(path);
	SDL_SetColorKey(enemySurface, SDL_TRUE, SDL_MapRGBA(enemySurface->format, 0, 0, 255, 0));
	texture = SDL_CreateTextureFromSurface(sys.ren, enemySurface);
	SDL_FreeSurface(enemySurface);
}

//Tar bort bilden, flyttar rect så den inte kolliderar med oönskat
Enemy::~Enemy() {
	SDL_DestroyTexture(texture);
	rect = { -20000,-20000,0,0 };
}

//Ritar ut bilden
void Enemy::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

//Fiende-logik, åker till vänster, dör om den kommer ur skärmen
void Enemy::tick() {
	counter--;
	if (rect.x < 800) {
		killable = true;
	}
	if (rect.x < 0) {
		ses.remove(this);
	}
	else if (counter % 2 == 0) {
		rect.x -= speed;
	}
}