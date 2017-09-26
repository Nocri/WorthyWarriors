#pragma once
class ControlsInterface
{
public:
	virtual void onPlayerUp() = 0;
	virtual void onPlayerDown() = 0;
	virtual void onPlayerRight() = 0;
	virtual void onPlayerLeft() = 0;
	virtual void onPlayerShoot() = 0;
	virtual void onPlayerTargetChange(int target_x, int target_y) = 0;
	virtual void onPlayerDropWeapon() = 0;
	virtual ~ControlsInterface() = 0;
};

