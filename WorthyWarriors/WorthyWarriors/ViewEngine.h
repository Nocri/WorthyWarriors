#pragma once
#include <vector>
#include "ControlsInterface.h"
#include "CollidableView.h"
#include "ViewEngineColor.h"
class ViewEngine
{
	std::vector<ControlsInterface*> controlListeners;
public:
	void addListener(ControlsInterface* listener) {
		controlListeners.push_back(listener);
	}

	void removeListener(ControlsInterface* listener) {
		for (int i = 0; i < controlListeners.size(); i++) {
			if (controlListeners.at(i) == listener) {
				controlListeners.erase(controlListeners.begin() + i);
				break;
			}
		}
	}

	virtual void interceptUserInput() = 0;
	virtual void checkCollision(CollidableView collidable, CollidableView collidable2) = 0;
	virtual void drawShape(int size_x, int size_y, int position_x, int position_y, ViewEngineColor color, int shapeEdges, int rotation) = 0;
	virtual ~ViewEngine() = 0;

};

