#include <SFML/Graphics.hpp>
#include "GameController.h"
#include "Timer.h"
#include "SfmlEngine.h"
#include "Coin.h"
#include "Projectle.h"
#include <iostream>
#include "WeakWeapon.h"
#include "Player.h"
#include <ctime>

int main()
{
	srand(time(NULL));

	GameController* controller = new GameController(800, 800, "Dzia³am", 16, 50, 50, 5);
	
	Timer::getInstance(0.3).addListener(controller);
	Timer::getInstance(0.3).startTimer();

	//Coin myCoin = Coin(50, 50, 5);
	//Projectle projectle = Projectle(200, 200, 90, 5, 5);
	//WeakWeapon weapon = WeakWeapon();
	//weapon.changePosition(280, 280);
	//Player player = Player(100, 100, 0);
	//player.pickWeapon(&weapon);
	//
	//player.aim(500, 500);
	//player.dragWeapon();

	//while (engine->isWindowOpen())
	//{
	//	system("pause");
	//	engine->interceptUserInput();
	//	engine->clearWindow();
	//	//engine->drawShape(200, 50, 50, ViewEngineColor(0, 255, 0, 255), 4, 45);
	//	//engine->drawShape(200, 30, 30, ViewEngineColor(255, 255, 0, 255), 4, 45);
	//	//engine->drawShape(200, 80, 80, ViewEngineColor(0, 255, 255, 255), 4, 45);
	//	//myCoin.draw(engine);
	//	projectle.draw(engine);
	//	projectle.move();
	//	player.draw(engine);
	//	weapon.draw(engine);
	//	engine->render();
	//}

	return 0;
}