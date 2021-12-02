#ifndef ENEMY_H
#define ENEMY_H
#include "Sprite.h"

class Enemy : public Sprite {
public:
	Enemy(int x, int y);
	~Enemy();
	void draw() const;
	void tick();
	SDL_Rect getRect() const { return rect; }
	bool isKillable() const { return killable; } 
private:
	int speed = 2; //Hastighet
	int counter = 800; //Används för logik
	bool killable = false; //Börjar som odödlig, så den inte dör offscreen
	const char* path = "C:/Users/46760/Pictures/grinch.png"; //Path till bilden
};
#endif // !ENEMY_H

