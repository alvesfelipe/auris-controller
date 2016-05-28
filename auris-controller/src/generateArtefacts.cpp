#include "generateArtefacts.h"

void GenerateArtefacts::generateMidiMelody(){

	ListFiles *lf = new ListFiles();
	MidiMelody *md = new MidiMelody();

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);
	string choose;
	string ext(".mp3");

	vector<string> ret;

	cout << "Chose a file to generate MIDI Melody: " << endl;
	lf->listExtension(home + "/music_for_deaf_files/audios", ext, &ret);

	if(getline(cin, choose)){
		string name(ret.at(atoi(choose.c_str())));

		//remove extension of name
		std::string::size_type i = name.find(ext);
		if (i != std::string::npos)
	   		name.erase(i, ext.length());

		md->melodyGenerator(name, home + "/music_for_deaf_files/audios/" + name + ext,
		home + "/music_for_deaf_files/midis/");
	}

	ret.clear();

	delete lf;
	delete md;	
}

void GenerateArtefacts::generateAurisStream(){

	ListFiles *lf = new ListFiles();
	AurisStream *as = new AurisStream();
	MidiToNotes *mtn = new MidiToNotes();

	vector<string> ret;

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);
	string choose;
	string ext2(".mid"), ext3(".txt");

	cout << "Chose a file to generate Auris Stream: " << endl;
	lf->listExtension(home + "/music_for_deaf_files/midis", ext2, &ret);

	if(getline(cin, choose)){
		string name(ret.at(atoi(choose.c_str())));

		//remove extension of name
		std::string::size_type i = name.find(ext2);
		if (i != std::string::npos)
	   		name.erase(i, ext2.length());

	   	mtn->midiNotes(name, home + "/music_for_deaf_files/midis/" + name + ext2, "/tmp/");
		as->streamAurisGenerate(name, home + "/music_for_deaf/auris-core/auris-stream/file/configure.txt",
						   		 "/tmp/" + name + ext3, 0, home + "/music_for_deaf_files/auris_melodies/");
	}

	ret.clear();

	delete lf;
	delete as;
	delete mtn;
}

