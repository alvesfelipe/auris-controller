#include "aurisStream.h"

AurisStream::AurisStream(){}

bool AurisStream::setMotorList(string config_path, string midi_notes, list<Motor *> *motor, Notes* nt){
	
	ifstream config_file(config_path.c_str());
	ifstream midi_file(midi_notes.c_str());

	string column1, column2;
	bool flag1=false, flag2=false;

	int on, off, midi;
	
	nt->setNotesMidi(&nt->notesMidi, &nt->notes);

	if(!config_file.is_open( )){
		config_file.clear();
        config_file.close();
    	
    	return false;
    }
    
    if(!midi_file.is_open( )){
		midi_file.clear();
        midi_file.close();

        return false;
    }

    //read midi file with melody of music
    while(midi_file >> midi >> on >> off){
    	for(map<string, vector<int> >::iterator it=nt->notesMidi.begin(); it!=nt->notesMidi.end(); ++it){
			for(vector<int>::iterator it2=it->second.begin(); it2!=it->second.end(); ++it2){
				if(*it2 == midi){
					motor->push_back(new Motor(midi, -1, "", it->first, on, off, -1));	
				}
			}
		}	
    }
    midi_file.close();

    //read configuration file
    while(config_file >> column1 >> column2){
    	//set id and type of motor by configure archive    	
    	if(flag1 == true && column2.compare("frequencyrange") != 0){	
    		for(list<Motor *>::iterator it=motor->begin(); it != motor->end(); ++it){
    			if((*it)->getNote().compare(column2) == 0){
    				//(*it)->setIdMotor(atoi(column1.c_str()));
    				(*it)->setTypeMotor("note");
    			}
    		}
    	}
    	//set vibration level of motor
    	if(flag2 == true){
    		for(list<Motor *>::iterator it=motor->begin(); it != motor->end(); ++it){
    			if((*it)->getNote().compare(column1) == 0)
    				(*it)->setVibrationLevel(atoi(column2.c_str()));
    		}
    	}
    	//check delimiters
    	if(column2.compare("note") == 0){
    		flag1 = true;
    	}
    	if(column2.compare("frequencyrange") == 0){
    		flag2 = true;
    		flag1 = false;
    	}
    	//end of check delimiters
    }
    config_file.close();

    return true;
}

void AurisStream::printMotorList(list<Motor *> *motor){
	for(list<Motor *>::iterator it=motor->begin(); it != motor->end(); ++it){
		cout << "Midi Note: " << (*it)->getMidiNote() << endl;
		cout << "Id Motor: " << (*it)->getIdMotor() << endl;
		cout << "Type Motor: " << (*it)->getTypeMotor() << endl;
		cout << "Time On: " <<(*it)->getTimeOn() << endl;
		cout << "Time Off:  " << (*it)->getTimeOff() << endl;
		cout << "Vibration Level: " << (*it)->getVibrationLevel() << endl;
		cout << "Note: " << (*it)->getNote() << endl;
		cout << "---------------------------" << endl;
	}
}

AurisStream::~AurisStream(){}