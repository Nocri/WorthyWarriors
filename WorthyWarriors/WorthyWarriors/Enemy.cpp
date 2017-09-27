#include "Enemy.h"



Enemy::Enemy(int position_x, int position_y)
{
	this->positionX = positionX;
	this->positionY = position_y;
	this->width = 40;
	this->height = 40;
	this->color = ViewEngineColor(255, 0, 0, 255);
}


Enemy::~Enemy()
{
}

void Enemy::draw(ViewEngine* engine) {
	engine->drawShape(height, positionX, positionY, color, 6, 0);
};

