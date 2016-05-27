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
		
		string melody_generator(string out_name, string audio_path, string out_paht);

		~MidiMelody();
};

#endif