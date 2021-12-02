#ifndef BULLET_H
#define BULLET_H
#include <SDL.h>
#include <SDL_image.h>
#include "Sprite.h"

class Bullet : public Sprite {
public:
	Bullet(int x, int y);
	~Bullet();
	void draw() const;
	void tick();
	SDL_Rect getRect() const { return rect; }
	static Bullet* getInstance(int x, int y); //Fabriksfunktion

private:
	int counter = 0;
};

#endif // !BULLET_H

