#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

//Abstrakt basklass f�r allt som ska ritas p� sk�rmen
class Sprite {
public:
	//Implementeras bara av player
	virtual void mouseDown (int x, int y){}
	virtual void mouseUp(int x, int y){}
	//Implementeras av alla
	virtual void draw() const = 0;
	virtual void tick() = 0;
	SDL_Rect getRect() const { return rect; }
	SDL_Rect* getRectPtr() const { return rp; }

protected:
	Sprite(int x, int y, int w, int h):rect{x,y,w,h}{}
	SDL_Rect rect; 
	SDL_Rect* rp = &rect;
	SDL_Texture* texture;

private:
	Sprite (const Sprite&) = delete; //F�rbjud copy-konsruktor
	const Sprite& operator=(const Sprite&) = delete; //F�rbjud tilldelningsoperator
};










#endif // !COMPONENT_H

