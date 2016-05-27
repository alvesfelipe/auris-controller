#include "midiToNotes.h"

int main(){

	MidiToNotes *mtn = new MidiToNotes();
	
	char const* tmp_home = getenv("HOME");
	string home(tmp_home);

	cout << mtn->midi_notes("midi_notes", home + "/midiMelody.mid", home + "/") << endl;

	delete mtn;
	return 0;
}