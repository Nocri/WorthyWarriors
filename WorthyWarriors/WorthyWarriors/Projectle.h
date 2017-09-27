#pragma once
#include "SelfMovingObject.h"
#include "CollidableView.h"
class Projectle :
	public SelfMovingObject, public CollidableView
{
	int power;
	int speed;

	Projectle();
public:
	Projectle(int positionX, int positionY, int rotation, int speed, int power);
	void move();
	void draw(ViewEngine* engine);
	~Projectle();
};

