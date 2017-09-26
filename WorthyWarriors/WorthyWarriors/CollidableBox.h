#pragma once

struct CollidableBox {
	int positionY, height, positionX, width;

	CollidableBox(int positionY, int height, int positionX, int width) : positionY(positionY), height(height), positionX(positionX), width(width) { }
};