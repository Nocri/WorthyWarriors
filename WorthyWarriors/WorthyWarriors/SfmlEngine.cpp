#include "SfmlEngine.h"

SfmlEngine::SfmlEngine(int windowWidth, int windowHeight, const char* windowName, int antialiasingLevel) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = antialiasingLevel;

	window = new sf::RenderWindow(sf::VideoMode(windowWidth, windowHeight), windowName, sf::Style::Default, settings);
};

bool SfmlEngine::isWindowOpen() {
	return window->isOpen();
};


void SfmlEngine::interceptUserInput() {
	sf::Event event;
	while (window->pollEvent(event))
	{
		for (ControlsInterface* listener : controlListeners) {
			if (event.type == sf::Event::Closed) {
				window->close();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				listener->onPlayerLeft();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			{
				listener->onPlayerUp();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			{
				listener->onPlayerDown();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				listener->onPlayerRight();
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				listener->onPlayerShoot();
			}
			int mouseX = sf::Mouse::getPosition(*window).x;
			int mouseY = sf::Mouse::getPosition(*window).y;
				listener->onPlayerTargetChange(mouseX, mouseY);
			
		}
	}
};
bool SfmlEngine::checkCollision(CollidableBox* collidable, CollidableBox* collidable2) {
	sf::FloatRect boundingBox, boundingBox2;
	boundingBox.left = collidable->positionX;
	boundingBox.top = collidable->positionY;
	boundingBox.height = collidable->height;
	boundingBox.width = collidable->width;

	boundingBox2.left = collidable2->positionX;
	boundingBox2.top = collidable2->positionY;
	boundingBox2.height = collidable2->height;
	boundingBox2.width = collidable2->width;

	return boundingBox.intersects(boundingBox2);
};

void SfmlEngine::drawShape(int shapeSize, int position_x, int position_y, ViewEngineColor color, int shapeEdges, int rotation) {
	sf::CircleShape shape(shapeSize, shapeEdges);
	shape.setPosition(position_x + shapeSize, position_y + shapeSize);
	shape.setOrigin(shapeSize, shapeSize);
	shape.setRotation(rotation);
	shape.setFillColor(sf::Color(color.red, color.green, color.blue, color.alpha));

	window->draw(shape);
};

void SfmlEngine::clearWindow() {
	window->clear();
};
void SfmlEngine::render() {
	window->display();
};

SfmlEngine::~SfmlEngine()
{
}
