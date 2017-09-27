#include "Coin.h"

Coin::Coin(int positionX, int positionY, int value)
{
	this->positionX = positionX;
	this->positionY = positionY;
	this->height = value;
	this->width = value;
	this->value = value;
	this->color = ViewEngineColor(255, 255, 0, 255);
}

Coin::~Coin()
{
}

void Coin::draw(ViewEngine* engine) {
	engine->drawShape(this->height, positionX, positionY, color, 30, 0);
};
