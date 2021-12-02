#ifndef SESSION_H
#define SESSION_H
#include "Sprite.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Spawner.h"
#include <SDL_ttf.h>
#include <string>

//Denna klass motsvarar GameEngine i uppgiftsbeskrivningen
class Session {
public:
	void add(Sprite* sprite);
	void remove(Sprite* sprite);
	void addEnemy(Enemy* enemy);
	void removeEnemy(Enemy* enemy);
	void addBullet(Bullet* bullet);

	void run();
	Player* player; 
	Spawner* spawner;

private:
	std::vector<Sprite*> sprites;
	std::vector<Sprite*> added;
	std::vector<Sprite*> removed;
	std::vector<Enemy*> enemies;
	std::vector<Bullet*> bullets;
	void endGame();
	int score = 0;
	bool gameOver = false;
	
};
extern Session ses;
#endif // !SESSION_H

