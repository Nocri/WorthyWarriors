#pragma once
#include "Projectle.h"
class ShootingInterface
{
public:
	virtual void onShootMade(Projectle* projectle) = 0;
	virtual ~ShootingInterface(){}
};

