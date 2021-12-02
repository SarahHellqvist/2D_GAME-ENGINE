#ifndef LABEL_H
#define LABEL_H
#include "Sprite.h"
#include <string>
#include <SDL.h>

//Klass för att visa text på skärmen, likt föreläsning
class Label : public Sprite {
public:
	Label(int x, int y, int w, int h, std::string s);
	~Label();
	void draw() const;
	void tick();
	std::string getText() const;
	void setText(std::string newText);
private:
	std::string text;
	SDL_Texture* texture;
	
};
#endif // !LABEL_H

