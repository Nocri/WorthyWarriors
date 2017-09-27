#pragma once
#include "Weapon.h"
class WeakWeapon :
	public Weapon
{
	WeakWeapon();
public:
	WeakWeapon(int ammo, int firePower, int fireRate);
	~WeakWeapon();
	void draw(ViewEngine* engine);
	void changePosition(int x, int y);
};

