#ifndef _TIMER_H
#define _TIMER_H

#include <iostream>
#include <ctime>

using namespace std;

class Timer{

	private:
		clock_t timerMillis;

	public:

		//start clock
		void startClock();
		//return elapsed time
		int timeClock();
		//Constructor
		Timer();
		//Destructor
		~Timer();
	
};

#endif