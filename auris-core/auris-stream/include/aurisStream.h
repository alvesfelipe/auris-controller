#ifndef _AURISSTREAM_H
#define _AURISSTREAM_H

#include "midiToNotes.h"
#include "motor.h"
#include "notes.h"
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class AurisStream{

	public:
		AurisStream();

		list<Motor *> allRequisitions;
		vector<string> notesContent;
		
		bool setMotorList(string config_path, string midi_notes, int id_option);

		bool streamAurisGenerate(string out_name, string config_path, string midi_notes, 
                                 int id_option, string out_path);

		void setDefaultIds();

		void printMotorList(list<Motor *> *motor);

		void printMusicNotes();

		~AurisStream();	
};

#endif