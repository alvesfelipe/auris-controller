#include "generateArtefacts.h"

int main(int argc,char *argv[]){
	
	GenerateArtefacts *ga = new GenerateArtefacts();

	string ok;
	int op;
	string ch;

	if(argc == 2){
		PlayAuris *pl = new PlayAuris();
		char const* tmp_home = getenv("HOME");
		string home(tmp_home);
		string name(argv[1]);

		cout << "------------>" << name << endl;
		pl->playAurisMelody(home + "/MUSIC_DEAF/music_for_deaf_files/auris_melodies/" + name + ".txt", 1);

		delete pl;
		return 0;
	}

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