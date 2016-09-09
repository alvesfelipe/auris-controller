#ifndef _GENERATEARTEFACTS_H
#define _GENERATEARTEFACTS_H

#include "listFiles.h"
#include "midiMelody.h"
#include "aurisStream.h"
#include "midiToNotes.h"
#include "playAuris.h"

class GenerateArtefacts{

	public:
		void generateMidiMelody();
		
		void generateAurisStream();
		
		void generatePlayAuris();

};

#endif