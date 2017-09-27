#pragma once
class SelfMovingObject
{
protected:
	SelfMovingObject() {};
public:
	virtual ~SelfMovingObject() {};
	virtual void move() = 0;
};

