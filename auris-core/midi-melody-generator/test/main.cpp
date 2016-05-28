#include "midiMelody.h"

int main(){
	
	MidiMelody *md = new MidiMelody();

	cout << md->melodyGenerator("Mike_Oldfield", "/home/felipe/Downloads/MUSICS_TESTES_EMOTIV/MUSICS_TESTES_EMOTIV/CALMO_POSITIVO/Mike_Oldfield.mp3", "~/") << endl;

	delete md;
	return 0;
}