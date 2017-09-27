#include "Timer.h"
#include <iostream>	//ToDo delete logs on release
Timer::Timer(double refreshInterval) : REFRESH_INTERVAL(refreshInterval)
{
}

void Timer::addListener(TimerInterface* listener) {
	listeners.push_back(listener);
};

void Timer::removeListener(TimerInterface* listener) {
	for (int i = 0; i < listeners.size(); i++) {
		if (listeners.at(i) == listener) {
			listeners.erase(listeners.begin() + i);
			break;
		}
	}
};

void Timer::startTimer() {
	startTime = std::clock();
	//std::cout << "inside time = " << std::clock() << " ref inter = " << REFRESH_INTERVAL << "\n";
	isActive = true;
	while (isActive) {
		if (((std::clock() - lastRefreshTime) / (double)CLOCKS_PER_SEC) > REFRESH_INTERVAL) {
			//std::cout << "triggered inside\n";
			lastRefreshTime = std::clock();

			for (TimerInterface* listener : listeners) {
				(*listener).onRefreshTriggered();
			}
		}
	}
};
void Timer::stopTimer() {
	isActive = false;
};


Timer::~Timer()
{
	for (TimerInterface* listener : listeners) {
		delete listener;
	}
}
