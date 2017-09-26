#ifndef VIEWENGINE_H
#define VIEWENGINE_H

#include "GameView.h"
#include "CollidableBox.h"

class ViewEngine;

class CollidableView :
	public GameView
{
protected:
	CollidableView() {};
public:
	virtual ~CollidableView();
	bool checkCollision(ViewEngine* viewEngine, CollidableView* collidable);
};

#endif