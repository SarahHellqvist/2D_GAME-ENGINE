#ifndef SPAWNER_H
#define SPAWNER_H
#include <SDL.h>

//Klass som generar fiender
class Spawner {
public:
	Spawner(int x, int y, int w, int h) :rect{ x,y,w,h } {}
	~Spawner();
	void tick();
	SDL_Rect getRect() const { return rect; }

private:
	SDL_Rect rect;
	int counter = 0;
};

#endif // !SPAWNER_H