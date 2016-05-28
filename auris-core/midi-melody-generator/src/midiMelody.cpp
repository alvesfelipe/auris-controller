#include "midiMelody.h"

MidiMelody::MidiMelody(){}

bool MidiMelody::melodyGenerator(string out_name, string audio_path, string out_path){
	
	string returned, aux;

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);

	cout << "Processing..." << endl;

	string lib_path = "cd " + home + "/MUSIC_DEAF/music_for_deaf/auris-core/midi-melody-generator/lib/audio_to_midi_melodia-master && ";
	string exec = "python -W ignore audio_to_midi_melodia.py " + audio_path + " " + out_path + out_name +
	 			 ".mid" + " 60 --smooth 0.25 --minduration 0.1";

	//system call
	redi::ipstream in(lib_path + exec);

	while (in >> aux){
		returned = returned + aux;
	}

	if(returned.find("Conversioncomplete.") != std::string::npos){
		
		cout << "SUCCESS" << endl;		   
		return true;
	}

	return false;	
}

MidiMelody::~MidiMelody(){}