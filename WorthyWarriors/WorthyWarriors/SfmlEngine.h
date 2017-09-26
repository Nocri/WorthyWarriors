#pragma once
#include "ViewEngine.h"
#include <SFML/Graphics.hpp>
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
	void checkCollision(CollidableView collidable, CollidableView collidable2);
	void drawShape(int shapeSize, int position_x, int position_y, ViewEngineColor color, int shapeEdges, int rotation);
	void clearWindow();
	void render();
};

