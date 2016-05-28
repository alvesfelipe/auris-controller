#ifndef _PLAYAURIS_H
#define _PLAYAURIS_H

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <wiringSerial.h>
#include <wiringPi.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <fstream>

using namespace std;
using std::stringstream;

class PlayAuris{

	public:
		PlayAuris();

		//This method send signal to Pins of Rasberry Pi
		void sendSignal(int motor, int intensity, int duration, int id_pin);

		//This method read a Auris Stream file and send signal to Arduino from Raspberry Pi2
		bool playAurisMelody(string aurs_file);
		
		~PlayAuris();
};

#endif