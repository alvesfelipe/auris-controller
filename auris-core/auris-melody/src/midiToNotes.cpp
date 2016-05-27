#include "midiToNotes.h"

MidiToNotes::MidiToNotes(){}

string MidiToNotes::midi_notes(string out_name, string midi_path, string out_path){
	
	string returned, aux;

	string lib_path = "cd ./lib/midifile/bin && ";
	string exec = "./midi2notes " + midi_path + " > " + out_path + out_name + ".txt";

	if (!boost::filesystem::exists(midi_path)){
  		cout << "Can't find midi file!" << std::endl;
		return "ERROR";
	}

	//system call
	redi::ipstream in(lib_path + exec);   
	return "SUCCESS";
}


MidiToNotes::~MidiToNotes(){}