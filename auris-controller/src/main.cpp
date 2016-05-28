#include "generateArtefacts.h"

int main(){
	
	GenerateArtefacts *ga = new GenerateArtefacts();

	string ok;
	int op;

	while(1){
		cout << "Choose one what you whant to do:" << endl;
		cout << "[1] - Generate MIDI Melody" << endl;
		cout << "[2] - Generate Auris Stream" << endl;
		cout << "[3] - Play Auris Stream" << endl;
		cout << "[-1] - Out" << endl;
		
		cin.clear();
		cin >> op;

		if(op == 1){
			ga->generateMidiMelody();
		}
		
		if(op == 2){
			ga->generateAurisStream();
		}

		if(op == 3){
			ga->generatePlayAuris();
		}

		if(op == -1){
			break;
		}

		cout << "Press any key and ENTER" << endl;
		cin.clear();
		cin>>op;
		system("clear");
	}

	return 0;
}