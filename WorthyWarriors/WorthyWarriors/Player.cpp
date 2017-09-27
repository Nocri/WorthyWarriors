#include "Player.h"

Player::Player(int position_x, int position_y, int rotation)
{
	height = 50;
	width = 50;
	positionX = position_x;
	positionY = position_y;
	rotationAngle = rotation-90;
}

Player::~Player()
{
}

void Player::draw(ViewEngine* engine) {
	engine->drawShape(height, positionX, positionY, ViewEngineColor(0, 233, 0, 255), 4, rotationAngle);
};

