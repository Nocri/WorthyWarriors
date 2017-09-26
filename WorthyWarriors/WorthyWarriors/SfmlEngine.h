#ifndef SFMLENGINE_H
#define SFMLENGINE_H

#include <SFML/Graphics.hpp>
#include "ViewEngineColor.h"
#include "ViewEngine.h"
#include "CollidableBox.h"

class SfmlEngine :
	public ViewEngine
{
	sf::RenderWindow* window;

	SfmlEngine();
public:
	SfmlEngine(int windowHeight, int windowWidth, const char* windowName, int antialiasingLevel);

	~SfmlEngine();

	bool isWindowOpen();
	void interceptUserInput();
	bool checkCollision(CollidableBox* collidable, CollidableBox* collidable2);
	void drawShape(int shapeSize, int position_x, int position_y, ViewEngineColor color, int shapeEdges, int rotation);
	void clearWindow();
	void render();
};

#endif // !SFMLENGINE_H

