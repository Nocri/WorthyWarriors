#pragma once
#include "ArmableCharacter.h"
class Enemy :
	public ArmableCharacter
{
	const int ENEMY_SPEED = 3;
	Enemy();
public:
	Enemy(int position_x, int position_y);
	~Enemy();
	void draw(ViewEngine* engine);
	void follow(int target_x, int target_y) {
		aim(target_x, target_y);
		float moveY = ENEMY_SPEED * sin((float)(3.14 / 180) *  (rotationAngle));
		float moveX = ENEMY_SPEED * cos((float)(3.14 / 180) * (rotationAngle));
		positionY -= moveY;
		positionX -= moveX;
	}
};

