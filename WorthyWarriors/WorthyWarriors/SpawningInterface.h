#pragma once
#include "Coin.h"
#include "Enemy.h"
class SpawningInterface
{
public:
	virtual void onCoinSpawned(Coin* coin) = 0;
	virtual void onEnemySpawned(Enemy* enemy) = 0;
	virtual ~SpawningInterface() {};
};

