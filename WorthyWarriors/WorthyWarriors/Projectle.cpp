#include "Projectle.h"
#include <iostream>
Projectle::Projectle(int positionX, int positionY, int rotation, int speed, int power) {
	this->positionX = positionX;
	this->positionY = positionY;
	this->rotationAngle = rotation;
	this->speed = speed;
	this->power = power;
	this->height = power * 2;
	this->width = power * 2;
	this->color = ViewEngineColor(242, (125 - (power * 4)), 12, 180);
};
void Projectle::move() {
	float moveY = speed * sin((float)(3.14/180) *  (rotationAngle));
	float moveX = speed * cos((float)(3.14/180) * (rotationAngle));
		positionY -= moveY;
		positionX += moveX;	
};

void Projectle::draw(ViewEngine* engine) {
	engine->drawShape(height, positionX, positionY, color, 3, rotationAngle);
};


Projectle::~Projectle()
{
}
