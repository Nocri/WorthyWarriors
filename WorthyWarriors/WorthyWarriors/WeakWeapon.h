#pragma once
#include "Weapon.h"
class WeakWeapon :
	public Weapon
{
public:
	WeakWeapon();
	~WeakWeapon();
	void draw(ViewEngine* engine);
	void changePosition(int x, int y);
};

