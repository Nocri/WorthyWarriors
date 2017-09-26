#include "SfmlEngine.h"

SfmlEngine::SfmlEngine()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}
}

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
			if (event.type == sf::Event::KeyPressed) {
				if (event.key.code == sf::Keyboard::Up) {
					listener->onPlayerUp();
				}
				if (event.key.code == sf::Keyboard::Down) {
					listener->onPlayerDown();
				}
				if (event.key.code == sf::Keyboard::Left) {
					listener->onPlayerLeft();
				}
				if (event.key.code == sf::Keyboard::Right) {
					listener->onPlayerRight();
				}
				if (event.key.code == sf::Keyboard::F) {
					listener->onPlayerDropWeapon();
				}
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				listener->onPlayerShoot();
			}
			if (event.type == sf::Event::MouseMoved) {
				listener->onPlayerTargetChange(event.mouseMove.x, event.mouseMove.y);
			}
		}
	}
};
void SfmlEngine::checkCollision(CollidableView collidable, CollidableView collidable2) {
	//ToDo MK implement
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
