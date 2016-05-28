#include "midiMelody.h"

MidiMelody::MidiMelody(){}

string MidiMelody::melodyGenerator(string out_name, string audio_path, string out_path){
	
	string returned, aux;

	string lib_path = "cd ./lib/audio_to_midi_melodia-master && ";
	string exec = "python audio_to_midi_melodia.py " + audio_path + " " + out_path + out_name +
	 			 ".mid" + " 60 --smooth 0.25 --minduration 0.1";

	//system call
	redi::ipstream in(lib_path + exec);

	while (in >> aux){
		returned = returned + aux;
	}

	if(returned.find("Conversioncomplete.") != std::string::npos){
		
		cout << "SUCCESS" << endl;		   
		return out_path + out_name + ".mid";
	}

	return "ERROR";	
}

MidiMelody::~MidiMelody(){}