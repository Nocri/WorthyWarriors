#pragma once
class TimerInterface
{
public:
	virtual void onRefreshTriggered() = 0;
	virtual ~TimerInterface() {};
};

