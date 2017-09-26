#pragma once
class SelfMovingObject
{
	SelfMovingObject();
public:
	virtual ~SelfMovingObject() {};
	virtual void move() = 0;
};

