#include "playAuris.h"

PlayAuris::PlayAuris(){}

void PlayAuris::sendSignal(int motor, int intensity, int duration, int id_pin){

	string destiny;

	stringstream a,b,c;
	a << motor;
	b << intensity;
	c << duration;

	destiny = a.str() + "&"+ b.str() + "&" + c.str() + "&";

	char send[100];

	memcpy(&send, destiny.c_str(), 100);

	cout << "send: " << send << endl;

	char d;

	serialPuts(id_pin, send);

	do{
		d = serialGetchar(id_pin);
		printf("%c",d);
	}while(d != '\n');
}

bool PlayAuris::playAurisMelody(string aurs_file){

	int fd;
	string id, time_on, time_off, intensity;

/*	if((fd = serialOpen("/dev/ttyAMA0",9600)) < 0){

		fprintf(stderr,"Unable to open serial device: %s\n",strerror(errno));
		return false;
	}

	if(wiringPiSetup() == -1){
		fprintf(stdout, "Unable to start wiringPi: %s\n", strerror(errno));
		return false;
	}*/

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
    	sendSignal(atoi(id.c_str()), atoi(intensity.c_str()), atoi(time_off.c_str()) - atoi(time_on.c_str()), fd);
    	/*cout << "ID: " << id << " Intensity: " << intensity << " Duration: " 
    	<< atoi(time_off.c_str()) - atoi(time_on.c_str()) << endl;*/
    }

    auris_f.close();

	return true;
}

PlayAuris::~PlayAuris(){}