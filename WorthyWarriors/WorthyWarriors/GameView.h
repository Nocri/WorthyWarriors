#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include "ViewEngineColor.h"
#include "ViewEngine.h"

class GameView
{
protected:
	GameView() {};
public:
	float positionX;
	float positionY;
	int width;
	int height;
	int rotationAngle = 0;
	bool isVisible = true;
	ViewEngineColor color;

	virtual ~GameView();

	virtual void draw(ViewEngine* viewEngine) = 0;
};

#endif