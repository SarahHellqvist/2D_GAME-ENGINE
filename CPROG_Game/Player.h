#ifndef PLAYER_H
#define PLAYER_H
#include "Sprite.h"

class Player : public Sprite {
public:
	Player();
	~Player();
	void draw() const;
	void tick();
	SDL_Rect getRect() const { return rect; }
	void move(int i);
	void shoot();

private:
	int speed = 10; //Hastighet
	int counter = 0; //Anv�nds f�r spelar-logik
	bool hasFired = false; //Flagga f�r om spelaren skjutit
};

#endif // !PLAYER_H

