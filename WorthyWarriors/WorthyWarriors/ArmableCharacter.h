#pragma once
#include "SelfMovingObject.h"
#include "Destroyable.h"
#include "Weapon.h"
class ArmableCharacter :
	public Destroyable
{
protected:
	ArmableCharacter() {};
	Weapon* weapon;
	bool isArmed_;
public:
	virtual ~ArmableCharacter() {};
	bool isArmed() { return isArmed_; };
	void pickWeapon(Weapon* newWeapon) {
		weapon = newWeapon;
		isArmed_ = true;
	}
	void throwWeapon() {
		isArmed_ = false;
	}
	void dragWeapon() {
		if (isArmed_) {
			float moveY = (height) * sin((float)(3.14 / 180) *  (rotationAngle));
			float moveX = (width) * cos((float)(3.14 / 180) * (rotationAngle));

			weapon->positionX = (positionY + height)- moveY;
			weapon->positionY = (positionX + width) + moveX;
			weapon->rotationAngle = rotationAngle;
		}
	}

	void aim(int target_x, int target_y) {
		rotationAngle = atan2(target_y - (positionY + height), target_x - (positionX + width));
		rotationAngle *= (180 / 3.14);
	}
};

