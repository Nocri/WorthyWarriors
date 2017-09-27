#include "GameController.h"

GameController::~GameController()
{
}

GameController::GameController(int windowHeight, int windowWidth,
	const char* windowName, int antialiasing, int maxProjectles, int maxCoins, int maxEnemies) 
	: MAX_COINS(maxCoins), MAX_ENEMIES(maxEnemies), MAX_PROJECTLES(maxProjectles) {
	player = new Player(windowWidth / 2, windowHeight / 2, 0);
	Weapon* startWeapon = new WeakWeapon();
	weapons.push_back(startWeapon);
	player->pickWeapon(startWeapon);
	engine = new SfmlEngine(windowHeight, windowWidth, windowName, antialiasing);
	engine->addListener(this);
};

