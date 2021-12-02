#include "Session.h"
#include "Sprite.h"
#include "System.h"
#include "Enemy.h"
#include "Label.h"
#include <vector>
#include <SDL.h>
#include <typeinfo>
#include <iostream>
#define FPS 60
using namespace std;


void Session::add(Sprite* sprite){
	added.push_back(sprite);
}

void Session::remove(Sprite* sprite) {
	removed.push_back(sprite);
}

void Session::addEnemy(Enemy* enemy) {
	enemies.push_back(enemy);
}

void Session::addBullet(Bullet* bullet) {
	bullets.push_back(bullet);
}


void Session::run() {
	bool running = true;
	Uint32 tickInterval = 1000 / FPS; //En unsigned int har bara positiva tal, vilket g�r att hela bit-rangen anv�nds f�r att representera ett positivt tal, s� en unsigned int kan vara mkt st�rre �n en vanlig int
	const Uint8* keyState = SDL_GetKeyboardState(NULL);
	SDL_bool collision;
	Label* scoreLabel = new Label(700, 5, 50, 36, "0");
	add(scoreLabel);
	SDL_Texture* bg = IMG_LoadTexture(sys.ren, "C:/Users/46760/Pictures/BG_03.png");
	const SDL_Rect& rect = { 0, 0, 800, 600 };
	

	while (running) {
		Uint32 nextTick = SDL_GetTicks() + tickInterval; //Ser till att spelet k�rs i r�tt FPS
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;

			case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_SPACE) {

					player->shoot();
				}
				break;
			}	
		}

		SDL_PumpEvents(); //uppdaterar listan med keystates, m�rker om n�got har tryckts p� (utanf�r en eventlistener)
		if (keyState[SDL_SCANCODE_DOWN]) {
			player->move(1);
		}

		if (keyState[SDL_SCANCODE_UP]) {
			player->move(-1);
		}
		
		//Kollisions-detektering
		for (Enemy* e : enemies) {
			collision = SDL_HasIntersection(e->getRectPtr(), player->getRectPtr()); //Kollision mellan player och enemy
			if (collision) {
				Mix_PlayChannel(2, sys.playerDeath, 0);
				player->~Player();
				gameOver = true; //Flagga f�r saker att skippa efter spelaren d�r
				endGame(); //Visar slutsk�rm
			}
			for (Bullet* b : bullets) {
				collision = SDL_HasIntersection(e->getRectPtr(), b->getRectPtr()); //Kollision mellan enemy och bullet
				if (collision && e->isKillable()) { //Enemy �r killable n�r den �r p� sk�rmen
					score++;
					scoreLabel->setText(to_string(score)); //L�gg till po�ng till spelarens score
					remove(e);
					Mix_PlayChannel(3, sys.enemyDeath, 0); //L�gg till fiender och bullets i borttagningslistan, spela upp d�dsljud
					remove(b);
					Mix_PlayChannel(4, sys.bulletHit, 0);
					for (vector<Enemy* >::iterator i = enemies.begin(); i != enemies.end(); ) { //Kopierad borttagning
						if (*i == e) {
							i = enemies.erase(i);
						}
						else {
							i++;
						}
					}
					for (vector<Bullet* >::iterator i = bullets.begin(); i != bullets.end(); ) { //Kopierad borttagning
						if (*i == b) {
							i = bullets.erase(i);
						}
						else {
							i++;
						}
					}
				}
			}
		}
		
		//Anropa tick om spelaren inte f�rlorat
		if(!gameOver) {
			for (Sprite* s : sprites) {
				s->tick();
			}

			spawner->tick();
		}

		//L�gg till adderade sprites i sprites-listan
		for (Sprite* s : added) {
			sprites.push_back(s);
		}
		//Sen rensa adderade-listan
		added.clear();

		//Ta bort sprites som inte ska vara med i sprites-listan l�ngre
		for (Sprite* s : removed) {
			for (vector<Sprite* >::iterator i = sprites.begin(); i != sprites.end(); ) { //Blivit kopierad p� andra st�llen, g�r om till funktion?
				if (*i == s) {
					i = sprites.erase(i);
				}
				else {
					i++;
				}
			}
		}
		//Sen rensa borttagningslistan
		removed.clear();

		//Uppdatera bilden
		SDL_SetRenderDrawColor(sys.ren, 0, 0, 0, 255);
		SDL_RenderClear(sys.ren);

		//L�gg till bakgrundsbild om spelaren inte f�rlorat
		if(!gameOver)
			SDL_RenderCopy(sys.ren, bg, NULL, &rect);

		//Anropar alla ritfunktioner
		for (Sprite* s : sprites) {
			s->draw();
		}
		//Uppdatera bilden
		SDL_RenderPresent(sys.ren);

		//V�nta ifall programmet kommer hit snabbare �n frameraten, i s� fall v�nta
		int delay = nextTick - SDL_GetTicks();
		if (delay > 0) {
			SDL_Delay(delay);
		}
	}

}

//Visar slutsk�rm
void Session::endGame(){
	
	for (auto s : sprites) {
		remove(s);
	}
	Label* gameOverTxt = new Label(250, 150, 300, 72, "GAME OVER");
	add(gameOverTxt);
	Label* finalScoreTxt = new Label(300, 250, 200, 72, "Score: " + to_string(score));
	add(finalScoreTxt);
		
}
Session ses;