#pragma once
#include "TimerInterface.h"
#include "Timer.h"
#include <iostream>
#include "SfmlEngine.h"
#include "GameView.h"
#include "Destroyable.h"
#include <vector>
#include "Player.h"
#include "Projectle.h"
#include "Coin.h"
#include "WeakWeapon.h"
#include "ControlsInterface.h"

class GameController :
	public TimerInterface, public ControlsInterface
{
	const int MAX_PROJECTLES;
	const int MAX_COINS;
	const int MAX_ENEMIES;

	const int PLAYER_MOVE = 2;

	ViewEngine* engine;

	Player* player;
	std::vector<GameView*> views;
	std::vector<Destroyable*> destroyables;
	std::vector<Projectle*> projectles;
	std::vector<Coin*> coins;
	std::vector<Weapon*> weapons;

	int points;

public:
	GameController(int windowHeight, int windowWidth,
		const char* windowName, int antialiasing, int maxProjectles, int maxCoins, int maxEnemies);
	~GameController();

	void refreshBoard() {
		engine->interceptUserInput();
		engine->clearWindow();

		player->draw(engine);
		player->dragWeapon();
		//ToDo export to method
		for (Weapon* weapon : weapons) {
			weapon->draw(engine);
		}

		engine->render();

		if (!engine->isWindowOpen()) {
			Timer::getInstance(0.033).stopTimer();
		}
	};

	virtual void onRefreshTriggered() {
		refreshBoard();
	};

private:
	GameController();

	void onPlayerUp() { player->positionY -= PLAYER_MOVE; };
	void onPlayerDown() { player->positionY += PLAYER_MOVE; };
	void onPlayerRight() { player->positionX += PLAYER_MOVE; };
	void onPlayerLeft() { player->positionX -= PLAYER_MOVE; };
	void onPlayerShoot() { std::cout << " shoot "; };
	void onPlayerTargetChange(int target_x, int target_y) { player->aim(target_x, target_y); };
	void onPlayerDropWeapon() { player->throwWeapon(); std::cout << "drop"; };
};

