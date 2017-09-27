#pragma once
#include "SelfMovingObject.h"
#include "Destroyable.h"
#include "Weapon.h"
#include "ShootingInterface.h"

class ArmableCharacter :
	public Destroyable
{
	const int PROJECTLE_SPEED = 5;
	int shootTries = 0;
protected:
	ArmableCharacter() {};
	Weapon* weapon;
	bool isArmed_;
public:
	virtual ~ArmableCharacter() {};
	bool isArmed() { return isArmed_; };

	void throwWeapon() {
		isArmed_ = false;
	}
	void dragWeapon() {
		if (isArmed_) {
			float moveY = (height) * sin((float)(3.14 / 180) *  (rotationAngle));
			float moveX = (width) * cos((float)(3.14 / 180) * (rotationAngle));

			weapon->positionX = (positionX )- moveX + height;
			weapon->positionY = (positionY) - moveY + width;
			weapon->rotationAngle = rotationAngle;
		}
	}

	void pickWeapon(Weapon* newWeapon) {
		weapon = newWeapon;
		isArmed_ = true;
		dragWeapon();
	}

	void aim(int target_x, int target_y) {

		const float PI = 3.14159265;

		float dx = (positionX + width) - target_x;
		float dy = (positionY + height) - target_y;

		float rotation = (atan2(dy, dx)) * 180 / PI;
		rotationAngle = rotation;
	}

	void shoot(ShootingInterface* listener) {
		if (isArmed_) {
			if (shootTries >= weapon->fireRate) {
				listener->onShootMade(new Projectle(weapon->positionX, weapon->positionY, rotationAngle, PROJECTLE_SPEED, weapon->firePower));
				shootTries = 0;
			}
			else
			{
				shootTries++;
			}
		}
	}
};

