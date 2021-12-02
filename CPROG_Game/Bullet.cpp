#include "Bullet.h"
#include <SDL_image.h>
#include "Sprite.h"
#include "System.h"
#include "Session.h"

//Maskar ut en bild för att bli av med bakgrunden
Bullet::Bullet(int x, int y) : Sprite(x, y, 35, 35) {
	SDL_Surface* bulletSurface = IMG_Load("C:/Users/46760/Pictures/snowball.png");
	SDL_SetColorKey(bulletSurface, SDL_TRUE, SDL_MapRGBA(bulletSurface->format, 0, 0, 0, 0));
	texture = SDL_CreateTextureFromSurface(sys.ren, bulletSurface);
	SDL_FreeSurface(bulletSurface);
}

Bullet::~Bullet() {
	SDL_DestroyTexture(texture);
	rect = { -1,-1,0,0 }; //Flyttar rect för att undvika oönskade kollisioner
}

void Bullet::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

//Bullet-logik
void Bullet::tick() {
	counter++;
	if (rect.x > 800) {
		ses.remove(this);
	}
	else if(counter % 2 == 0) {
		rect.x+=10;
	}
}

Bullet* Bullet::getInstance(int x, int y) {
	return new Bullet(x, y);
}