#include "midiMelody.h"

int main(){
	
	MidiMelody *md = new MidiMelody();

	cout << md->melodyGenerator("midiMelody", "~/Downloads/test.wav", "~/") << endl;

	delete md;
	return 0;
}