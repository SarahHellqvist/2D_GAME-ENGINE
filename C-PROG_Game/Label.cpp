#include "Label.h"
#include "System.h"
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
using namespace std;

Label::Label(int x, int y, int w, int h, string s) : Sprite(x, y, w, h), text(s){
	SDL_Surface* surf = TTF_RenderText_Solid(sys.font, text.c_str(), { 255,255,255 });
	texture = SDL_CreateTextureFromSurface(sys.ren, surf);
	SDL_FreeSurface(surf);
}

Label::~Label(){
	SDL_DestroyTexture(texture);
}

void Label::draw() const {
	const SDL_Rect& rect = getRect();
	SDL_RenderCopy(sys.ren, texture, NULL, &rect);
}

void Label::tick(){}

string Label::getText() const {
	return text;
}
void Label::setText(string newText) {
	text = newText;
	SDL_DestroyTexture(texture);
	SDL_Surface* surf = TTF_RenderText_Solid(sys.font,
		text.c_str(), { 255,255,255 });
	texture = SDL_CreateTextureFromSurface(sys.ren, surf);
	SDL_FreeSurface(surf);
}



