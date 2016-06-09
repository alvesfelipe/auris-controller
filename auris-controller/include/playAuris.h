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
#include "sendsignalbeagle.h"

using namespace std;
using std::stringstream;

class PlayAuris{

	public:
		PlayAuris();

		//This method send signal to Pins of Rasberry Pi
		void sendSignalRasp(string information, int id_pin);

		//This method send signal to Pins of Beagle Bone Black
		void sendSignalBeagle(int id, int duration);

		//This method read a Auris Stream file and send signal to (op==0)Raspberry Pi2
		// or (op==1)BeagleBoneBlack
		bool playAurisMelody(string aurs_file, int op);
		
		~PlayAuris();
};

#endif