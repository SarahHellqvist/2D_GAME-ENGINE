#include "Spawner.h"
#include "Enemy.h"
#include "Session.h"
#include <SDL.h>
#include <stdlib.h>

Spawner::~Spawner() {}

//Lägger till fiender i spelsessionen
void Spawner::tick() {
	counter++;
	if (counter % 60 == 0) {
		Enemy* e = new Enemy((rand() % rect.w) + rect.x, rand() % (rect.h - 105) ); //105 är enemy height
		ses.addEnemy(e);
		ses.add(e);
	}
}