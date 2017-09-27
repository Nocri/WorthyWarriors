#include "GameController.h"

GameController::~GameController()
{
}

GameController::GameController(int windowHeight, int windowWidth,
	const char* windowName, int antialiasing, int maxProjectles, int maxCoins, int maxEnemies) 
	: MAX_COINS(maxCoins), MAX_ENEMIES(maxEnemies), MAX_PROJECTLES(maxProjectles) {
	this->spawner = new ObjectsSpawner(this, windowHeight, windowWidth, 1000, 300);
	Timer::getInstance(0.033).addListener(spawner);
	player = new Player(windowWidth / 2, windowHeight / 2, 0);
	armables.push_back(player);
	Weapon* startWeapon = new WeakWeapon(200, 5, 10);
	weapons.push_back(startWeapon);
	player->pickWeapon(startWeapon);
	engine = new SfmlEngine(windowHeight, windowWidth, windowName, antialiasing);
	engine->addListener(this);
};

