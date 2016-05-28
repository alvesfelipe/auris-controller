#ifndef _AURISSTREAM_H
#define _AURISSTREAM_H

#include "midiToNotes.h"
#include "motor.h"
#include "notes.h"
#include <fstream>

using namespace std;

class AurisStream{

	public:
		AurisStream();
		
		bool setMotorList(string config_path, string midi_notes, list<Motor *> *motor, Notes* nt);

		void printMotorList(list<Motor *> *motor);

		~AurisStream();	
};

#endif