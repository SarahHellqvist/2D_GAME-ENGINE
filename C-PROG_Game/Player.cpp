#include "Player.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "Session.h"
#include "Bullet.h"

Player::Player() : Sprite(5, 300, 75, 75) { //Anger startposition
	texture = IMG_LoadTexture(sys.ren, "C:/Users/46760/Pictures/santa.png");
}

Player::~Player() {
	SDL_DestroyTexture(texture);
	rect = { 20000,200000,0,0 }; //Flyttar för att undvika oönskade kollisioner
}

void Player::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Player::tick() {
	if (hasFired) { //Begränsar hur många skott spelaren kan skjuta
		counter++;
		if (counter % 30 == 0) {
			hasFired = false;
			counter = 0;
		}
	}
}

void Player::move(int i) {
	if (i > 0) { //flytta ner
		if (rect.h + rect.y + i < 600) { //Kolla så att player inte befinner sig vid nederkanten, isåfall får player flytta neråt
			rect.y += (i * speed);
		}
	}
	else { //flytta upp
		if (rect.y + i > 0) { //Kolla så att player inte befinner sig vid överkanten, isåfall får player flytta uppåt
			rect.y += (i * speed);
		}
	}
	
}

//Skjut-logik, skapar bullets via fabriksfunktion
void Player::shoot() {
	if (!hasFired) {
		Bullet* b = Bullet::getInstance(rect.x + rect.w, rect.y);
		ses.add(b);
		ses.addBullet(b);
		hasFired = true;
	}
}
