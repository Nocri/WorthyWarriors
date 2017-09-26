#include "CollidableView.h"

CollidableView::~CollidableView()
{
}

bool CollidableView::checkCollision(ViewEngine* viewEngine, CollidableView* collidable) {
	return viewEngine->checkCollision(new CollidableBox(0, 0, 0, 0), new CollidableBox(0,0,0,0));
}