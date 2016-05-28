#include "midiToNotes.h"
#include "aurisStream.h"

int main(){

	MidiToNotes *mtn = new MidiToNotes();
	AurisStream *as = new AurisStream();
	Notes *nt = new Notes();

	list<Motor *> motor;
	
	char const* tmp_home = getenv("HOME");
	string home(tmp_home);

	cout << mtn->midiNotes("midi_notes", home + "/midiMelody.mid", home + "/") << endl;
	cout << as->setMotorList(home + "/music_for_deaf/auris-core/auris-stream/file/configure.txt", 
								home + "/midi_notes.txt", &motor, nt) << endl;

	as->printMotorList(&motor);

	delete nt;
	delete as;
	delete mtn;
	return 0;
}