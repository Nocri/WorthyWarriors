#pragma once
#include <ctime>
#include <vector>
#include "TimerInterface.h"

class Timer
{
	double const REFRESH_INTERVAL;

	Timer(double refreshInterval);
	std::vector<TimerInterface*> listeners;

	std::clock_t startTime;
	std::clock_t lastRefreshTime;
	bool isActive = false;

public:
	static Timer &getInstance(double refreshInterval) {
		static Timer INSTANCE(refreshInterval);
		return INSTANCE;
	};
	void startTimer();
	void stopTimer();
	void addListener(TimerInterface* listener);
	void removeListener(TimerInterface* listener);
	~Timer();
};

