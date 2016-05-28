#include "midiToNotes.h"

MidiToNotes::MidiToNotes(){}

string MidiToNotes::midiNotes(string out_name, string midi_path, string out_path){
	
	string returned, aux;

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);

	string lib_path = "cd " + home + "/music_for_deaf/auris-core/auris-stream/lib/midifile/bin && ";
	string exec = "./midi2notes " + midi_path + " > " + out_path + out_name + ".txt";

	if (!boost::filesystem::exists(midi_path)){
  		cout << "Can't find midi file!" << std::endl;
		return "ERROR";
	}

	//system call to midifile lib
	redi::ipstream in(lib_path + exec);   
	
	return out_path + out_name + ".txt";
}


MidiToNotes::~MidiToNotes(){}