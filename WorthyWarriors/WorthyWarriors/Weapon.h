#pragma once
#include "CollidableView.h"
class Weapon : public CollidableView
{
public:
	int ammo;
	int firePower;
	int fireRate;
public:
	Weapon(){}
	virtual ~Weapon(){}
	virtual void changePosition(int x, int y) = 0;
};

