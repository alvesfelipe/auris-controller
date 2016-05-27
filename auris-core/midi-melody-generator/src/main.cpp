#include "midiMelody.h"

int main(){
	
	MidiMelody *md = new MidiMelody();

	cout << md->melody_generator("midiMelody", "~/Downloads/test.wav", "~/") << endl;

	delete md;
	return 0;
}