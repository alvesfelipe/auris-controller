#include "generateArtefacts.h"

int main(){
	
	GenerateArtefacts *ga = new GenerateArtefacts();

	string ok;
	int op;
	string ch;

	while(1){
		cout << "Choose what you want to do:" << endl;
		cout << "[1] - Generate MIDI Melody" << endl;
		cout << "[2] - Generate Auris Stream" << endl;
		cout << "[3] - Play Auris Stream" << endl;
		cout << "[0] - Out" << endl;
		
		cin.clear();
		cin >> op;

		if(op == 1){
			system("clear");
			ga->generateMidiMelody();
		}
		
		if(op == 2){
			system("clear");
			ga->generateAurisStream();
		}

		if(op == 3){
			system("clear");
			ga->generatePlayAuris();
		}

		if(op == 0){
			break;
		}

		cout << "Press any key and ENTER" << endl;
		cin>>ch;
		if(ch.compare("\n")){
			system("clear");
		}
	}

	return 0;
}