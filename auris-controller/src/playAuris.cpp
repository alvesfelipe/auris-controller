#include "playAuris.h"

PlayAuris::PlayAuris(){}

void PlayAuris::sendSignalRasp(string information, int id_pin){

	char send[100], d;
	memcpy(&send, information.c_str(), 100);

	cout << "send: " << send << endl;
	serialPuts(id_pin, send);

	do{
		d = serialGetchar(id_pin);
		printf("%c",d);
	}while(d != '\n');
}

void PlayAuris::sendSignalBeagle(int id, int duration){

}

bool PlayAuris::playAurisMelody(string aurs_file, int op){

	int fd, duration;
	string id, time_on, time_off, intensity;\
	SendSignalBeagle *ssb = new SendSignalBeagle();

	ssb->setGpioPins();
	//test open serial Rasp 
	/*if((fd = serialOpen("/dev/ttyAMA0",9600)) < 0){

		fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
		return false;
	}

	if(wiringPiSetup() == -1){
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return false;
	}
	*/
	//open Auris File
	ifstream auris_f(aurs_file.c_str());

    if(!auris_f.is_open()){
		auris_f.clear();
	    auris_f.close();

	    cout << "UNABLE TO OPEN AURIS FILE" << endl;

	    return false;
    }

    //read Auris File with melody of music
    while(auris_f >> id >> time_on >> time_off >> intensity){

    	duration = atoi(time_off.c_str()) - atoi(time_on.c_str());
    	
    	if(op == 0){
	    	sendSignalRasp(id, fd);
	    	sendSignalRasp(intensity, fd);
	    	sendSignalRasp(to_string(duration), fd);
    	}

    	if(op == 1){
    		ssb->setPinOn(ssb->getGpioPin(atoi(id.c_str())), duration);
    		ssb->setPinOff(ssb->getGpioPin(atoi(id.c_str())));
    	}
    	
    	cout << "ID: " << id << " Intensity: " << intensity << " Duration: " 
    	<< atoi(time_off.c_str()) - atoi(time_on.c_str()) << endl;
    }

    auris_f.close();

    delete ssb;
	return true;
}

PlayAuris::~PlayAuris(){}