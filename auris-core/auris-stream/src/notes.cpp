#include "notes.h"

Notes::Notes(){}

void Notes::setNotesMidi(map<string, vector <int> > *notesMidi, vector<string> *notes){

	vector<int> auxVector;

	//create and set vector with notes
	notes->push_back("C");
	notes->push_back("C#");
	notes->push_back("D");
	notes->push_back("D#");
	notes->push_back("E");
	notes->push_back("F");
	notes->push_back("F#");
	notes->push_back("G");
	notes->push_back("G#");
	notes->push_back("A");
	notes->push_back("A#");
	notes->push_back("B");

	int aux;

	//populating map
	for(int j=0; j<8; j++){
		aux = j;

		for(int i=0; i<11; i++){
			auxVector.push_back(aux);
			aux += 12;
		}
		notesMidi->insert ( std::pair<string,vector<int> >(notes->at(j), auxVector) );
		auxVector.clear();
	}

	for(int j=8; j<12; j++){
		aux = j;
		
		for(int i=0; i<10; i++){
			auxVector.push_back(aux);
			aux += 12;
		}
		notesMidi->insert ( std::pair<string,vector<int> >(notes->at(j), auxVector) );
		auxVector.clear();
	}
}

Notes::~Notes(){}