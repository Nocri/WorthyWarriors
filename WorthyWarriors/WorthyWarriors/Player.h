#pragma once
#include "ArmableCharacter.h"
class Player :
	public ArmableCharacter
{
	Player();
public:
	Player(int position_x, int position_y, int rotation);
	~Player();
	void draw(ViewEngine* engine);
};

