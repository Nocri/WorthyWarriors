#include "WeakWeapon.h"

WeakWeapon::WeakWeapon()
{
	height = 7;
	width = 7;
}


WeakWeapon::~WeakWeapon()
{
}

void WeakWeapon::draw(ViewEngine* engine) {
	engine->drawShape(height, positionX, positionY, ViewEngineColor(255, 0, 0, 255), 6, 0);
};

void WeakWeapon::changePosition(int x, int y) {
	positionX = x;
	positionY = y;
};
