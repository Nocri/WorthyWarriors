#pragma once
#include "CollidableView.h"
class Destroyable :
	public CollidableView
{
protected:
	int hp;
public:

	Destroyable()
	{
	}

	virtual ~Destroyable()
	{}

	bool takeDamage(int damage) {
		hp -= damage;
		return hp <= 0;
	}
};

