#include "Session.h"
#include "Spawner.h"


int main(int argc, char** argv) {
	Player* player = new Player();
	ses.player = player;
	ses.add(player);
	Spawner* spawner = new Spawner(800,0,250,600); //Argument borde vara variabel, inte hårdkodad
	ses.spawner = spawner;
	ses.run();
	return 0;
}