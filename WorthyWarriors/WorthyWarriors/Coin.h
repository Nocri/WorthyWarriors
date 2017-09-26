#pragma once
#include "CollidableView.h"
class Coin :
	public CollidableView
{
	int value;
	Coin();
public:
	Coin(int positionX, int positionY, int value);
	~Coin();
	void draw(ViewEngine* engine);
};

