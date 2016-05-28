#ifndef _MIDIMELODY_H
#define _MIDIMELODY_H

#include <iostream>
#include <string>
#include <pstream.h>

using namespace std;

class MidiMelody{

	private:

	public:	
		MidiMelody();
		
		string melodyGenerator(string out_name, string audio_path, string out_path);

		~MidiMelody();
};

#endif