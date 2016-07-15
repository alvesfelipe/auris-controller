#ifndef _SENDSIGNALBEAGLE_H
#define _SENDSIGNALBEAGLE_H

#include <unistd.h>
#include <stdio.h>
#include <vector>

using namespace std;

class SendSignalBeagle{
	
	private:
		vector<int> gpioPins; 

	public:
		FILE *outPinFile;
		FILE *pinDirection;
		char gpioPinLow[3], gpioPinHigh[4], gpioPinDirection[2];

		//Setters
		void setGpioPins();

		//Getters 
		int getGpioPin(int pos);
		
		//Function for set on pin
		void setPinOn(int gpioPin, int timeBound);

		//Function for set off pin
		void setPinOff(int gpioPin);
		
		//Function for set all pins off
		void setAllPinsOff();

		//Constructor
		SendSignalBeagle(int gpioPin);
		//Empty constructor	
		SendSignalBeagle();
		//Destructor
		~SendSignalBeagle();	

		//Print
		void toString();	

};

#endif
