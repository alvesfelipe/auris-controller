#include "timer.h"

//Empty constructor
Timer::Timer(){}

//init funcion start Clock
void Timer::startClock(){ 

    this->timerMillis = clock();
}

//return elapsed time
int Timer::timeClock(){
    
    int result;
    result = (clock() - this->timerMillis) / (int)(CLOCKS_PER_SEC / 10500);
  
    return result; 
}

//Destructor
Timer::~Timer(){}